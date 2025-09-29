
#ifndef  POINT_4D_HPP
# define POINT_4D_HPP

# include <fstream>

class Point4D
{
	public:
		float X;
		float Y;
		float Z;
		float W;
};

std::ostream & operator <<(std::ostream & o, const Point4D & idx);

#endif
