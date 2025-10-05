


NAME = YMT.a
COMPILER = c++ -std=c++11
FLAGS = -Wall -Wextra -Werror



FILES_SRC = \
\
	DataStruct/Point3D.cpp \
	DataStruct/Angle3D.cpp \
	DataStruct/Trans3D.cpp \
	DataStruct/Undex3D.cpp \
	DataStruct/AxisBox3D.cpp \
	DataStruct/Point2D.cpp \
	DataStruct/SizeRatio2D.cpp \
	DataStruct/Range.cpp \
	DataStruct/LInter.cpp \
	DataStruct/DepthFactors.cpp \
	DataStruct/Point4D.cpp \
	DataStruct/Color.cpp \
	DataStruct/Depth.cpp \
	DataStruct/LightBase.cpp \
	DataStruct/LightSolar.cpp \
	DataStruct/LightSpot.cpp \
	DataStruct/Ray3D.cpp \
	DataO.cpp \
\
	Graphics/Shader/ShaderCode.cpp \
	Graphics/Shader/BaseShader.cpp \
\
	Graphics/Uniform/Base/UniformBase.cpp \
	Graphics/Uniform/Data/Float1.cpp \
	Graphics/Uniform/Data/Point3D.cpp \
	Graphics/Uniform/Data/Angle3D.cpp \
	Graphics/Uniform/Data/Trans3D.cpp \
	Graphics/Uniform/Data/Point2D.cpp \
	Graphics/Uniform/Data/SizeRatio2D.cpp \
	Graphics/Uniform/Data/DepthFactors.cpp \
	Graphics/Uniform/Data/Range.cpp \
	Graphics/Uniform/Data/Depth.cpp \
	Graphics/Uniform/Data/LInter.cpp \
	Graphics/Uniform/Data/Color.cpp \
	Graphics/Uniform/Data/LightBase.cpp \
	Graphics/Uniform/Data/LightSolar.cpp \
	Graphics/Uniform/Data/LightSpot.cpp \
\
	Graphics/Multiform/Base/MultiformBase.cpp \
	Graphics/Multiform/Data/Trans3D.cpp \
	Graphics/Multiform/Data/SizeRatio2D.cpp \
	Graphics/Multiform/Data/DepthFactors.cpp \
	Graphics/Multiform/Data/Range.cpp \
	Graphics/Multiform/Data/Depth.cpp \
	Graphics/Multiform/Data/LInter.cpp \
	Graphics/Multiform/Data/Color.cpp \
\
	Graphics/Buffer/BaseBufferArray.cpp \
	Graphics/Buffer/BaseBuffer.cpp \
\
	Graphics/Attribute/Base/AttributeLocation.cpp \
	Graphics/Attribute/Base/AttributeBase.cpp \
	Graphics/Attribute/Data/Point3D.cpp \
	Graphics/Attribute/Data/Angle3D.cpp \
	Graphics/Attribute/Data/Trans3D.cpp \
	Graphics/Attribute/Data/Point2D.cpp \
	Graphics/Attribute/Data/Point4D.cpp \
	Graphics/Attribute/Data/Color.cpp \
	Graphics/Attribute/Data/Float1.cpp \
\
	PH/PolyHedra_MainData.cpp \
	PH/PolyHedra_MainAttrib.cpp \
	PH/PolyHedra_MainBuffer.cpp \
	PH/PH_3D/PolyHedra_3D_BufferArray.cpp \
	PH/PH_3D/PolyHedra_3D_Instances.cpp \
	PH/PH_3D/PolyHedra_3D_Shader.cpp \
\
	Simple3D/Simple3D_InstData.cpp \
	Simple3D/Simple3D_InstAttrib.cpp \
	Simple3D/Simple3D_InstBuffer.cpp \
\
	Physics3D/Physics3D_InstData.cpp \
	Physics3D/Physics3D_InstAttrib.cpp \
	Physics3D/Physics3D_InstBuffer.cpp \
\
	OBJ/OBJ.cpp \
	OBJ/OBJ_Main.cpp \
	OBJ/OBJ_3D_BufferArray.cpp \
	OBJ/OBJ_3D_Shader.cpp \
	OBJ/MTL.cpp \
\
	TextureArray.cpp \
	PolyHedra.cpp \
	PolyHedraData.cpp \
	TimeMeasure.cpp \
	Window.cpp

FILES_OBJ = $(FILES_SRC:.cpp=.o)

DIR_SRC = src/
DIR_OBJ = obj/

FILES_ABS_OBJ = $(addprefix $(DIR_OBJ), $(FILES_OBJ))



ARC_X_DIR = obj/arc/



$(NAME) : $(FILES_ABS_OBJ)
	@mkdir -p $(ARC_X_DIR)
#	ar -x $(ARC_OPENGL) --output ./obj/arc
#	ar -x $(ARC_FILEPARSER) --output ./obj/arc
#	ar -x E:/Utility/glfw-3.4.bin.WIN64/lib-mingw-w64/libglfw3.a --output ./obj/arc
#	ar -rcs $(NAME) $(FILES_ABS_OBJ) $(ARC_X_DIR)*
#	ar -rcs $(NAME) $(FILES_ABS_OBJ) -lgdi32
	ar -rcs $(NAME) $(FILES_ABS_OBJ)

all:
	@$(MAKE) $(FILES_ABS_OBJ)
	@$(MAKE) $(NAME)

clean:
	rm -f $(FILES_ABS_OBJ)
	rm -f $(ARC_X_DIR)*

fclean:
	@$(MAKE) clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re arc



$(DIR_OBJ)%.o : $(DIR_SRC)%.cpp
	@mkdir -p $(dir $@)
	$(COMPILER) $(FLAGS) -I include -I other -c $^ -o $@


