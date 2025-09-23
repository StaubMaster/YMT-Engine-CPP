#include "PolyHedra.hpp"



YMT::PolyHedra::ShaderInst::ShaderInst()
	: BaseShader((const ShaderCode []) {
ShaderCode::FromFile(SHADER_DIR + std::string("inst.vert")),
ShaderCode::FromFile(SHADER_DIR + std::string("inst.frag")),
}, 2)
, WindowScale(this, "contentScale")
, Depth(this, "depthFactor")
, UniViewTrans(this, "view")
{

}
YMT::PolyHedra::ShaderInst::~ShaderInst()
{

}



void YMT::PolyHedra::ShaderInst::UniformUpdate()
{
	WindowScale.Update();
	Depth.Update();
	UniViewTrans.Update();
}
