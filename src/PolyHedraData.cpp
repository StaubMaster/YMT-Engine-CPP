#include "PolyHedraData.hpp"

YMT::PolyHedra::Corner::Corner() { }
YMT::PolyHedra::Corner::Corner(Point3D pos) : Position(pos) { }

YMT::PolyHedra::FaceCorner::FaceCorner() { }
YMT::PolyHedra::FaceCorner::FaceCorner(unsigned int udx, float tex_x, float tex_y) : Udx(udx), Tex(tex_x, tex_y) { }

YMT::PolyHedra::Face::Face() { }
YMT::PolyHedra::Face::Face(FaceCorner c0, FaceCorner c1, FaceCorner c2) : Corner0(c0), Corner1(c1), Corner2(c2) { }