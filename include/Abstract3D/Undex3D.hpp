#ifndef UNDEX_3D_HPP
# define UNDEX_3D_HPP

# include <iostream>

class Undex3D
{
	public:
		unsigned int X;
		unsigned int Y;
		unsigned int Z;

	public:
		Undex3D();
		Undex3D(unsigned int x, unsigned int y, unsigned int c);
		~Undex3D();

		Undex3D(const Undex3D & other);
		const Undex3D & operator =(const Undex3D & other);

		Undex3D operator +(const Undex3D & other) const;
		Undex3D operator -(const Undex3D & other) const;

	public:
		static bool	Box_inclusive(Undex3D idx, Undex3D min, Undex3D max);
		static bool	Box_exclusive(Undex3D idx, Undex3D min, Undex3D max);

		static bool	loop_inclusive(Undex3D & idx, Undex3D min, Undex3D max);
		static bool	loop_exclusive(Undex3D & idx, Undex3D min, Undex3D max);
		static bool	loop_inclusive(Undex3D & idx, unsigned int min, unsigned int max);
		static bool	loop_exclusive(Undex3D & idx, unsigned int min, unsigned int max);
};

std::ostream & operator <<(std::ostream & o, const Undex3D & idx);

#endif