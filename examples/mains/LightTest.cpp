#include <iostream>
#include "OpenGL/openGL.h"

#include "DataStruct/Full/PolyHedra_3D/PolyHedra_3D_Instances.hpp"

#include "Graphics/Shader/ShaderCode.hpp"
#include "Graphics/Shader/BaseShader.hpp"

#include "Graphics/Uniform/Data/SizeRatio2D.hpp"
#include "Graphics/Uniform/Data/Trans3D.hpp"
#include "Graphics/Uniform/Data/Depth.hpp"

#include "Graphics/Multiform/Data/SizeRatio2D.hpp"
#include "Graphics/Multiform/Data/Trans3D.hpp"
#include "Graphics/Multiform/Data/Depth.hpp"

#include "Graphics/Uniform/Data/LightBase.hpp"
#include "Graphics/Uniform/Data/LightSolar.hpp"
#include "Graphics/Uniform/Data/LightSpot.hpp"

#include "DataStruct/LightBase.hpp"
#include "DataStruct/LightSolar.hpp"
#include "DataStruct/LightSpot.hpp"

#include "DataO.hpp"

#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/Skin/SkinBase.hpp"
#include "PolyHedra/Skin/Skin2DA.hpp"

#include "Texture/TextureBase.hpp"
#include "Texture/Texture2DArray.hpp"
#include "Texture/TextureGen.hpp"

#include "Window.hpp"

#include "DirectoryContext.hpp"
#include "FileContext.hpp"
#include "Format/Image.hpp"



DirectoryContext ImageDir("../media/Images");
DirectoryContext ShaderDir("../media/Shaders");



Window * win;

Trans3D	ViewTrans;
Depth	ViewDepth;

ContainerDynamic<YMT::PolyHedra*> FancyPolyHedras;
ContainerDynamic<PolyHedra_3D_Instances*> FancyPolyHedraInstances;

YMT::PolyHedra * Poly0;
PolyHedra_3D_Instances * PH0_Instances;

ContainerDynamic<EntryContainerDynamic<Simple3D_InstData>::Entry*> Entrys;

BaseShader * PH_Shader;

Uniform::SizeRatio2D * Uni_ViewPortSizeRatio;
Uniform::Trans3D * Uni_View;
Uniform::Depth * Uni_Depth;

Multiform::SizeRatio2D * Multi_ViewPortSizeRatio;
Multiform::Trans3D * Multi_View;
Multiform::Depth * Multi_Depth;

LightBase Light_Ambient;
Uniform::LightBase * Uni_Light_Ambient;

LightSolar Light_Solar;
Uniform::LightSolar * Uni_Light_Solar;

LightSpot Light_Spot;
Uniform::LightSpot * Uni_Light_Spot;


Trans3D SpotLightTrans0;



void InitShaders()
{
	PH_Shader = new BaseShader((const ShaderCode []) {
		ShaderCode::FromFile(ShaderDir.File("PH_S3D.vert")),
		ShaderCode::FromFile(ShaderDir.File("PH_ULight.frag"))
	}, 2);

	Uni_ViewPortSizeRatio = new Uniform::SizeRatio2D("ViewPortSizeRatio", *PH_Shader);
	Uni_View = new Uniform::Trans3D("View", *PH_Shader);
	Uni_Depth = new Uniform::Depth("Depth", *PH_Shader);

	Multi_ViewPortSizeRatio = new Multiform::SizeRatio2D("ViewPortSizeRatio");
	Multi_View = new Multiform::Trans3D("View");
	Multi_Depth = new Multiform::Depth("Depth");

	BaseShader * shaders [] = {
		PH_Shader,
	};
	int shader_count = 1;

	Multi_ViewPortSizeRatio -> FindUniforms(shaders, shader_count);
	Multi_View -> FindUniforms(shaders, shader_count);
	Multi_Depth -> FindUniforms(shaders, shader_count);

	Multi_Depth -> ChangeData(ViewDepth);

	Uni_Light_Ambient = new Uniform::LightBase("Ambient", *PH_Shader);
	Uni_Light_Solar = new Uniform::LightSolar("Solar", *PH_Shader);
	Uni_Light_Spot = new Uniform::LightSpot("Spot", *PH_Shader);
}
void FreeShaders()
{
	delete PH_Shader;

	delete Uni_ViewPortSizeRatio;
	delete Uni_View;
	delete Uni_Depth;

	delete Multi_ViewPortSizeRatio;
	delete Multi_View;
	delete Multi_Depth;

	delete Uni_Light_Ambient;
	delete Uni_Light_Solar;
	delete Uni_Light_Spot;
}

