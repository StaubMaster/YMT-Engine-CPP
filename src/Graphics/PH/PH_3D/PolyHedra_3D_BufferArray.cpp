#include "Graphics/PH/PH_3D/PolyHedra_3D_BufferArray.hpp"

#include "Graphics/Attribute/AttributeLocation.hpp"
#include "Graphics/Attribute/AttributeBase.hpp"

#include "Graphics/Attribute/AttribPoint3D.hpp"
#include "Graphics/Attribute/AttribAngle3D.hpp"

#include "Graphics/Attribute/AttribPoint2D.hpp"
#include "Graphics/Attribute/AttribTrans3D.hpp"

# include "OpenGL/openGL.h"
# include <iostream>



PolyHedra_3D_BufferArray::PolyHedra_3D_BufferArray() :
	Instance_Base_BufferArray(GL_TRIANGLES)
{

}
PolyHedra_3D_BufferArray::~PolyHedra_3D_BufferArray()
{

}

/*
turn the long stuff in the Contstructor into its own class
but then those should be called _Buffer
and this should be _BufferArray ?
yes
*/
