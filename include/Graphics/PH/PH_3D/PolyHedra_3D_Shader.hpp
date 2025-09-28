
#ifndef  POLYHEDRA_3D_SHADER_HPP
# define POLYHEDRA_3D_SHADER_HPP

# include "Graphics/Shader/BaseShader.hpp"

# include "Graphics/Uniform/Abstract2D/UniSizeRatio2D.hpp"
# include "Graphics/Uniform/Abstract1D/UniDepthFactors.hpp"
# include "Graphics/Uniform/Abstract3D/UniTrans3D.hpp"

# include "FileManager/DirectoryContext.hpp"
# include "FileManager/FileContext.hpp"



class PolyHedra_3D_Shader : public BaseShader
{
	public:
		UniSizeRatio2D	ViewPortSizeRatio;
		UniTrans3D		View;
		UniDepthFactors	DepthFactors;

	public:
		PolyHedra_3D_Shader(const DirectoryContext & dir);
		~PolyHedra_3D_Shader();
};

#endif
