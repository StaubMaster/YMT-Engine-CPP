#ifndef  POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "Miscellaneous/ContainerDynamic.hpp"

# include "Parsing/ParsingCommand.hpp"

# include <string>
# include <exception>

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
		struct PolyHedraParsingEnvironmentData : public ParsingCommand::EnvironmentData
		{
			/*
				Line
				have ParsingCommand here instead of as Parameter
				have the full Line String here
			*/

			PolyHedra *		Data;
			unsigned int	CornerOffset;
			unsigned int	FaceOffset;

			PolyHedraParsingEnvironmentData(const FileContext & file);
			void Parse(const ParsingCommand & cmd) override;

			void Parse_Type(const ParsingCommand & cmd);
			void Parse_Format(const ParsingCommand & cmd);
			void Parse_Skin(const ParsingCommand & cmd);

			void Parse_Corner(const ParsingCommand & cmd);
			void Parse_Face(const ParsingCommand & cmd);

			void Parse_Offset(const ParsingCommand & cmd);
			void Parse_Belt(const ParsingCommand & cmd, bool direction, bool closure);
			void Parse_Band(const ParsingCommand & cmd, bool direction, bool closure);
			void Parse_Fan(const ParsingCommand & cmd, bool direction, bool closure);
			void Parse_Circle(const ParsingCommand & cmd, bool direction);
		};
	public:
		static PolyHedra * Load(const FileContext & file);
};
};

#endif