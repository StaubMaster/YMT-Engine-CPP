#include "OBJ/OBJ_3D_Shader.hpp"
#include "Graphics/Shader/ShaderCode.hpp"



OBJ_3D_Shader::OBJ_3D_Shader(const DirectoryContext & dir)
	: BaseShader((const ShaderCode []) {
		ShaderCode::FromFile(dir.File("OBJ_S3D.vert")),
		ShaderCode::FromFile(dir.File("OBJ.frag")),
	}, 2),
	ViewPortSizeRatio("ViewPortSizeRatio", *this),
	View("View", *this),
	Depth("Depth", *this),
	ColorToTex("ColorToTex", *this)
	{ }
OBJ_3D_Shader::~OBJ_3D_Shader()
{

}
