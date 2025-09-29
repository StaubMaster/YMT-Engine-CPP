
#ifndef  OBJ_HPP
# define OBJ_HPP

# include "Abstract.hpp"

# include "Miscellaneous/ContainerDynamic.hpp"

# include <exception>



struct OBJ_MainData;

class LineCommand;
class FileContext;

class MTL;

class OBJ
{
	private:
		class FaceCorner
		{
			public:
				Point4D Position;
				Point3D Texture;
				Point3D Normal;
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

		ContainerDynamic<MTL*> Materials;

	private:
		OBJ();
	public:
		~OBJ();

	public:
		OBJ_MainData * ToMainData(int & count);

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
