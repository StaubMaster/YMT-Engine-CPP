#ifndef POLYHEDRA_INST_SHADER_HPP
# define POLYHEDRA_INST_SHADER_HPP

# include "Graphics/BaseShader.hpp"

//# include "Graphics/Uniform/Float/UniTransformation3D.hpp"
//# include "Graphics/Uniform/Float/UniDepth.hpp"
//# include "Graphics/Uniform/Float/UniScale.hpp"

# include "PolyHedraData.hpp"

class YMT::PolyHedra::ShaderInst : public BaseShader
{
	public:
		//UniScale WindowScale;
		//UniDepth Depth;
		//UniTransformation3D UniViewTrans;

	public:
		ShaderInst();
		~ShaderInst();

	private:
		void UniformUpdate();
};

#endif