
#ifndef  POLYHEDRA_3D_SHADER_HPP
# define POLYHEDRA_3D_SHADER_HPP

# include "Graphics/Shader/BaseShader.hpp"
# include "Graphics/Uniform/Uniforms.hpp"

# include "FileManager/DirectoryContext.hpp"
# include "FileManager/FileContext.hpp"



class PolyHedra_3D_Shader : public BaseShader
{
	public:
		UniSizeRatio2D	ViewPortSizeRatio;
		UniTrans3D		View;
		UniDepth		Depth;

	public:
		PolyHedra_3D_Shader(const DirectoryContext & dir);
		~PolyHedra_3D_Shader();
};

#endif
