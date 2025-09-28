#include "Graphics/PH/PH_3D/PolyHedra_3D_Shader.hpp"



PolyHedra_3D_Shader::PolyHedra_3D_Shader(const DirectoryContext & dir)
	: BaseShader((const ShaderCode []) {
		ShaderCode::FromFile(dir.File("inst.vert")),
		ShaderCode::FromFile(dir.File("inst.frag")),
	}, 2),
	ViewPortSizeRatio("ViewPortSizeRatio", *this),
	View("View", *this),
	DepthFactors("DepthFactors", *this)
	{ }
PolyHedra_3D_Shader::~PolyHedra_3D_Shader()
{

}
