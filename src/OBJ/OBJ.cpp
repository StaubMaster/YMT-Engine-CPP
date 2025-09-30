#include "OBJ/OBJ.hpp"
#include "OBJ/OBJ_Main.hpp"

#include "OBJ/MTL.hpp"

#include "FileManager/FileContext.hpp"
#include "FileManager/Parsing/LineCommand.hpp"

#include <string>



OBJ::FaceCorner::FaceCorner()
{
	Position = 0xFFFFFFFF;
	Texture = 0xFFFFFFFF;
	Normal = 0xFFFFFFFF;
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

}



Point3D OBJ::Position_MainData(unsigned int idx)
{
	Point4D val = Positions[idx];
	return Point3D(val.X, val.Y, val.Z);
}
Point2D OBJ::Texture_MainData(unsigned int idx)
{
	if (idx != 0xFFFFFFFF)
	{
		Point3D val = Textures[idx];
		return Point2D(val.X, val.Y);
	}
	else
	{
		return Point2D();
	}
}
Point3D OBJ::Normal_MainData(unsigned int idx, Point3D normal)
{
	if (idx != 0xFFFFFFFF)
	{
		return Normals[idx];
	}
	else
	{
		return normal;
	}
}
OBJ_MainData * OBJ::ToMainData(int & count)
{
	count = Faces.Count() * 3;
	OBJ_MainData * data = new OBJ_MainData[count];

	for (unsigned int f = 0; f < Faces.Count(); f++)
	{
		const Face & face = Faces[f];
		int c = f * 3;
		OBJ_MainData & c0 = data[c + 0];
		OBJ_MainData & c1 = data[c + 1];
		OBJ_MainData & c2 = data[c + 2];

		c0.Position = Position_MainData(face.Corner1.Position);
		c1.Position = Position_MainData(face.Corner2.Position);
		c2.Position = Position_MainData(face.Corner3.Position);

		c0.Texture = Texture_MainData(face.Corner1.Texture);
		c1.Texture = Texture_MainData(face.Corner2.Texture);
		c2.Texture = Texture_MainData(face.Corner3.Texture);

		Point3D normal = Point3D::cross(c1.Position - c0.Position, c2.Position - c0.Position).normalize();

		c0.Normal = Normal_MainData(face.Corner1.Normal, normal);
		c1.Normal = Normal_MainData(face.Corner2.Normal, normal);
		c2.Normal = Normal_MainData(face.Corner3.Normal, normal);
	}

	return data;
}



void OBJ::Parse_v(const LineCommand & cmd)
{
	Point4D p;
	if (cmd.Args.size() == 3)
	{
		p.X = std::stof(cmd.Args[0]);
		p.Y = std::stof(cmd.Args[1]);
		p.Z = std::stof(cmd.Args[2]);
		p.W = 1.0f;
	}
	else { std::cout << "Bad Num of Args\n"; }
	//std::cout << "v" << p << "\n";
	Positions.Insert(p);
}
void OBJ::Parse_vt(const LineCommand & cmd)
{
	Point3D p;
	if (cmd.Args.size() == 2)
	{
		p.X = std::stof(cmd.Args[0]);
		p.Y = std::stof(cmd.Args[1]);
		p.Z = 0.0f;
	}
	else { std::cout << "Bad Num of Args\n"; }
	//std::cout << "vt" << p << "\n";
	Textures.Insert(p);
}
void OBJ::Parse_vn(const LineCommand & cmd)
{
	Point3D p;
	if (cmd.Args.size() == 3)
	{
		p.X = std::stof(cmd.Args[0]);
		p.Y = std::stof(cmd.Args[1]);
		p.Z = std::stof(cmd.Args[2]);
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
		corn.Position = std::stoi(index_strings[0]) - 1;
	}
	if (index_strings.size() >= 2 && !index_strings[1].empty())
	{
		corn.Texture = std::stoi(index_strings[1]) - 1;
	}
	if (index_strings.size() >= 3 && !index_strings[2].empty())
	{
		corn.Normal = std::stoi(index_strings[2]) - 1;
	}

	return corn;
}
void OBJ::Parse_f(const LineCommand & cmd)
{
	if (cmd.Args.size() < 3) { std::cout << "Bad Num of Args\n"; }

	std::vector<FaceCorner> corns;
	for (unsigned int i = 0; i < cmd.Args.size(); i++)
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
	if (cmd.Args.size() < 1) { std::cout << "Bad Num of Args\n"; }
	MTL * mtl = MTL::Load(FileContext(Path + "/" + cmd.Args[0]));
	Materials.Insert(*mtl);
	delete mtl;
}
void OBJ::Parse_usemtl(const LineCommand & cmd)
{
	if (cmd.Args.size() < 1) { std::cout << "Bad Num of Args\n"; }
	Materials.Select(cmd.Args[0]);
}

void OBJ::Parse(const LineCommand & cmd)
{
	if (cmd.Name.empty())			{ }
	else if (cmd.Name == "#")		{ }
	else if (cmd.Name == "v")		{ Parse_v(cmd); }
	else if (cmd.Name == "vt")		{ Parse_vt(cmd); }
	else if (cmd.Name == "vn")		{ Parse_vn(cmd); }
	else if (cmd.Name == "f")		{ Parse_f(cmd); }
	else if (cmd.Name == "mtllib")	{ Parse_mtllib(cmd); }
	else if (cmd.Name == "usemtl")	{ Parse_usemtl(cmd); }
	else
	{
		std::cout << "Unknown OBJ LineCommand: '" << cmd.Name << "'\n";
	}
}



OBJ * OBJ::Load(const FileContext & file)
{
	if (file.Exists())
	{
		OBJ * obj = new OBJ();
		obj -> Path = file.Path();
		LineCommand::Split(file, *obj, &OBJ::Parse);
		std::cout << "Materials:\n";
		for (unsigned int i = 0; i < obj -> Materials.Materials.Count(); i++)
		{
			std::cout << obj -> Materials.Materials[i].ToString() << "\n";
		}
		return obj;
	}
	return NULL;
}
