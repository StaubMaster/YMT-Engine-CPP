#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/PolyHedraData.hpp"

#include "PolyHedra/Skin/SkinBase.hpp"
#include "PolyHedra/Skin/Skin2DA.hpp"
#include "Texture/TextureGen.hpp"

#include "FileContext.hpp"
#include "FilePath.hpp"
#include "Parsing/LineCommand.hpp"

#include "DataStruct/Point3D.hpp"
#include "DataStruct/Angle3D.hpp"
#include "DataStruct/AxisBox3D.hpp"
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

	else if (name == "v")		{ Parse_Offset(cmd); }
	else if (name == "circle")	{ Parse_CircleOLD(cmd); }
	else if (name == "belt0")	{ Parse_Belt(cmd, false, false); }
	else if (name == "belt1")	{ Parse_Belt(cmd, false, true); }
	else if (name == "fan0")	{ Parse_Fan(cmd, false, true); }
	else if (name == "fan1")	{ Parse_Fan(cmd, true, true); }

	else if (name == "circle>")	{ Parse_Circle(cmd, false); }
	else if (name == "circle<")	{ Parse_Circle(cmd, true); }

	else if (name == "belt>0")	{ Parse_Belt(cmd, false, false); }
	else if (name == "belt<0")	{ Parse_Belt(cmd, true, false); }
	else if (name == "belt>1")	{ Parse_Belt(cmd, false, true); }
	else if (name == "belt<1")	{ Parse_Belt(cmd, true, true); }

	else if (name == "fan>0")	{ Parse_Fan(cmd, false, false); }
	else if (name == "fan<0")	{ Parse_Fan(cmd, true, false); }
	else if (name == "fan>1")	{ Parse_Fan(cmd, false, true); }
	else if (name == "fan<1")	{ Parse_Fan(cmd, true, true); }

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
	//std::cout << cmd << "\n";
	//std::cout << "COff: " << CornerOffset << "\n";

	unsigned int idx[cmd.Count()];
	for (unsigned int i = 0; i < cmd.Count(); i++)
	{
		std::string idx_str = cmd.ToString(i);
		if (idx_str[0] == '+' || idx_str[0] == '-')
		{ idx[i] = CornerOffset + cmd.ToInt32(i); }
		else
		{ idx[i] = cmd.ToUInt32(i); }
		//std::cout << "[" << idx[i] << "]" << Data -> Corners[idx[i]].Position << "\n";
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

void YMT::PolyHedra::PolyHedraParsingEnvironmentData::Parse_Offset(const ParsingCommand & cmd)
{
	if (!cmd.CheckCount(CountCheckEqual(2))) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckEqual(2)); }

	{
		std::string corner = cmd.ToString(0);
		if (corner[0] == '+' || corner[0] == '-')
		{ CornerOffset += cmd.ToInt32(0); }
		else
		{ CornerOffset = cmd.ToUInt32(0); }
	}

	{
		std::string corner = cmd.ToString(1);
		if (corner[0] == '+' || corner[0] == '-')
		{ FaceOffset += cmd.ToInt32(1); }
		else
		{ FaceOffset = cmd.ToUInt32(1); }
	}
}
void YMT::PolyHedra::PolyHedraParsingEnvironmentData::Parse_Belt(const ParsingCommand & cmd, bool direction, bool closure)
{
	unsigned int len = cmd.Count() / 2;
	if (!cmd.CheckCount(CountCheckModulo(2, 0)) || len < 2) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckModulo(2, 0)); }

	unsigned int idx0[len];
	unsigned int idx1[len];
	for (unsigned int i = 0; i < len; i++)
	{
		unsigned int i0 = i;
		unsigned int i1 = i + len;

		std::string idx0_str = cmd.ToString(i0);
		if (idx0_str[0] == '+' || idx0_str[0] == '-')
		{ idx0[i] = CornerOffset + cmd.ToInt32(i0); }
		else
		{ idx0[i] = cmd.ToUInt32(i0); }

		std::string idx1_str = cmd.ToString(i1);
		if (idx1_str[0] == '+' || idx1_str[0] == '-')
		{ idx1[i] = CornerOffset + cmd.ToInt32(i1); }
		else
		{ idx1[i] = cmd.ToUInt32(i1); }
	}

	for (unsigned int i = 1; i < len; i++)
	{
		if (!direction)
		{
			//Data -> Insert_Face4(idx0[i - 1], idx0[i - 0], idx1[i - 1], idx1[i - 0]);
			Data -> Insert_Face3(idx0[i - 1], idx0[i - 0], idx1[i - 1]);
			Data -> Insert_Face3(idx1[i - 1], idx0[i - 0], idx1[i - 0]);
		}
		else
		{
			//Data -> Insert_Face4(idx1[i - 1], idx0[i - 0], idx1[i - 1], idx1[i - 0]);
			Data -> Insert_Face3(idx1[i - 1], idx0[i - 0], idx0[i - 1]);
			Data -> Insert_Face3(idx1[i - 0], idx0[i - 0], idx1[i - 1]);
		}
	}

	if (closure)
	{
		if (!direction)
		{
			Data -> Insert_Face3(idx0[len - 1], idx0[0], idx1[len - 1]);
			Data -> Insert_Face3(idx1[len - 1], idx0[0], idx1[0]);
		}
		else
		{
			Data -> Insert_Face3(idx0[0], idx0[len -1], idx1[len - 1]);
			Data -> Insert_Face3(idx0[0], idx1[len -1], idx1[0]);
		}
	}
}
void YMT::PolyHedra::PolyHedraParsingEnvironmentData::Parse_Band(const ParsingCommand & cmd, bool direction, bool closure)
{
	(void)cmd;
	(void)direction;
	(void)closure;
}
void YMT::PolyHedra::PolyHedraParsingEnvironmentData::Parse_Fan(const ParsingCommand & cmd, bool direction, bool closure)
{
	unsigned int len = cmd.Count() - 1;
	if (!cmd.CheckCount(CountCheckRange(2, 255))) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckRange(2, 255)); }

	unsigned int middle;
	{
		std::string idx0_str = cmd.ToString(0);
		if (idx0_str[0] == '+' || idx0_str[0] == '-')
		{ middle = CornerOffset + cmd.ToInt32(0); }
		else
		{ middle = cmd.ToUInt32(0); }
	}

	unsigned int blade[len];
	for (unsigned int i = 0; i < len; i++)
	{
		std::string idx1_str = cmd.ToString(i + 1);
		if (idx1_str[0] == '+' || idx1_str[0] == '-')
		{ blade[i] = CornerOffset + cmd.ToInt32(i + 1); }
		else
		{ blade[i] = cmd.ToUInt32(i + 1); }
	}

	for (unsigned int i = 1; i < len; i++)
	{
		if (!direction)
		{
			Data -> Insert_Face3(middle, blade[i - 1], blade[i - 0]);
		}
		else
		{
			Data -> Insert_Face3(middle, blade[i - 0], blade[i - 1]);
		}
	}

	if (closure)
	{
		if (!direction)
		{
			Data -> Insert_Face3(middle, blade[len - 1], blade[0]);
		}
		else
		{
			Data -> Insert_Face3(middle, blade[0], blade[len - 1]);
		}
	}
}
void YMT::PolyHedra::PolyHedraParsingEnvironmentData::Parse_CircleOLD(const ParsingCommand & cmd)
{
	if (!cmd.CheckCount(CountCheckEqual(10))) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckEqual(10)); }
	//std::cout << cmd << "\n";

	int step_num = cmd.ToInt32(0);
	int step_off = cmd.ToInt32(1);

	Point3D center(
		cmd.ToFloat(2),
		cmd.ToFloat(3),
		cmd.ToFloat(4)
	);
	float radius = cmd.ToFloat(5);

	Angle3D angle = Angle3D::FromPoint3D(Point3D(
		cmd.ToFloat(6),
		cmd.ToFloat(7),
		cmd.ToFloat(8)
	));
	float offset = Angle3D::DegreeToRadian(cmd.ToFloat(9));

	int step_abs = 0;
	if (step_num > 0) { step_abs = +step_num; offset += PI * 0; }
	if (step_num < 0) { step_abs = -step_num; offset += PI * 1; }

	Point3D rad_p(radius, 0, 0);
	for (int i = 0; i < step_abs; i++)
	{
		angle.Z = ((i + step_off) * (TAU / step_num)) + offset;
		angle.CalcBack();
		Point3D p;
		p = angle.rotate(rad_p);
		p = p + center;
		Data -> Insert_Corn(Corner(p));
		//std::cout << p << "\n";
	}
}
void YMT::PolyHedra::PolyHedraParsingEnvironmentData::Parse_Circle(const ParsingCommand & cmd, bool direction)
{
	if (!cmd.CheckCount(CountCheckEqual(11))) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckEqual(11)); }
	//std::cout << cmd << "\n";

	float step = (TAU / cmd.ToInt32(0));
	int step_num = cmd.ToInt32(1);
	int step_off = cmd.ToInt32(2);

	Point3D center(
		cmd.ToFloat(3),
		cmd.ToFloat(4),
		cmd.ToFloat(5)
	);
	Point3D radius(cmd.ToFloat(6), 0, 0);

	Angle3D angle = Angle3D::FromPoint3D(Point3D(
		cmd.ToFloat(7),
		cmd.ToFloat(8),
		cmd.ToFloat(9)
	));
	float offset = Angle3D::DegreeToRadian(cmd.ToFloat(10));

	for (int i = 0; i < step_num; i++)
	{
		if (!direction)
		{
			angle.Z = ((i + step_off) * step) + offset;
		}
		else
		{
			//angle.Z = ((i + step_off) * step) + offset;
		}
		angle.CalcBack();
		Point3D p;
		p = angle.rotate(radius) + center;
		Data -> Insert_Corn(Corner(p));
		//std::cout << p << "\n";
	}
}

