
#ifndef  OBJ_HPP
# define OBJ_HPP

# include "Abstract.hpp"

# include "Miscellaneous/ContainerDynamic.hpp"

# include "FileManager/FileContext.hpp"

# include <exception>

class OBJ
{
	private:
		class Command
		{
			public:
				std::string Name;
				std::string * Args;
				unsigned int Num;
			public:
				Command(std::string text);
				~Command();
		};

		class Face
		{
		};

	private:
		ContainerDynamic<Point4D> Positions;
		ContainerDynamic<Point3D> Textures;
		ContainerDynamic<Point3D> Normals;

	private:
		OBJ();
	public:
		~OBJ();

	private:
		void Insert_Position(const Command & cmd);	//	v
		void Insert_Texture(const Command & cmd);	//	vt
		void Insert_Normal(const Command & cmd);	//	vn
		void Insert_Face(const Command & cmd);		//	f

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