void AddInstances()
{
	int Range_Size1 = 0x1FF;
	int Range_SizeH = 0x0FF;
	int j_len = 16;
	int i_len = 16;
	for (int j = 0; j < j_len; j++)
	{
		Entrys.Insert(PH0_Instances -> Alloc(i_len));
		//std::cout << "[" << j << "]" << (*Entrys[j]).Offset << "|" << (*Entrys[j]).Length << "\n";
		Point3D center(
			(std::rand() & Range_Size1) - Range_SizeH,
			(std::rand() & Range_Size1) - Range_SizeH,
			(std::rand() & Range_Size1) - Range_SizeH
		);
		Angle3D rot(
			(std::rand() & Range_Size1) - Range_SizeH,
			(std::rand() & Range_Size1) - Range_SizeH,
			(std::rand() & Range_Size1) - Range_SizeH
		);
		rot.CalcFore();
		for (int i = 0; i < i_len; i++)
		{
			(*Entrys[j])[i].Trans.Pos = center + Point3D(
				(std::rand() & Range_Size1) - Range_SizeH,
				(std::rand() & Range_Size1) - Range_SizeH,
				(std::rand() & Range_Size1) - Range_SizeH
			);
			(*Entrys[j])[i].Trans.Rot = rot;
		}
	}

	/*for (int j = 0; j < j_len; j++)
	{
		std::cout << "[" << j << "]" << (*Entrys[j]).Offset << "|" << (*Entrys[j]).Length << "\n";
	}*/

	{
		std::cout << "Instance Count: " << (PH0_Instances -> Instances.Length) << "\n";
		//int MemSize = (PH0_Instances -> Instances.Length) * sizeof(Simple3D_InstData);
		//std::cout << (MemSize / (1)) << " Bytes\n";
		//std::cout << (MemSize / (1 * 1000)) << "k Bytes\n";
		//std::cout << (MemSize / (1 * 1000 * 1000)) << "M Bytes\n";
	}
}


void FancyInsert(unsigned int ph_idx, Point3D pos, Angle3D rot)
{
	unsigned int idx = Entrys.Count();
	Entrys.Insert(FancyPolyHedraInstances[ph_idx] -> Alloc(1));
	(*Entrys[idx])[0].Trans = Trans3D(pos, rot);
	(*Entrys[idx])[0].Trans.Rot.CalcBack();
}
void Fancify()
{
	unsigned int idx_stage =				FancyPolyHedras.Insert(YMT::PolyHedra::Load(FileContext("../media/YMT/Light/Stage.polyhedra.ymt")));
	unsigned int idx_stage_light =			FancyPolyHedras.Insert(YMT::PolyHedra::Load(FileContext("../media/YMT/Light/Stage_Light.polyhedra.ymt")));
	unsigned int idx_stage_light_holder =	FancyPolyHedras.Insert(YMT::PolyHedra::Load(FileContext("../media/YMT/Light/Stage_Light_Holder.polyhedra.ymt")));
	unsigned int idx_truss =				FancyPolyHedras.Insert(YMT::PolyHedra::Load(FileContext("../media/YMT/Light/Truss_Square40cm_Len200cm.polyhedra.ymt")));
	unsigned int idx_truss_cube =			FancyPolyHedras.Insert(YMT::PolyHedra::Load(FileContext("../media/YMT/Light/Truss_Cube40cm.polyhedra.ymt")));

	for (unsigned int i = 0; i < FancyPolyHedras.Count(); i++)
	{
		FancyPolyHedraInstances.Insert(new PolyHedra_3D_Instances(FancyPolyHedras[i]));
	}

	FancyInsert(idx_stage, Point3D(0, 0, 0), Angle3D(0, 0, 0));

	FancyInsert(idx_truss, Point3D(-32, 10, -22), Angle3D(0, Angle3D::DegreeToRadian(90), 0));
	FancyInsert(idx_truss, Point3D(-32, 30, -22), Angle3D(0, Angle3D::DegreeToRadian(90), 0));
	FancyInsert(idx_truss_cube, Point3D(-32, 42, -22), Angle3D(0, 0, 0));

	FancyInsert(idx_truss, Point3D(+32, 10, -22), Angle3D(0, Angle3D::DegreeToRadian(90), 0));
	FancyInsert(idx_truss, Point3D(+32, 30, -22), Angle3D(0, Angle3D::DegreeToRadian(90), 0));
	FancyInsert(idx_truss_cube, Point3D(+32, 42, -22), Angle3D(0, 0, 0));

	FancyInsert(idx_truss, Point3D(-20, 42, -22), Angle3D(Angle3D::DegreeToRadian(90), 0, 0));
	FancyInsert(idx_truss, Point3D(  0, 42, -22), Angle3D(Angle3D::DegreeToRadian(90), 0, 0));
	FancyInsert(idx_truss, Point3D(+20, 42, -22), Angle3D(Angle3D::DegreeToRadian(90), 0, 0));

	FancyInsert(idx_truss, Point3D(-32, 42, -10), Angle3D(0, 0, 0));
	FancyInsert(idx_truss, Point3D(+32, 42, -10), Angle3D(0, 0, 0));
	FancyInsert(idx_truss, Point3D(-32, 42, +10), Angle3D(0, 0, 0));
	FancyInsert(idx_truss, Point3D(+32, 42, +10), Angle3D(0, 0, 0));

	FancyInsert(idx_truss, Point3D(-32, 10, +22), Angle3D(0, Angle3D::DegreeToRadian(90), 0));
	FancyInsert(idx_truss, Point3D(-32, 30, +22), Angle3D(0, Angle3D::DegreeToRadian(90), 0));
	FancyInsert(idx_truss_cube, Point3D(-32, 42, +22), Angle3D(0, 0, 0));

	FancyInsert(idx_truss, Point3D(+32, 10, +22), Angle3D(0, Angle3D::DegreeToRadian(90), 0));
	FancyInsert(idx_truss, Point3D(+32, 30, +22), Angle3D(0, Angle3D::DegreeToRadian(90), 0));
	FancyInsert(idx_truss_cube, Point3D(+32, 42, +22), Angle3D(0, 0, 0));

	FancyInsert(idx_truss, Point3D(-20, 42, +22), Angle3D(Angle3D::DegreeToRadian(90), 0, 0));
	FancyInsert(idx_truss, Point3D(  0, 42, +22), Angle3D(Angle3D::DegreeToRadian(90), 0, 0));
	FancyInsert(idx_truss, Point3D(+20, 42, +22), Angle3D(Angle3D::DegreeToRadian(90), 0, 0));

	FancyInsert(idx_stage_light, SpotLightTrans0.Pos, SpotLightTrans0.Rot);
	FancyInsert(idx_stage_light_holder, SpotLightTrans0.Pos, Angle3D(SpotLightTrans0.Rot.X, 0, 0));
}


