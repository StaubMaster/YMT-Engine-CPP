#include "PH/PH_3D/PolyHedra_3D_Shader.hpp"
#include "Graphics/Shader/ShaderCode.hpp"



PolyHedra_3D_Shader::PolyHedra_3D_Shader(const DirectoryContext & dir)
	: BaseShader((const ShaderCode []) {
		ShaderCode::FromFile(dir.File("PH_S3D.vert")),
		//ShaderCode::FromFile(dir.File("PH_solar.frag")),
		ShaderCode::FromFile(dir.File("PH_ULight.frag")),
	}, 2),
	ViewPortSizeRatio("ViewPortSizeRatio", *this),
	View("View", *this),
	Depth("Depth", *this)
	{ }
PolyHedra_3D_Shader::~PolyHedra_3D_Shader()
{

}
