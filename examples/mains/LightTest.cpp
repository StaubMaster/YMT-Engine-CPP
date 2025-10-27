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

#include "Texture2DArray.hpp"
#include "PolyHedra.hpp"
#include "Window.hpp"

#include "DirectoryContext.hpp"
#include "FileContext.hpp"
#include "Format/Image.hpp"



DirectoryContext ImageDir("../media/Images");
DirectoryContext ShaderDir("../media/Shaders");



Window * win;

Trans3D	ViewTrans;
Depth	ViewDepth;

YMT::PolyHedra * Poly0;
Texture2DArray * Tex0;

PolyHedra_3D_Instances * PH_Instances;
int Entrys_Count;
EntryContainerDynamic<Simple3D_InstData>::Entry ** Entrys;

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
	int j_len = 16;
	int i_len = 16;
	Entrys = new EntryContainerDynamic<Simple3D_InstData>::Entry*[j_len];
	for (int j = 0; j < j_len; j++)
	{
		Entrys[j] = PH_Instances -> Alloc(i_len);
		//std::cout << "[" << j << "]" << (*Entrys[j]).Offset << "|" << (*Entrys[j]).Length << "\n";
		Point3D center(
			(std::rand() & 0x1F) - 0xF,
			(std::rand() & 0x1F) - 0xF,
			(std::rand() & 0x1F) - 0xF
		);
		Angle3D rot(
			(std::rand() & 0x1F) - 0xF,
			(std::rand() & 0x1F) - 0xF,
			(std::rand() & 0x1F) - 0xF
		);
		rot.CalcFore();
		for (int i = 0; i < i_len; i++)
		{
			(*Entrys[j])[i].Trans.Pos = center + Point3D(
				(std::rand() & 0x1F) - 0xF,
				(std::rand() & 0x1F) - 0xF,
				(std::rand() & 0x1F) - 0xF
			);
			(*Entrys[j])[i].Trans.Rot = rot;
		}
	}
	Entrys_Count = j_len;

	/*for (int j = 0; j < j_len; j++)
	{
		std::cout << "[" << j << "]" << (*Entrys[j]).Offset << "|" << (*Entrys[j]).Length << "\n";
	}*/

	{
		std::cout << "Instance Count: " << (PH_Instances -> Instances.Length) << "\n";
		//int MemSize = (PH_Instances -> Instances.Length) * sizeof(Simple3D_InstData);
		//std::cout << (MemSize / (1)) << " Bytes\n";
		//std::cout << (MemSize / (1 * 1000)) << "k Bytes\n";
		//std::cout << (MemSize / (1 * 1000 * 1000)) << "M Bytes\n";
	}
}



void Init()
{
	std::cout << "Init 0\n";

	InitShaders();

	//Poly0 = YMT::PolyHedra::FullTexture();
	Poly0 = YMT::PolyHedra::Cube();
	//Poly0 = YMT::PolyHedra::ConeC(12, 0.5f);

	Poly0 -> UseCornerNormals = false;
	Tex0 = new Texture2DArray(128, 128, 1, (FileContext[])
	{
		ImageDir.File("Orientation.png"),
		//ImageDir.File("GrayDeant.png"),
	});
	PH_Instances = new PolyHedra_3D_Instances(Poly0);

	AddInstances();

	std::cout << "Init 1\n";
}
void Free()
{
	std::cout << "Free 0\n";

	delete PH_Instances;
	delete [] Entrys;
	delete Tex0;
	delete Poly0;

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
	Light_Spot.Pos = ViewTrans.Pos;
	Light_Spot.Dir = ViewTrans.Rot.rotate(Point3D(0, 0, 1));

	PH_Shader -> Use();
	Uni_Light_Ambient -> PutData(Light_Ambient);
	Uni_Light_Solar -> PutData(Light_Solar);
	Uni_Light_Spot -> PutData(Light_Spot);

	(*Entrys[0])[0].Trans.Pos = Point3D(0, 0, 3);
	(*Entrys[0])[0].Trans.Rot = ViewTrans.Rot;
	(*Entrys[0])[0].Trans.Rot.CalcBack();

	Tex0 -> Bind();
	PH_Instances -> Update();
	PH_Instances -> Draw();
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

	ViewTrans = Trans3D(Point3D(0, 0, 0), Angle3D(0, 0, 0));
	ViewDepth.Factors = DepthFactors(0.1f, 100.0f);
	ViewDepth.Range = Range(0.8f, 1.0f);
	ViewDepth.Color = win -> DefaultColor;

	Light_Ambient = LightBase(0.25f, Color(1.0f, 0.0f, 0.0f));
	Light_Solar = LightSolar(0.1f, Color(0.0f, 0.0f, 1.0f), Point3D(+1, -3, +2).normalize());
	Light_Spot = LightSpot(1.0f, Color(0.0f, 1.0f, 0.0f), Point3D(0, 0, 0), Point3D(0, 0, 0), Range(0.8, 0.95));



	std::cout << "++++ Run\n";
	win -> Run();
	std::cout << "---- Run\n";



	delete win;



	glfwTerminate();
	std::cout << "main() return";
	return 0;
}
