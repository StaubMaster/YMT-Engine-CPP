
#ifndef  OBJ_HPP
# define OBJ_HPP

# include "MTL.hpp"

# include "DataDec.hpp"

# include "Miscellaneous/ContainerDynamic.hpp"

# include <exception>



struct OBJ_MainData;

class LineCommand;
class FileContext;

//class MTL;

class OBJ
{
	private:
		class FaceCorner
		{
			public:
				unsigned int Position;
				unsigned int Texture;
				unsigned int Normal;
			public:
				FaceCorner();
		};
		class Face
		{
			public:
				FaceCorner Corner1;
				FaceCorner Corner2;
				FaceCorner Corner3;
				int MaterialIndex;
			public:
				Face();
		};

	private:
		std::string Path;

		ContainerDynamic<Point4D> Positions;
		ContainerDynamic<Point3D> Textures;
		ContainerDynamic<Point3D> Normals;
		ContainerDynamic<Face> Faces;

		MTL Materials;

	private:
		OBJ();
	public:
		~OBJ();

	public:
		Point4D Position_MainData(unsigned int idx);
		Point3D Texture_MainData(unsigned int idx, Point4D pos, SizeRatio2D scale, char sides);
		Point3D Normal_MainData(unsigned int idx, Point3D normal);
		OBJ_MainData * ToMainData(int & count, SizeRatio2D texScale);

	private:
		void Parse_v(const LineCommand & cmd);
		void Parse_vt(const LineCommand & cmd);
		void Parse_vn(const LineCommand & cmd);

		FaceCorner Parse_f_element(std::string text);
		void Parse_f(const LineCommand & cmd);

		void Parse_o(const LineCommand & cmd);
		void Parse_s(const LineCommand & cmd);

		void Parse_mtllib(const LineCommand & cmd);
		void Parse_usemtl(const LineCommand & cmd);

		void Parse(const LineCommand & cmd);

	public:
		static OBJ * Load(const FileContext & file);

	private:
		class Exception_InvalidString : public std::exception
		{
			private:
				std::string Line;
				std::string Text;
			public:
				Exception_InvalidString(std::string line, std::string text);
			public:
				const char * what() const noexcept;
		};
};

#endif
