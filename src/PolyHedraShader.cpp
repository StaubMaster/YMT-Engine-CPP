#include "PolyHedraShader.hpp"



PolyHedraShader::PolyHedraShader()
	: BaseShader((const ShaderCode []) {
ShaderCode::FromFile("Shaders/test.vert"),
ShaderCode::FromFile("Shaders/test.frag"),
}, 2)
, WindowScale(this, "contentScale")
, Depth(this, "depthFactor")
, UniTrans(this, "trans")
, UniViewTrans(this, "view")
{

}
PolyHedraShader::~PolyHedraShader()
{

}
