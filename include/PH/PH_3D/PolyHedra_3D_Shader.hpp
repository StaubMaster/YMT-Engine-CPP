
#ifndef  POLYHEDRA_3D_SHADER_HPP
# define POLYHEDRA_3D_SHADER_HPP

# include "Graphics/Shader/BaseShader.hpp"
# include "Graphics/Uniform/Uniforms.hpp"

class DirectoryContext;

class PolyHedra_3D_Shader : public BaseShader
{
	public:
		Uniform::SizeRatio2D	ViewPortSizeRatio;
		Uniform::Trans3D		View;
		Uniform::Depth			Depth;

	public:
		PolyHedra_3D_Shader(const DirectoryContext & dir);
		~PolyHedra_3D_Shader();
};

#endif
