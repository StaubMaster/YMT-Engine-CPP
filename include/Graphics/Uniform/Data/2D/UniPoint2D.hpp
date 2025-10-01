
#ifndef  UNI_POINT_2D_HPP
# define UNI_POINT_2D_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"

# include "DataDec.hpp"

class BaseShader;

namespace Uniform
{
class Point2D : public Uniform::GenericUniformBase<::Point2D>
{
	private:
		int Location;

	public:
		Point2D(std::string name, BaseShader & shader);

	public:
		void PutData(::Point2D p) override;
};
};

#endif
