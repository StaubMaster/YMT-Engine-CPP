#include "DataStruct/Main/Waveform/OBJ_3D_Shader.hpp"
#include "Graphics/Shader/ShaderCode.hpp"

#include "DirectoryContext.hpp"
#include "FileContext.hpp"

#include <iostream>



OBJ_3D_Shader::OBJ_3D_Shader(const DirectoryContext & dir)
	: BaseShader((const ShaderCode []) {
		ShaderCode::FromFile(dir.File("OBJ_S3D.vert")),
		ShaderCode::FromFile(dir.File("OBJ.frag")),
	}, 2),
	ViewPortSizeRatio("ViewPortSizeRatio", *this),
	View("View", *this),
	Depth("Depth", *this),
	ColorToTex("ColorToTex", *this)
{
	//std::cout << "################################################################\n";
	//std::cout << dir.File("OBJ_S3D.vert").LoadText();
	//std::cout << "################################################################\n";
	//std::cout << dir.File("OBJ.frag").LoadText();
	//std::cout << "################################################################\n";
}
OBJ_3D_Shader::~OBJ_3D_Shader()
{

}
