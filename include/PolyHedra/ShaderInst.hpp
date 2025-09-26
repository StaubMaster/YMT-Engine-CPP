#ifndef POLYHEDRA_INST_SHADER_HPP
# define POLYHEDRA_INST_SHADER_HPP

# include "Graphics/BaseShader.hpp"

//# include "Graphics/Uniform/Float/UniTransformation3D.hpp"
//# include "Graphics/Uniform/Float/UniDepth.hpp"
//# include "Graphics/Uniform/Float/UniScale.hpp"

# include "FileManager/DirectoryContext.hpp"
# include "FileManager/FileContext.hpp"

# include "PolyHedraData.hpp"

class YMT::PolyHedra::ShaderInst : public BaseShader
{
	public:
		//UniScale WindowScale;
		//UniDepth Depth;
		//UniTransformation3D UniViewTrans;

	public:
		ShaderInst(const DirectoryContext & dir);
		~ShaderInst();

	private:
		void UniformUpdate();
};

#endif