void Init()
{
	std::cout << "Init 0\n";

	InitShaders();

	//Poly0 = YMT::PolyHedra::Load(FileContext("../media/YMT/Spline/Drehgestell_Achse.polyhedra.ymt"));
	//Poly0 = YMT::PolyHedra::Load(FileContext("../media/YMT/Spline/Drehgestell_Halter.polyhedra.ymt"));	//	Faces wrong way
	//Poly0 = YMT::PolyHedra::Load(FileContext("../media/YMT/Spline/Drehgestell_Rahmen.polyhedra.ymt"));	//	Faces Wrong way
	//Poly0 = YMT::PolyHedra::Load(FileContext("../media/YMT/Spline/Gleis_Seg.polyhedra.ymt"));				//	Faces Wrong way
	//Poly0 = YMT::PolyHedra::Load(FileContext("../media/YMT/Spline/Schienen_Seg.polyhedra.ymt"));			//	Faces Wrong way
	//Poly0 = YMT::PolyHedra::Load(FileContext("../media/YMT/Spline/Wagen_Flach.polyhedra.ymt"));			//	Faces Wrong way, some Geometry Wrong
	//Poly0 = YMT::PolyHedra::Load(FileContext("../media/YMT/Spline/Wagen_Tief.polyhedra.ymt"));			//	Faces Wrong way, some Geometry Wrong

	//Poly0 = YMT::PolyHedra::Load(FileContext("../media/YMT/test/cube.polyhedra.ymt"));
	Poly0 = YMT::PolyHedra::Cube();
	//Poly0 = YMT::PolyHedra::ConeC(12, 0.5f);
	//Poly0 = YMT::PolyHedra::FullTexture(TextureGen::Orientation2D());
	PH0_Instances = new PolyHedra_3D_Instances(Poly0);

	AddInstances();
	Fancify();

	std::cout << "Init 1\n";
}
void Free()
{
	std::cout << "Free 0\n";

	delete PH0_Instances;
	delete Poly0;
	for (unsigned int i = 0; i < FancyPolyHedraInstances.Count(); i++)
	{
		delete FancyPolyHedraInstances[i];
	}
	for (unsigned int i = 0; i < FancyPolyHedras.Count(); i++)
	{
		delete FancyPolyHedras[i];
	}

	FreeShaders();

	std::cout << "Free 1\n";
}

