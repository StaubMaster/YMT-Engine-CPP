#include "PolyHedra/PolyHedra.hpp"
#include "FileContext.hpp"
#include "Parsing/LineCommand.hpp"



void YMT::PolyHedra::Parse_Type(const LineCommand & cmd)
{
	if (cmd.Args.size() != 1) { std::cout << cmd.Name << ": " << "Bad Number of Args" << "\n"; return; }
	if (cmd.Args[0] != "PolyHedra") { std::cout << cmd.Name << ": " << "Bad Type " << "\n"; return; }
	std::cout << cmd.Name << ": " << "Good\n";
}
void YMT::PolyHedra::Parse_Format(const LineCommand & cmd)
{
	if (cmd.Args.size() != 1) { std::cout << cmd.Name << ": " << "Bad Number of Args" << "\n"; return; }
	if (cmd.Args[0] != "PH_2025_10_27") { std::cout << cmd.Name << ": " << "Bad Type " << "\n"; return; }
	std::cout << cmd.Name << ": " << "Good\n";
	(void)cmd;
}
void YMT::PolyHedra::Parse_Skin(const LineCommand & cmd)
{
	if (cmd.Args.size() != 1) { std::cout << cmd.Name << ": " << "Bad Number of Args" << "\n"; return; }
	FileContext skin_file(cmd.Args[0]);
	if (skin_file.Exists()) { std::cout << cmd.Name << ": " << "Bad Skin File" << "\n"; return; }
	std::cout << cmd.Name << ": " << "Good\n";
}
void YMT::PolyHedra::Parse_c(const LineCommand & cmd)
{
	(void)cmd;
}
void YMT::PolyHedra::Parse_f(const LineCommand & cmd)
{
	(void)cmd;
}
void YMT::PolyHedra::Parse(const LineCommand & cmd)
{
	std::cout << "Command: '" << cmd.Name << "'";
	std::cout << " ";
	std::cout << "[" << cmd.Args.size() << "]";
	for (size_t i = 0; i < cmd.Args.size(); i++)
	{
		std::cout << " ";
		std::cout << "<" << cmd.Args[i] << ">";
	}
	std::cout << "\n";

	if (cmd.Name == "")				{ std::cout << "Empty\n"; }
	else if (cmd.Name == "Type")	{ Parse_Type(cmd); }
	else if (cmd.Name == "Format")	{ Parse_Format(cmd); }
	else if (cmd.Name == "Skin")	{ Parse_Skin(cmd); }
	else if (cmd.Name == "c")		{ Parse_c(cmd); }
	else if (cmd.Name == "f")		{ Parse_f(cmd); }
	else { std::cout << "Unknown\n"; }
}

YMT::PolyHedra * YMT::PolyHedra::Load(const FileContext & file)
{
	std::cout << "\n";
	PolyHedra * temp = new PolyHedra();
	LineCommand::Split(file, *temp, &Parse);
	std::cout << "\n";
	return temp;
}
