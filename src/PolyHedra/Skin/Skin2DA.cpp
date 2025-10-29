#include "PolyHedra/Skin/Skin2DA.hpp"
#include "PolyHedra/PolyHedra.hpp"

#include "Parsing/LineCommand.hpp"
#include "FileContext.hpp"

#include "DataStruct/Point2D.hpp"
#include "DataO.hpp"



Skin2DA::Skin2DA() :
	SkinGenericBase(),
	W(0), H(0)
{ }
Skin2DA::~Skin2DA()
{ }



TextureBase * Skin2DA::ToTexture() const
{
	return new Texture2DArray(W, H, Images.Count(), (const Image**)Images.ToPointer());
}





void Skin2DA::Parse_W(const LineCommand & cmd)
{
	if (cmd.Args.size() != 1) { std::cout << cmd.Name << ": " << "Bad Number of Args" << "\n"; return; }
	W = std::stoul(cmd.Args[0]);
}
void Skin2DA::Parse_H(const LineCommand & cmd)
{
	if (cmd.Args.size() != 1) { std::cout << cmd.Name << ": " << "Bad Number of Args" << "\n"; return; }
	H = std::stoul(cmd.Args[0]);
}
void Skin2DA::Parse_File(const LineCommand & cmd)
{
	if (cmd.Args.size() != 1) { std::cout << cmd.Name << ": " << "Bad Number of Args" << "\n"; return; }
	FileContext file(File -> Directory() + "/" + cmd.Args[0]);
	std::string ext = file.Extension();
	std::cout << ext << "\n";
	if (ext == ".png" || ext == ".PNG")
	{
		Images.Insert(file.LoadImagePNG());
	}
	else
	{
		std::cout << cmd.Name << ": " << "Unknown Image Extension" << "\n";
	}
}
void Skin2DA::Parse_t(const LineCommand & cmd)
{
	size_t len = cmd.Args.size() / 2;
	if ((cmd.Args.size() % 2) != 0 || len < 3 || len > 4) { std::cout << cmd.Name << ": " << "Bad Number of Args" << "\n"; return; }
	Point2D t[len];
	for (size_t i = 0; i < len; i++)
	{
		t[i].X = std::stof(cmd.Args[i * 2 + 0]);
		t[i].Y = std::stof(cmd.Args[i * 2 + 1]);
		std::cout << t[i] << "\n";
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
void Skin2DA::Parse(const LineCommand & cmd)
{
	std::cout << "Skin: Object: \n";

	if (cmd.Name == "")	{ std::cout << "Skin: Object: " << "Empty\n"; }
	else if (cmd.Name == "W") { Parse_W(cmd); }
	else if (cmd.Name == "H") { Parse_H(cmd); }
	else if (cmd.Name == "File") { Parse_File(cmd); }
	else if (cmd.Name == "t") { Parse_t(cmd); }
	else { std::cout << "Skin: Object: " << "Unknown\n"; }
}
