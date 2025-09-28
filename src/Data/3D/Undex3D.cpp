#include "Data/3D/Undex3D.hpp"



Undex3D::Undex3D()
{
	X = 0;
	Y = 0;
	Z = 0;
}
Undex3D::Undex3D(unsigned int x, unsigned int y, unsigned int z)
{
	X = x;
	Y = y;
	Z = z;
}
Undex3D::~Undex3D()
{

}


Undex3D::Undex3D(const Undex3D & other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
}
const Undex3D & Undex3D::operator =(const Undex3D & other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	return (*this);
}



Undex3D Undex3D::operator +(const Undex3D & other) const
{
	return Undex3D(
		X + other.X,
		Y + other.Y,
		Z + other.Z
	);
}
Undex3D Undex3D::operator -(const Undex3D & other) const
{
	return Undex3D(
		X - other.X,
		Y - other.Y,
		Z - other.Z
	);
}



/*unsigned int	Undex3D::ToIndex(unsigned int size_per_side) const
{
	return (
		X + 
		Y * size_per_side +
		Z * size_per_side * size_per_side
	);
}*/





bool	Undex3D::Box_inclusive(Undex3D idx, Undex3D min, Undex3D max)
{
	return	(idx.X >= min.X && idx.X <= max.X) &&
			(idx.Y >= min.Y && idx.Y <= max.Y) &&
			(idx.Z >= min.Z && idx.Z <= max.Z);
}
bool	Undex3D::Box_exclusive(Undex3D idx, Undex3D min, Undex3D max)
{
	return	(idx.X > min.X && idx.X < max.X) &&
			(idx.Y > min.Y && idx.Y < max.Y) &&
			(idx.Z > min.Z && idx.Z < max.Z);
}



bool Undex3D::loop_inclusive(Undex3D & idx, Undex3D min, Undex3D max)
{
	idx.Z++;
	if (idx.Z > max.Z)
	{
		idx.Z = min.Z,
		idx.Y++;
		if (idx.Y > max.Y)
		{
			idx.Y = min.Y;
			idx.X++;
			if (idx.X > max.X)
			{
				idx.X = min.X;
				return (false);
			}
		}
	}
	return (true);
}
bool Undex3D::loop_exclusive(Undex3D & idx, Undex3D min, Undex3D max)
{
	idx.Z++;
	if (idx.Z >= max.Z)
	{
		idx.Z = min.Z,
		idx.Y++;
		if (idx.Y >= max.Y)
		{
			idx.Y = min.Y;
			idx.X++;
			if (idx.X >= max.X)
			{
				idx.X = min.X;
				return (false);
			}
		}
	}
	return (true);
}
bool Undex3D::loop_inclusive(Undex3D & idx, unsigned int min, unsigned int max)
{
	idx.Z++;
	if (idx.Z > max)
	{
		idx.Z = min,
		idx.Y++;
		if (idx.Y > max)
		{
			idx.Y = min;
			idx.X++;
			if (idx.X > max)
			{
				idx.X = min;
				return (false);
			}
		}
	}
	return (true);
}
bool Undex3D::loop_exclusive(Undex3D & idx, unsigned int min, unsigned int max)
{
	idx.Z++;
	if (idx.Z >= max)
	{
		idx.Z = min,
		idx.Y++;
		if (idx.Y >= max)
		{
			idx.Y = min;
			idx.X++;
			if (idx.X >= max)
			{
				idx.X = min;
				return (false);
			}
		}
	}
	return (true);
}





std::ostream & operator <<(std::ostream & o, const Undex3D & u)
{
	o << "[" << u.X << ":" << u.Y << ":" << u.Z << "]";
	return o;
}
