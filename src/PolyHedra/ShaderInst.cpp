#include "PolyHedra.hpp"



YMT::PolyHedra::ShaderInst::ShaderInst(const DirectoryContext & dir)
	: BaseShader((const ShaderCode []) {
		ShaderCode::FromFile(dir.File("inst.vert")),
		ShaderCode::FromFile(dir.File("inst.frag")),
	}, 2)
//, WindowScale(this, "contentScale")
//, Depth(this, "depthFactor")
//, UniViewTrans(this, "view")
{

}
YMT::PolyHedra::ShaderInst::~ShaderInst()
{

}



void YMT::PolyHedra::ShaderInst::UniformUpdate()
{
	//WindowScale.Update();
	//Depth.Update();
	//UniViewTrans.Update();
}
