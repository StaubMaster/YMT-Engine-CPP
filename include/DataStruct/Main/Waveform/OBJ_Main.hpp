
#ifndef  OBJ_MAIN_HPP
# define OBJ_MAIN_HPP



# include "DataStruct/Point3D.hpp"
# include "DataStruct/Point4D.hpp"
# include "DataStruct/Color.hpp"



# include "Graphics/Attribute/Base/AttributeLocation.hpp"
# include "Graphics/Attribute/Base/AttributeBase.hpp"

# include "Graphics/Attribute/Point4D.hpp"
# include "Graphics/Attribute/Point3D.hpp"
# include "Graphics/Attribute/Color.hpp"
# include "Graphics/Attribute/Base/FloatN.hpp"



# include "Graphics/Buffer/BaseBuffer.hpp"



struct OBJ_MainData
{
	Point4D	Position;
	Point3D	Texture;
	Point3D	Normal;
	::Color	Color;

	::Color	AmbientColor;
	::Color	DiffuseColor;
	float	SpecularPower;
	::Color	SpecularColor;
};



class OBJ_MainAttrib : public Attribute::Base
{
	private:
		Attribute::Point4D	Position;
		Attribute::Point3D	Texture;
		Attribute::Point3D	Normal;
		Attribute::Color	Color;

		Attribute::Color	AmbientColor;
		Attribute::Color	DiffuseColor;
		Attribute::FloatN	SpecularPower;
		Attribute::Color	SpecularColor;

	public:
		OBJ_MainAttrib(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexPosition,
			unsigned int indexTexture,
			unsigned int indexNormal,
			unsigned int indexColor,
			unsigned int indexAmbientColor,
			unsigned int indexDiffuseColor,
			unsigned int indexSpecularPower,
			unsigned int indexSpecularColor
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
			unsigned int indexNormal,
			unsigned int indexColor,
			unsigned int indexAmbientColor,
			unsigned int indexDiffuseColor,
			unsigned int indexSpecularPower,
			unsigned int indexSpecularColor
		);
		~OBJ_MainBuffer();
};



#endif
