
#ifndef  UNI_COLOR_HPP
# define UNI_COLOR_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "DataDec.hpp"

class BaseShader;

namespace Uniform
{
class Color : public Uniform::GenericUniformBase<::Color>
{
	private:
		int Location;

	public:
		Color(std::string name, BaseShader & shader);

	public:
		void PutData(::Color val) override;
};
};

#endif
