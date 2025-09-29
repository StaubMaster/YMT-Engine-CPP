#include "OBJ/OBJ_3D_Shader.hpp"



OBJ_3D_Shader::OBJ_3D_Shader(const DirectoryContext & dir)
	: BaseShader((const ShaderCode []) {
		ShaderCode::FromFile(dir.File("OBJ_inst.vert")),
		ShaderCode::FromFile(dir.File("OBJ_inst.frag")),
	}, 2),
	ViewPortSizeRatio("ViewPortSizeRatio", *this),
	View("View", *this),
	Depth("Depth", *this)
	{ }
OBJ_3D_Shader::~OBJ_3D_Shader()
{

}
