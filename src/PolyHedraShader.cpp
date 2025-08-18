#include "PolyHedraShader.hpp"



PolyHedraShader::PolyHedraShader()
	: BaseShader((const ShaderCode []) {
ShaderCode::FromFile(SHADER_DIR + std::string("test.vert")),
ShaderCode::FromFile(SHADER_DIR + std::string("test.frag")),
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



void PolyHedraShader::UniformUpdate()
{
	WindowScale.Update();
	Depth.Update();
	UniTrans.Update();
	UniViewTrans.Update();
}
