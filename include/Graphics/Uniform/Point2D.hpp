
#ifndef  UNI_POINT_2D_HPP
# define UNI_POINT_2D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/Float2.hpp"
# include "DataDeclare.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Point2D : public Uniform::GBase<::Point2D>
{
	private:
		Uniform::Float2 Location;

	public:
		Point2D(std::string name, Shader::Base & shader);

	public:
		void PutData(::Point2D p) override;
};
};

#endif
