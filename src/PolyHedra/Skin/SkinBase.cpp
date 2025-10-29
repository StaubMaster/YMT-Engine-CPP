#include "PolyHedra/Skin/SkinBase.hpp"
#include "PolyHedra/Skin/Skin2DA.hpp"
#include "Texture/TextureBase.hpp"
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
	File(file), Skin(NULL)
{ }
void SkinBase::ParsingEnvironmentData::Parse_Type(const LineCommand & cmd)
{
	if (cmd.Args.size() != 1) { std::cout << cmd.Name << ": " << "Bad Number of Args" << "\n"; return; }
	if (cmd.Args[0] != "Skin2DA") { std::cout << cmd.Name << ": " << "Bad Type " << "\n"; return; }
	Skin = new Skin2DA();
	Skin -> File = &File;
}
void SkinBase::ParsingEnvironmentData::Parse_Format(const LineCommand & cmd)
{
	if (cmd.Args.size() != 1) { std::cout << cmd.Name << ": " << "Bad Number of Args" << "\n"; return; }
	if (cmd.Args[0] != "S_2025_10_27") { std::cout << cmd.Name << ": " << "Bad Type " << "\n"; return; }
	std::cout << cmd.Name << ": " << "Good\n";
	(void)cmd;
}
void SkinBase::ParsingEnvironmentData::Parse(const LineCommand & cmd)
{
	std::cout << "Skin: " << "Command: '" << cmd.Name << "'";
	std::cout << " ";
	std::cout << "[" << cmd.Args.size() << "]";
	for (size_t i = 0; i < cmd.Args.size(); i++)
	{
		std::cout << " ";
		std::cout << "<" << cmd.Args[i] << ">";
	}
	std::cout << "\n";

	if (cmd.Name == "")	{ std::cout << "Skin: " << "Empty\n"; }
	else if (cmd.Name == "Type") { Parse_Type(cmd); }
	else if (cmd.Name == "Format") { Parse_Format(cmd); }
	else if (Skin != NULL) { Skin -> Parse(cmd); }
	else { std::cout << "Skin: " << "Unknown\n"; }
}
SkinBase * SkinBase::Load(const FileContext & file)
{
	ParsingEnvironmentData data(file);
	LineCommand::Split(file, data, &SkinBase::ParsingEnvironmentData::Parse);
	data.Skin -> Done();
	return data.Skin;
}
