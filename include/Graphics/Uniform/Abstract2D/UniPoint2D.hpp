
#ifndef  UNI_NEW_POINT_2D_HPP
# define UNI_NEW_POINT_2D_HPP

# include "Abstract.hpp"
# include "Graphics/BaseShader.hpp"
# include "Graphics/Uniform/GenericShaderUniform.hpp"
# include "Graphics/Uniform/GenericUniformBase.hpp"

class UniPoint2D : public GenericShaderUniform<Point2D>
{
	private:
		int Location;

	public:
		UniPoint2D(std::string name, BaseShader & shader);

	public:
		void PutData(Point2D p) override;
};

#endif
