#include "OBJ/MTL.hpp"

#include "FileManager/FileContext.hpp"
#include "FileManager/Parsing/LineCommand.hpp"

#include <string>



MTL::MTL()
{

}
MTL::~MTL()
{

}



void MTL::Parse_newmtl(const LineCommand & cmd)
{
	(void)cmd;
}
void MTL::Parse_Ns(const LineCommand & cmd)
{
	(void)cmd;
}
void MTL::Parse_Ka(const LineCommand & cmd)
{
	(void)cmd;
}
void MTL::Parse_Kd(const LineCommand & cmd)
{
	(void)cmd;
}
void MTL::Parse_Ks(const LineCommand & cmd)
{
	(void)cmd;
}
void MTL::Parse_Ni(const LineCommand & cmd)
{
	(void)cmd;
}
void MTL::Parse_d(const LineCommand & cmd)
{
	(void)cmd;
}
void MTL::Parse_illum(const LineCommand & cmd)
{
	(void)cmd;
}
void MTL::Parse(const LineCommand & cmd)
{
	if (cmd.Args.size() == 0)
	{
		return;
	}

	std::cout << "Material Command: " << cmd.Args[0] << "\n";

	const std::string & name = cmd.Args[0];
	if (name == "#")			{ }
	else
	{
		std::cout << "Unknown LineCommand: " << name << "\n";
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