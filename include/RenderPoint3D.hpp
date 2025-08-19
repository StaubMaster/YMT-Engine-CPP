#ifndef RENDER_POINT_3D_HPP
 #define RENDER_POINT_3D_HPP

# include "Abstract2D/Point2D.hpp"
# include "Abstract3D/Point3D.hpp"

struct RenderPoint3D
{
	Point3D	Position;
	Point3D	Normal;
	Point2D	Texture;
};

#endif