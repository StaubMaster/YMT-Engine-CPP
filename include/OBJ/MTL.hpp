
#ifndef  MTL_HPP
# define MTL_HPP

# include "Abstract.hpp"

# include "Miscellaneous/ContainerDynamic.hpp"

# include <exception>



class LineCommand;
class FileContext;

class MTL
{
	public:
		std::string Name;
		Color	Ka;	//	ambient
		Color	Kd;	//	diffuse
		Color	Ks;	//	specular
		float	Ns;	//	specular
		float	d;	//	"dissolve"
		float	Tr;	//	Transparent = 1.0 - d;
		float	Ni;	//	"optical density"
		int		illum;	//	look it up idiot

	private:
		MTL();
	public:
		~MTL();

	private:
		void Parse_newmtl(const LineCommand & cmd);
		void Parse_Ns(const LineCommand & cmd);
		void Parse_Ka(const LineCommand & cmd);
		void Parse_Kd(const LineCommand & cmd);
		void Parse_Ks(const LineCommand & cmd);
		void Parse_Ni(const LineCommand & cmd);
		void Parse_d(const LineCommand & cmd);
		void Parse_illum(const LineCommand & cmd);
		void Parse(const LineCommand & cmd);

	public:
		static MTL * Load(const FileContext & file);
};

#endif
