//	put this into the Base folder ?

#ifndef  DATA_O_HPP
# define DATA_O_HPP

# include "DataDec.hpp"

# include <iosfwd>

std::ostream & operator <<(std::ostream & o, const Point2D & val);
std::ostream & operator <<(std::ostream & o, const Point3D & val);
std::ostream & operator <<(std::ostream & o, const Point4D & val);

std::ostream & operator <<(std::ostream & o, const Angle3D & val);

std::ostream & operator <<(std::ostream & o, const Undex3D & val);

std::ostream & operator <<(std::ostream & o, const Color & val);

#endif