void Frame(double timeDelta)
{
	if (win -> IsMouseLocked())
	{
		ViewTrans.TransformFlatX(win -> MoveFromKeys(2.0f * timeDelta), win -> SpinFromCursor(0.2f * timeDelta));
	}
	ViewTrans.Rot.CalcBack();
	Multi_View -> ChangeData(ViewTrans);
	//Light_Spot.Pos = ViewTrans.Pos;
	//Light_Spot.Dir = ViewTrans.Rot.rotate(Point3D(0, 0, 1));

	PH_Shader -> Use();
	Uni_Light_Ambient -> PutData(Light_Ambient);
	Uni_Light_Solar -> PutData(Light_Solar);
	Uni_Light_Spot -> PutData(Light_Spot);

	(*Entrys[0])[0].Trans.Pos = Point3D(0, 0, 3);
	//(*Entrys[0])[0].Trans.Rot = ViewTrans.Rot;
	(*Entrys[0])[0].Trans.Rot = Angle3D();
	(*Entrys[0])[0].Trans.Rot.CalcBack();

	PH0_Instances -> Update();
	if (PH0_Instances -> Texture != NULL)
	{
		PH0_Instances -> Texture -> Bind();
	}
	PH0_Instances -> Draw();

	for (unsigned int i = 0; i < FancyPolyHedraInstances.Count(); i++)
	{
		FancyPolyHedraInstances[i] -> Update();
		if (FancyPolyHedraInstances[i] -> Texture != NULL)
		{
			FancyPolyHedraInstances[i] -> Texture -> Bind();
		}
		FancyPolyHedraInstances[i] -> Draw();
	}
}

void Resize(int w, int h)
{
	Multi_ViewPortSizeRatio -> ChangeData(SizeRatio2D(w, h));
}



int main()
{
	if (glfwInit() == 0)
	{
		std::cout << "GLFW Init Failed\n";
		return -1;
	}

	try
	{
		win = new Window(640, 480);
		win -> InitFunc = Init;
		win -> FrameFunc = Frame;
		win -> FreeFunc = Free;
		win -> ResizeFunc = Resize;
	}
	catch (std::exception & ex)
	{
		std::cout << "exception: " << ex.what() << "\n";
	}
	catch (const char * err)
	{
		std::cerr << "String Error: "<< err << "\n";
		glfwTerminate();
		return -1;
	}
	catch (...)
	{
		std::cerr << "Unknown Error" << "\n";
		glfwTerminate();
		return -1;
	}

	win -> DefaultColor = Color(0.25f, 0.0f, 0.0f);

	ViewTrans = Trans3D(Point3D(0, 20, -50), Angle3D(0, 0, 0));
	ViewDepth.Factors = DepthFactors(0.1f, 100.0f);
	ViewDepth.Range = Range(0.8f, 1.0f);
	ViewDepth.Color = win -> DefaultColor;

	//Light_Ambient = LightBase(0.25f, Color(1.0f, 0.0f, 0.0f));
	Light_Ambient = LightBase(0.05f, Color(1.0f, 1.0f, 1.0f));
	//Light_Solar = LightSolar(0.1f, Color(0.0f, 0.0f, 1.0f), Point3D(+1, -3, +2).normalize());
	Light_Solar = LightSolar(0.2f, Color(1.0f, 1.0f, 1.0f), Point3D(+1, -3, +2).normalize());
	//Light_Spot = LightSpot(1.0f, Color(0.0f, 1.0f, 0.0f), Point3D(0, 0, 0), Point3D(0, 0, 0), Range(0.8, 0.95));
	//Light_Spot = LightSpot(1.0f, Color(1.0f, 1.0f, 1.0f), Point3D(0, 0, 0), Point3D(0, 0, 0), Range(0.3, 0.95));

	SpotLightTrans0 = Trans3D(Point3D(+32, 30, -10), Angle3D(Angle3D::DegreeToRadian(-45), Angle3D::DegreeToRadian(-40), 0));
	SpotLightTrans0.Rot.CalcBack();
	Light_Spot = LightSpot(1.0f, Color(1.0f, 1.0f, 1.0f), SpotLightTrans0.Pos + SpotLightTrans0.Rot.rotate(Point3D(0, 0, +3)), SpotLightTrans0.Rot.rotate(Point3D(0, 0, 1)), Range(0.8, 0.95));



	std::cout << "++++ Run\n";
	win -> Run();
	std::cout << "---- Run\n";



	delete win;



	glfwTerminate();
	std::cout << "main() return";
	return 0;
}