YMT::PolyHedra * YMT::PolyHedra::Load(const FileContext & file)
{
	//std::cout << "\n";
	//std::cout << "Loading PolyHedra File " << file.Name() << " ...\n";
	PolyHedraParsingEnvironmentData data(file);
	data.Data = new PolyHedra();
	ParsingCommand::SplitFileIntoCommands(data);
	if (data.Data != NULL)
	{
		if (data.Data -> Skin == NULL)
		{
			Skin2DA * skin = new Skin2DA();
			skin -> W = 1;
			skin -> H = 1;
			skin -> Images.Insert(TextureGen::NoSkin());
			data.Data -> Skin = skin;
		}
		data.Data -> Done();
	}
	else
	{
		data.Data = Cube();
	}
	//std::cout << "Loading PolyHedra File " << file.Name() << " done\n";

	//std::cout << "Count:" << " V:" << data.Data -> Corners.Count() << "\n";
	//std::cout << "Count:" << " F:" << data.Data -> Faces.Count() << "\n";
	//AxisBox3D bound = data.Data -> CalcBound();
	//std::cout << "Bound:" << "Limit:" << bound << "\n";
	//std::cout << "Bound:" << "Size:" << bound.Size() << "\n";

	/*	Unit Converter
		Length:	to make Data more cohereent
		Area:	not sure where I would need this
		Volume:	might be interesting ?
		Angle:	Deg to Rad & Rad to Deg
		Time:	?
		once a base is made it shouldnt be very difficult to add new Units
	*/

	//std::cout << "\n";
	return data.Data;
}
