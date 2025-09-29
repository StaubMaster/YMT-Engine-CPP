#include "OBJ/OBJ.hpp"
#include "OBJ/OBJ_Main.hpp"

#include "OBJ/MTL.hpp"

#include "FileManager/FileContext.hpp"
#include "FileManager/Parsing/LineCommand.hpp"

#include <string>



OBJ::FaceCorner::FaceCorner()
{
	Position = Point4D();
	Texture = Point3D();
	Normal = Point3D();
}
OBJ::Face::Face()
{
	Corner1 = FaceCorner();
	Corner2 = FaceCorner();
	Corner3 = FaceCorner();
}



OBJ::OBJ()
{

}
OBJ::~OBJ()
{
	for (unsigned int i = 0; i < Materials.Count(); i++)
	{
		delete Materials[i];
	}
}



Point3D Convert_4D_To_3D(Point4D p)
{
	return Point3D(p.X, p.Y, p.Z);
}
Point2D Convert_3D_To_2D(Point3D p)
{
	return Point2D(p.X, p.Y);
}

OBJ_MainData * OBJ::ToMainData(int & count)
{
	count = Faces.Count() * 3;
	OBJ_MainData * data = new OBJ_MainData[count];

	for (unsigned int f = 0; f < Faces.Count(); f++)
	{
		const Face & face = Faces[f];

		int c = f * 3;
		data[c + 0].Position = Convert_4D_To_3D(face.Corner1.Position);
		data[c + 1].Position = Convert_4D_To_3D(face.Corner2.Position);
		data[c + 2].Position = Convert_4D_To_3D(face.Corner3.Position);

		data[c + 0].Texture = Convert_3D_To_2D(face.Corner1.Texture);
		data[c + 1].Texture = Convert_3D_To_2D(face.Corner2.Texture);
		data[c + 2].Texture = Convert_3D_To_2D(face.Corner3.Texture);

		data[c + 0].Normal = face.Corner1.Normal;
		data[c + 1].Normal = face.Corner2.Normal;
		data[c + 2].Normal = face.Corner3.Normal;
	}

	return data;
}



void OBJ::Parse_v(const LineCommand & cmd)
{
	Point4D p;
	if (cmd.Args.size() == 4)
	{
		p.X = std::stof(cmd.Args[1]);
		p.Y = std::stof(cmd.Args[2]);
		p.Z = std::stof(cmd.Args[3]);
		p.W = 1.0f;
	}
	else { std::cout << "Bad Num of Args\n"; }
	//std::cout << "v" << p << "\n";
	Positions.Insert(p);
}
void OBJ::Parse_vt(const LineCommand & cmd)
{
	Point3D p;
	if (cmd.Args.size() == 3)
	{
		p.X = std::stof(cmd.Args[1]);
		p.Y = std::stof(cmd.Args[2]);
		p.Z = 0.0f;
	}
	else { std::cout << "Bad Num of Args\n"; }
	//std::cout << "vt" << p << "\n";
	Textures.Insert(p);
}
void OBJ::Parse_vn(const LineCommand & cmd)
{
	Point3D p;
	if (cmd.Args.size() == 4)
	{
		p.X = std::stof(cmd.Args[1]);
		p.Y = std::stof(cmd.Args[2]);
		p.Z = std::stof(cmd.Args[3]);
	}
	else { std::cout << "Bad Num of Args\n"; }
	//std::cout << "vn" << p << "\n";
	Textures.Insert(p);
}

OBJ::FaceCorner OBJ::Parse_f_element(std::string text)
{
	std::vector<std::string> index_strings;
	{
		std::string index_string;
		std::stringstream stream(text);
		while (std::getline(stream, index_string, '/'))
		{
			index_strings.push_back(index_string);
		}
	}

	FaceCorner corn;
	if (index_strings.size() >= 1)
	{
		int idx = std::stoi(index_strings[0]) - 1;
		corn.Position = Positions[idx];
	}
	if (index_strings.size() >= 2 && index_strings[1].empty())
	{
		int idx = std::stoi(index_strings[0]) - 1;
		corn.Texture = Textures[idx];
	}
	if (index_strings.size() >= 3 && index_strings[2].empty())
	{
		int idx = std::stoi(index_strings[0]) - 1;
		corn.Normal = Normals[idx];
	}
	return corn;
}
void OBJ::Parse_f(const LineCommand & cmd)
{
	if (cmd.Args.size() < 4) { std::cout << "Bad Num of Args\n"; }
	std::vector<FaceCorner> corns;
	for (unsigned int i = 1; i < cmd.Args.size(); i++)
	{
		corns.push_back(Parse_f_element(cmd.Args[i]));
	}

	if (corns.size() == 3)
	{
		Face face;
		face.Corner1 = corns[0];
		face.Corner2 = corns[1];
		face.Corner3 = corns[2];
		Faces.Insert(face);
	}
	else if (corns.size() == 4)
	{
		Face face;
		face.Corner1 = corns[0];
		face.Corner2 = corns[1];
		face.Corner3 = corns[2];
		Faces.Insert(face);
		face.Corner1 = corns[0];
		face.Corner2 = corns[2];
		face.Corner3 = corns[3];
		Faces.Insert(face);
	}
	else
	{
		std::cout << "Error: No Polygons with more then 4 sides.\n";
	}
}

void OBJ::Parse_mtllib(const LineCommand & cmd)
{
	if (cmd.Args.size() < 2) { std::cout << "Bad Num of Args\n"; }
	MTL * mtl = MTL::Load(FileContext(Path + "/" + cmd.Args[1]));
	Materials.Insert(mtl);
}

void OBJ::Parse(const LineCommand & cmd)
{
	if (cmd.Args.size() == 0)
	{
		return;
	}

	const std::string & name = cmd.Args[0];
	if (name == "#")			{ }
	else if (name == "v")		{ Parse_v(cmd); }
	else if (name == "vt")		{ Parse_vt(cmd); }
	else if (name == "vn")		{ Parse_vn(cmd); }
	else if (name == "f")		{ Parse_f(cmd); }
	else if (name == "mtllib")	{ Parse_mtllib(cmd); }
	else
	{
		std::cout << "Unknown LineCommand: " << name << "\n";
	}
}



OBJ * OBJ::Load(const FileContext & file)
{
	if (file.Exists())
	{
		OBJ * obj = new OBJ();
		obj -> Path = file.Path();
		LineCommand::Split(file, *obj, &OBJ::Parse);
		return obj;
	}
	return NULL;
}
