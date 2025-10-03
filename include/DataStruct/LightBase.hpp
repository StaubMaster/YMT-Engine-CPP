
#ifndef  LIGHT_BASE_HPP
# define LIGHT_BASE_HPP

# include "Color.hpp"

struct LightBase
{
	public:
		float	Intensity;
		Color	Color;

	public:
		LightBase();
		LightBase(float intensity, ::Color color);
};

#endif
