
#ifndef  UNI_POINT_2D_HPP
# define UNI_POINT_2D_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Uniform/Base/GenericMultiformBase.hpp"

# include "DataDec.hpp"

class BaseShader;

class UniPoint2D : public GenericUniformBase<Point2D>
{
	private:
		int Location;

	public:
		UniPoint2D(std::string name, BaseShader & shader);

	public:
		void PutData(Point2D p) override;
};

#endif
