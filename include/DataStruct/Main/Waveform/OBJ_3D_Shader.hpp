
#ifndef  OBJ_3D_SHADER_HPP
# define OBJ_3D_SHADER_HPP

# include "Graphics/Shader/Base.hpp"
# include "Graphics/UniformsInclude.hpp"

class DirectoryContext;

class OBJ_3D_Shader : public Shader::Base
{
	public:
		Uniform::SizeRatio2D	ViewPortSizeRatio;
		Uniform::Trans3D		View;
		Uniform::Depth			Depth;
		Uniform::LInter			ColorToTex;

	public:
		OBJ_3D_Shader(const DirectoryContext & dir);
		~OBJ_3D_Shader();
};

#endif
