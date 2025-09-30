#include "OBJ/MTL.hpp"

#include "FileManager/FileContext.hpp"
#include "FileManager/Parsing/LineCommand.hpp"

#include <string>



MTL::Material::Material()
{

}
std::string MTL::Material::ToString()
{
	std::ostringstream os;
	os << "Name: " << Name;
	os << "\n  Ka: " << Ka;
	os << "\n  Kd: " << Kd;
	os << "\n  Ks: " << Ks;
	os << "\n  Ns: " << Ns;
	os << "\n  Ni: " << Ni;
	os << "\n  d: " << d;
	os << "\n  illum: " << illum;
	return os.str();
}



MTL::MTL()
{
	Index_Newest = 0xFFFFFFFF;
	Index_Selected = 0xFFFFFFFF;
}
MTL::~MTL()
{

}



MTL::Material * MTL::Newest()
{
	if (Index_Newest != 0xFFFFFFFF)
	{
		return &Materials[Index_Newest];
	}
	return NULL;
}
MTL::Material * MTL::Selected()
{
	if (Index_Selected != 0xFFFFFFFF)
	{
		return &Materials[Index_Selected];
	}
	return NULL;
}

void MTL::Insert(MTL & mtl)
{
	Materials.Insert(mtl.Materials.ToPointer(), mtl.Materials.Count());
}
void MTL::Select(std::string name)
{
	for (unsigned int i = 0; i < Materials.Count(); i++)
	{
		if (Materials[i].Name == name)
		{
			Index_Selected = i;
		}
	}
}



void MTL::Parse_newmtl(const LineCommand & cmd)
{
	Index_Newest = Materials.Count();
	Materials.Insert(Material());
	Newest() -> Name = cmd.Args[0];
}

void MTL::Parse_Ka(const LineCommand & cmd)
{
	Newest() -> Ka.R = std::stof(cmd.Args[0]);
	Newest() -> Ka.G = std::stof(cmd.Args[1]);
	Newest() -> Ka.B = std::stof(cmd.Args[2]);
}
void MTL::Parse_Kd(const LineCommand & cmd)
{
	Newest() -> Kd.R = std::stof(cmd.Args[0]);
	Newest() -> Kd.G = std::stof(cmd.Args[1]);
	Newest() -> Kd.B = std::stof(cmd.Args[2]);
}
void MTL::Parse_Ks(const LineCommand & cmd)
{
	Newest() -> Ks.R = std::stof(cmd.Args[0]);
	Newest() -> Ks.G = std::stof(cmd.Args[1]);
	Newest() -> Ks.B = std::stof(cmd.Args[2]);
}
void MTL::Parse_Ns(const LineCommand & cmd)
{
	Newest() -> Ns = std::stof(cmd.Args[0]);
}
void MTL::Parse_Ni(const LineCommand & cmd)
{
	Newest() -> Ni = std::stof(cmd.Args[0]);
}
void MTL::Parse_d(const LineCommand & cmd)
{
	Newest() -> d = std::stof(cmd.Args[0]);
}

void MTL::Parse_illum(const LineCommand & cmd)
{
	Newest() -> illum = std::stoi(cmd.Args[0]);
	std::cout << "illum: " << Newest() -> illum << "\n";
}

void MTL::Parse(const LineCommand & cmd)
{
	if (cmd.Name.empty())			{ }
	else if (cmd.Name == "#")		{ }
	else if (cmd.Name == "newmtl")	{ Parse_newmtl(cmd); }
	else if (cmd.Name == "Ka")		{ Parse_Ka(cmd); }
	else if (cmd.Name == "Kd")		{ Parse_Kd(cmd); }
	else if (cmd.Name == "Ks")		{ Parse_Ks(cmd); }
	else if (cmd.Name == "Ns")		{ Parse_Ns(cmd); }
	else if (cmd.Name == "Ni")		{ Parse_Ni(cmd); }
	else if (cmd.Name == "d")		{ Parse_d(cmd); }
	else if (cmd.Name == "illum")	{ Parse_illum(cmd); }
	else
	{
		std::cout << "Unknown MTL LineCommand: '" << cmd.Name << "'\n";
	}
}



MTL * MTL::Load(const FileContext & file)
{
	std::cout << "'" << file.FilePath << "'" << " exists ? " << file.Exists() << "\n";
	if (file.Exists())
	{
		MTL * mtl = new MTL();
		LineCommand::Split(file, *mtl, &MTL::Parse);
		return mtl;
	}
	return NULL;
}