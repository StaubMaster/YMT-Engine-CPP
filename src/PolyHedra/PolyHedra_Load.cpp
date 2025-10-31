#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/PolyHedraData.hpp"

#include "PolyHedra/Skin/SkinBase.hpp"
#include "PolyHedra/Skin/Skin2DA.hpp"

#include "FileContext.hpp"
#include "FilePath.hpp"
#include "Parsing/LineCommand.hpp"

#include "DataStruct/Point3D.hpp"
#include "DataO.hpp"



/*
	Parse each line
	for errors / Debug stuff
		console out should be normalized
		also use errors for certain things
		like args number
		Unknown / Invalid
	Exceptions
		right now I use exceptions that create and store a String internally
		make a BaseException for that
		have FileExceptions and LineExceptions ?
			LineExceptions skip the line but continue in the File ?
			dont know of any case where that applies right now
			also could just give the BaseException an extra info ?
			so Bits that say what type of exception it is
*/



YMT::PolyHedra::PolyHedraParsingEnvironmentData::PolyHedraParsingEnvironmentData(const FileContext & file)
	: ParsingCommand::EnvironmentData(file),
	Data(NULL),
	CornerOffset(0),
	FaceOffset(0)
{ }
void YMT::PolyHedra::PolyHedraParsingEnvironmentData::Parse(const ParsingCommand & cmd)
{
	std::string name = cmd.Name();
	if (name == "")				{ /*std::cout << "empty\n";*/ }
	else if (name == "Type")	{ Parse_Type(cmd); }
	else if (name == "Format")	{ Parse_Format(cmd); }

	else if (name == "Skin")	{ Parse_Skin(cmd); }

	else if (name == "c")		{ Parse_Corner(cmd); }
	else if (name == "f")		{ Parse_Face(cmd); }

	else if (name == "p")		{ Parse_Corner(cmd); }
	else if (name == "d")		{ Parse_Face(cmd); }
	else if (name == "o")		{ Parse_Face(cmd); }

	else						{ std::cout << "unknown: " << cmd << "\n"; }
}
void YMT::PolyHedra::PolyHedraParsingEnvironmentData::Parse_Type(const ParsingCommand & cmd)
{
	if (!cmd.CheckCount(CountCheckEqual(1))) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckEqual(1)); }
	if (cmd.ToString(0) != "PolyHedra") { throw ParsingCommand::ExceptionInvalidArg(cmd, 0); }
}
void YMT::PolyHedra::PolyHedraParsingEnvironmentData::Parse_Format(const ParsingCommand & cmd)
{
	if (!cmd.CheckCount(CountCheckEqual(1))) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckEqual(1)); }
	if (cmd.ToString(0) != "PH_2025_10_27") { throw ParsingCommand::ExceptionInvalidArg(cmd, 0); }
}
void YMT::PolyHedra::PolyHedraParsingEnvironmentData::Parse_Skin(const ParsingCommand & cmd)
{
	if (!cmd.CheckCount(CountCheckEqual(1))) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckEqual(1)); }
	FileContext file(File.Directory() + "/" + cmd.ToString(0));
	if (Data -> Skin != NULL)
	{
		std::cout << cmd.Name() << ": " << "Skin already given" << "\n";
		std::cout << "Prev: Skin: " << Data -> Skin << "\n";
		delete Data -> Skin;
		Data -> Skin = NULL;
	}
	if (!file.Exists()) { std::cout << cmd.Name() << ": " << "Bad Skin File" << "\n"; return; }
	Data -> Skin = SkinBase::Load(file);
}

void YMT::PolyHedra::PolyHedraParsingEnvironmentData::Parse_Corner(const ParsingCommand & cmd)
{
	if (!cmd.CheckCount(CountCheckRange(3, 3))) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckRange(3, 3)); }
	Point3D c;
	c.X = cmd.ToFloat(0);
	c.Y = cmd.ToFloat(1);
	c.Z = cmd.ToFloat(2);
	//std::cout << "c: " << c << "\n";
	Data -> Insert_Corn(Corner(c));
}
void YMT::PolyHedra::PolyHedraParsingEnvironmentData::Parse_Face(const ParsingCommand & cmd)
{
	if (!cmd.CheckCount(CountCheckRange(3, 4))) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckRange(3, 4)); }

	unsigned int idx[cmd.Count()];
	for (unsigned int i = 0; i < cmd.Count(); i++)
	{
		idx[i] = cmd.ToUInt32(i);
		//std::cout << "[" << idx[i] << "]" << "\n";
	}

	if (cmd.Count() == 3)
	{
		Data -> Insert_Face3(FaceCorner(idx[0]), FaceCorner(idx[1]), FaceCorner(idx[2]));
	}
	else if (cmd.Count() == 4)
	{
		Data -> Insert_Face4(FaceCorner(idx[0]), FaceCorner(idx[1]), FaceCorner(idx[2]), FaceCorner(idx[3]));
	}
}



YMT::PolyHedra * YMT::PolyHedra::Load(const FileContext & file)
{
	std::cout << "\n";
	PolyHedraParsingEnvironmentData data(file);
	data.Data = new PolyHedra();
	ParsingCommand::SplitFileIntoCommands(data);
	if (data.Data != NULL)
	{
		data.Data -> Done();
	}
	else
	{
		data.Data = Cube();
	}
	std::cout << "Count: " << data.Data -> Corners.Count() << " : " << data.Data -> Faces.Count() << "\n";
	std::cout << "\n";
	return data.Data;
}
