#ifndef POLYHEDRA_SHADER_HPP
# define POLYHEDRA_SHADER_HPP

# include "Graphics/BaseShader.hpp"
# include "Graphics/Uniform/Float/UniTransformation3D.hpp"
# include "Graphics/Uniform/Float/UniDepth.hpp"
# include "Graphics/Uniform/Float/UniScale.hpp"

class PolyHedraShader : public BaseShader
{
	public:
		UniScale WindowScale;
		UniDepth Depth;
		UniTransformation3D UniTrans;
		UniTransformation3D UniViewTrans;

	public:
		PolyHedraShader();
		~PolyHedraShader();
};

#endif