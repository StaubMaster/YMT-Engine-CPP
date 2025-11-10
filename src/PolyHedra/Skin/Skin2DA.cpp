#include "PolyHedra/Skin/Skin2DA.hpp"
#include "PolyHedra/PolyHedra.hpp"

#include "Graphics/Texture/2DArray.hpp"

#include "Parsing/LineCommand.hpp"
#include "FileContext.hpp"

#include "DataStruct/Point2D.hpp"
#include "DataShow.hpp"



Skin2DA::Skin2DA() :
	SkinGenericBase(),
	W(0), H(0)
{ }
Skin2DA::~Skin2DA()
{ }



Texture::Base * Skin2DA::ToTexture() const
{
	return new Texture::T2DArray(W, H, Images.Count(), (const Image**)Images.ToPointer());
}





void Skin2DA::Parse(const ParsingCommand & cmd)
{
	std::string name = cmd.Name();
	if (name == "")				{ /*std::cout << "Skin: Object: " << "Empty\n";*/ }
	else if (name == "W")		{ Parse_W(cmd); }
	else if (name == "H")		{ Parse_H(cmd); }
	else if (name == "File")	{ Parse_File(cmd); }
	else if (name == "t")		{ Parse_t(cmd); }
	else						{ std::cout << "unknown: " << cmd << "\n"; }
}
void Skin2DA::Parse_W(const ParsingCommand & cmd)
{
	if (!cmd.CheckCount(CountCheckEqual(1))) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckEqual(1)); }
	W = cmd.ToUInt32(0);
}
void Skin2DA::Parse_H(const ParsingCommand & cmd)
{
	if (!cmd.CheckCount(CountCheckEqual(1))) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckEqual(1)); }
	H = cmd.ToUInt32(0);
}
void Skin2DA::Parse_File(const ParsingCommand & cmd)
{
	if (!cmd.CheckCount(CountCheckEqual(1))) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckEqual(1)); }
	FileContext file(File -> Directory() + "/" + cmd.ToString(0));
	std::string ext = file.Extension();
	std::cout << ext << "\n";
	if (ext == ".png" || ext == ".PNG")
	{
		Images.Insert(file.LoadImagePNG());
	}
	else
	{
		std::cout << file.Path.ToString() << ": " << "Unknown Image Extension" << "\n";
	}
}
void Skin2DA::Parse_t(const ParsingCommand & cmd)
{
	unsigned int len = cmd.Count() / 2;
	if (!cmd.CheckCount(CountCheckModulo(2, 0)) || len < 3 || len > 4) { throw ParsingCommand::ExceptionInvalidCount(cmd, CountCheckModulo(2, 0)); }
	Point2D t[len];
	for (size_t i = 0; i < len; i++)
	{
		t[i].X = cmd.ToFloat(i * 2 + 0);
		t[i].Y = cmd.ToFloat(i * 2 + 1);
		//std::cout << t[i] << "\n";
	}

	if (len == 3)
	{
		Insert_Face3(Skin2DFaceCorner(t[0]), Skin2DFaceCorner(t[1]), Skin2DFaceCorner(t[2]));
	}
	else if (len == 4)
	{
		Insert_Face4(Skin2DFaceCorner(t[0]), Skin2DFaceCorner(t[1]), Skin2DFaceCorner(t[2]), Skin2DFaceCorner(t[3]));
	}
}
