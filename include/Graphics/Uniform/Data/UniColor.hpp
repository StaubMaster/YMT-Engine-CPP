
#ifndef  UNI_COLOR_HPP
# define UNI_COLOR_HPP

# include "Graphics/Shader/BaseShader.hpp"
# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Uniform/Base/GenericMultiformBase.hpp"

# include "Data/DataFore.hpp"

class UniColor : public GenericUniformBase<Color>
{
	private:
		int Location;

	public:
		UniColor(std::string name, BaseShader & shader);

	public:
		void PutData(Color val) override;
};

# include "Data/Color.hpp"

class MultiColor : public GenericMultiformBase<UniColor, Color>
{
	public:
		MultiColor(std::string name);
};

#endif
