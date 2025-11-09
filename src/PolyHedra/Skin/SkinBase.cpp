#include "PolyHedra/Skin/SkinBase.hpp"
#include "PolyHedra/Skin/Skin2DA.hpp"
#include "Graphics/Texture/Base.hpp"
#include "Format/Image.hpp"
#include "Parsing/LineCommand.hpp"



SkinBase::SkinBase() :
	Images(),
	File(NULL)
	{ }
SkinBase::~SkinBase()
{
	for (unsigned int i = 0; i < Images.Count(); i++)
	{
		delete Images[i];
	}
}





SkinBase::ParsingEnvironmentData::ParsingEnvironmentData(const FileContext & file) :
	ParsingCommand::EnvironmentData(file), Skin(NULL)
{ }
void SkinBase::ParsingEnvironmentData::Parse(const ParsingCommand & cmd)
{
	std::string name = cmd.Name();
	if (name== "")				{ /*std::cout << "Skin: " << "Empty\n";*/ }
	else if (name == "Type")	{ Parse_Type(cmd); }
	else if (name == "Format")	{ Parse_Format(cmd); }
	else if (Skin != NULL)		{ Skin -> Parse(cmd); }
	else						{ std::cout << "unknown: " << cmd << "\n"; }
}
void SkinBase::ParsingEnvironmentData::Parse_Type(const ParsingCommand & cmd)
{
	if (!cmd.CheckCount(CountCheckEqual(1))) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckEqual(1)); }
	if (cmd.ToString(0) == "Skin2DA")
	{
		Skin = new Skin2DA();
		Skin -> File = &File;
		return;
	}
	throw ParsingCommand::ExceptionInvalidArg(cmd, 0);
}
void SkinBase::ParsingEnvironmentData::Parse_Format(const ParsingCommand & cmd)
{
	if (!cmd.CheckCount(CountCheckEqual(1))) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckEqual(1)); }
	if (cmd.ToString(0) != "S_2025_10_27") { throw ParsingCommand::ExceptionInvalidArg(cmd, 0); }
}

SkinBase * SkinBase::Load(const FileContext & file)
{
	ParsingEnvironmentData data(file);
	ParsingCommand::SplitFileIntoCommands(data);
	data.Skin -> Done();
	return data.Skin;
}
