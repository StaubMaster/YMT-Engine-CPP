
#ifndef  UNI_COLOR_HPP
# define UNI_COLOR_HPP

# include "Graphics/Shader/BaseShader.hpp"
# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Uniform/Base/GenericMultiformBase.hpp"

# include "Abstract.hpp"

class UniColor : public GenericUniformBase<Color>
{
	private:
		int Location;

	public:
		UniColor(std::string name, BaseShader & shader);

	public:
		void PutData(Color val) override;
};

class MultiColor : public GenericMultiformBase<UniColor, Color>
{
	public:
		MultiColor(std::string name);
};

#endif
