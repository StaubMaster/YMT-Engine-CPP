


NAME = YMT.a
COMPILER = c++ -std=c++11
FLAGS = -Wall -Wextra -Werror



FILES_SRC = \
\
	DataStruct/Point3D.cpp \
	DataStruct/Angle3D.cpp \
	DataStruct/Trans3D.cpp \
	DataStruct/Undex3D.cpp \
	DataStruct/Point2D.cpp \
	DataStruct/SizeRatio2D.cpp \
	DataStruct/Range.cpp \
	DataStruct/LInter.cpp \
	DataStruct/DepthFactors.cpp \
	DataStruct/Point4D.cpp \
	DataStruct/Color.cpp \
	DataStruct/Depth.cpp \
	DataO.cpp \
\
	Graphics/Shader/ShaderCode.cpp \
	Graphics/Shader/BaseShader.cpp \
	Graphics/Uniform/Base/UniformBase.cpp \
	Graphics/Uniform/Data/UniPoint3D.cpp \
	Graphics/Uniform/Data/UniAngle3D.cpp \
	Graphics/Uniform/Data/UniTrans3D.cpp \
	Graphics/Uniform/Data/UniPoint2D.cpp \
	Graphics/Uniform/Data/UniSizeRatio2D.cpp \
	Graphics/Uniform/Data/UniDepthFactors.cpp \
	Graphics/Uniform/Data/UniRange.cpp \
	Graphics/Uniform/Data/UniDepth.cpp \
	Graphics/Uniform/Data/UniColor.cpp \
\
	Graphics/Multiform/Base/MultiformBase.cpp \
	Graphics/Multiform/Data/UniTrans3D.cpp \
	Graphics/Multiform/Data/UniSizeRatio2D.cpp \
	Graphics/Multiform/Data/UniDepthFactors.cpp \
	Graphics/Multiform/Data/UniRange.cpp \
	Graphics/Multiform/Data/UniDepth.cpp \
	Graphics/Multiform/Data/UniColor.cpp \
\
	Graphics/Buffer/BaseBufferArray.cpp \
	Graphics/Buffer/BaseBuffer.cpp \
	Graphics/Attribute/AttributeLocation.cpp \
	Graphics/Attribute/AttributeBase.cpp \
\
	Graphics/Attribute/AttribPoint3D.cpp \
	Graphics/Attribute/AttribAngle3D.cpp \
	Graphics/Attribute/AttribTrans3D.cpp \
	Graphics/Attribute/AttribPoint2D.cpp \
	Graphics/Attribute/AttribPoint4D.cpp \
\
	Graphics/PH/PolyHedra_MainData.cpp \
	Graphics/PH/PolyHedra_MainAttrib.cpp \
	Graphics/PH/PolyHedra_MainBuffer.cpp \
	Graphics/PH/PH_3D/PolyHedra_3D_BufferArray.cpp \
	Graphics/PH/PH_3D/PolyHedra_3D_Instances.cpp \
	Graphics/PH/PH_3D/PolyHedra_3D_Shader.cpp \
\
	Graphics/Simple3D/Simple3D_InstData.cpp \
	Graphics/Simple3D/Simple3D_InstAttrib.cpp \
	Graphics/Simple3D/Simple3D_InstBuffer.cpp \
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


