
#ifndef  UNI_COLOR_HPP
# define UNI_COLOR_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/Float3.hpp"
# include "DataDeclare.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Color : public Uniform::GBase<::Color>
{
	private:
		Uniform::Float3 Location;

	public:
		Color(std::string name, Shader::Base & shader);

	public:
		void PutData(::Color val) override;
};
};

#endif
