
#ifndef  OBJ_MAIN_HPP
# define OBJ_MAIN_HPP



# include "DataStruct/Point3D.hpp"
# include "DataStruct/Point4D.hpp"



# include "Graphics/Attribute/AttributeLocation.hpp"
# include "Graphics/Attribute/AttributeBase.hpp"

# include "Graphics/Attribute/AttribPoint4D.hpp"
# include "Graphics/Attribute/AttribPoint3D.hpp"



# include "Graphics/Buffer/BaseBuffer.hpp"



struct OBJ_MainData
{
	Point4D	Position;
	Point3D	Texture;
	Point3D	Normal;
};



class OBJ_MainAttrib : public Attribute::Base
{
	private:
		Attribute::Point4D	Position;
		Attribute::Point3D	Texture;
		Attribute::Point3D	Normal;

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
