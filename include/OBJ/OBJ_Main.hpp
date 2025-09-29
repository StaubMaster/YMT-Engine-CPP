
#ifndef  OBJ_MAIN_HPP
# define OBJ_MAIN_HPP



# include "Abstract.hpp"



# include "Graphics/Attribute/AttributeLocation.hpp"
# include "Graphics/Attribute/AttributeBase.hpp"

# include "Graphics/Attribute/AttribPoint3D.hpp"
# include "Graphics/Attribute/AttribPoint2D.hpp"



# include "Graphics/Buffer/BaseBuffer.hpp"



struct OBJ_MainData
{
	Point3D	Position;
	Point2D	Texture;
	Point3D	Normal;
};



class OBJ_MainAttrib : public AttributeBase
{
	private:
		AttribPoint3D	Position;
		AttribPoint2D	Texture;
		AttribPoint3D	Normal;

	public:
		OBJ_MainAttrib(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexPosition,
			unsigned int indexTexture,
			unsigned int indexNormal
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};



class OBJ_MainBuffer : public BaseBuffer
{
	public:
		OBJ_MainBuffer(
			unsigned int indexPosition,
			unsigned int indexTexture,
			unsigned int indexNormal
		);
		~OBJ_MainBuffer();
};



#endif
