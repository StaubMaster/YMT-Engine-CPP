#include "DataStruct/Full/PolyHedra_3D/PolyHedra_3D_Shader.hpp"
#include "Graphics/Shader/Code.hpp"

#include "DirectoryContext.hpp"
#include "FileContext.hpp"



PolyHedra_3D_Shader::PolyHedra_3D_Shader(const DirectoryContext & dir)
	: Shader::Base((const Shader::Code []) {
		Shader::Code::FromFile(dir.File("PH_S3D.vert")),
		//Shader::Code::FromFile(dir.File("PH_solar.frag")),
		//Shader::Code::FromFile(dir.File("PH_ULight.frag")),
		Shader::Code::FromFile(dir.File("PH_Full.frag")),
	}, 2),
	ViewPortSizeRatio("ViewPortSizeRatio", *this),
	View("View", *this),
	Depth("Depth", *this)
	{ }
PolyHedra_3D_Shader::~PolyHedra_3D_Shader()
{

}
