#ifndef  POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "Miscellaneous/ContainerDynamic.hpp"
# include <string>

struct PolyHedra_MainData;

class SkinBase;

struct Point2D;

class Image;
class FileContext;
class LineCommand;

namespace YMT
{

class PolyHedra
{
	private:
		struct Corner;
		struct FaceCorner;
		struct Face;

	private:
		ContainerDynamic<Corner>	Corners;
		ContainerDynamic<Face>		Faces;
	public:
		FileContext *	File;
		SkinBase *		Skin;

	public:
		bool UseCornerNormals;

	private:
		PolyHedra();
	public:
		~PolyHedra();

	private:
		void Done();
		void Calc_Face_Normals();
		void Calc_Corn_Normals();

		void Insert_Corn(Corner corn);
		void Insert_Face3(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2);
		void Insert_Face4(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2, FaceCorner corn3);

	public:
		static PolyHedra * Cube(float scale = 1.0f);
		static PolyHedra * ConeC(int segments, float width = 1.0f, float height = 1.0f);
		static PolyHedra * FullTexture(Image * img, float scale = 1.0f);

	public:
		PolyHedra_MainData * ToMainData(int & count);
	public:
		std::string ToInfo() const;

	private:
		void Parse_Type(const LineCommand & cmd);
		void Parse_Format(const LineCommand & cmd);
		void Parse_Skin(const LineCommand & cmd);
		void Parse_c(const LineCommand & cmd);
		void Parse_f(const LineCommand & cmd);
		void Parse(const LineCommand & cmd);
	public:
		static PolyHedra * Load(const FileContext & file);
};
};

#endif