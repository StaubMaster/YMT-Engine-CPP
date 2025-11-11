#include "PolyHedra/Data.hpp"

YMT::PolyHedra::Corner::Corner() { }
YMT::PolyHedra::Corner::Corner(Point3D pos) : Position(pos) { }

YMT::PolyHedra::FaceCorner::FaceCorner() { }
YMT::PolyHedra::FaceCorner::FaceCorner(unsigned int udx) : Udx(udx) { }

YMT::PolyHedra::Face::Face() { }
YMT::PolyHedra::Face::Face(FaceCorner c0, FaceCorner c1, FaceCorner c2) : Corner0(c0), Corner1(c1), Corner2(c2) { }
