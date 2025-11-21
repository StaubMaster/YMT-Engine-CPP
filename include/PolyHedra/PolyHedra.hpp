#ifndef  POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "Miscellaneous/ContainerDynamic.hpp"

# include <string>
# include <exception>

struct PolyHedra_MainData;

class SkinBase;

struct Point2D;
struct AxisBox3D;

class Image;
class FileContext;

/*
Functions for changing the PolyHedra
are required for creating it
but I dont want them exposed once the PolyHedra is done

go back to having a seperate PolyHedra::Templace for that ?
it has all the Functions for changing the PolyHedra
Template dosent need to store its own Values
it can just referance the PolyHedra
if I make it nested

but if I make it nested, then I need put it all in the same Header
which is what I want to avoid

make the Template "parallel" to PolyHedra
PolyHedra.ToTemplate() will return a Template with referances to its

YES I CAN forward declare nested classes
thats literally what the first thing in the class is

but the question still is what to catually store in the Template
probably FileContext

maybe other Context stuff
*/

namespace YMT
{
class PolyHedra
{
	public:
		struct Corner;
		struct FaceCorner;
		struct Face;

	private:
		ContainerDynamic<Corner>	Corners;
		ContainerDynamic<Face>		Faces;
	public:
		FileContext *	File;
		SkinBase *		Skin;

	private:
		bool UseCornerNormals;

	private:
		PolyHedra();
	public:
		~PolyHedra();

	public:
		PolyHedra_MainData * ToMainData(int & count);
	public:
		std::string ToInfo() const;
		AxisBox3D	CalcBound() const;

	public:
		struct Template;
		Template * ToTemplate();

	public:
		struct Generate;

	private:
		struct ParsingData;
	public:
		static PolyHedra * Load(const FileContext & file);
};
};

#endif