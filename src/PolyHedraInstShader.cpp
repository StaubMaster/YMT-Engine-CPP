#include "PolyHedraInstShader.hpp"



PolyHedraInstShader::PolyHedraInstShader()
	: BaseShader((const ShaderCode []) {
ShaderCode::FromFile(SHADER_DIR + std::string("inst.vert")),
ShaderCode::FromFile(SHADER_DIR + std::string("inst.frag")),
}, 2)
, WindowScale(this, "contentScale")
, Depth(this, "depthFactor")
, UniViewTrans(this, "view")
{

}
PolyHedraInstShader::~PolyHedraInstShader()
{

}



void PolyHedraInstShader::UniformUpdate()
{
	WindowScale.Update();
	Depth.Update();
	UniViewTrans.Update();
}
