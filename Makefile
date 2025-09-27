


#NAME = a.exe
NAME = YMT.a
COMPILER = c++ -std=c++11
FLAGS = -Wall -Wextra -Werror



FILES_SRC = \
\
	Abstract3D/Point3D.cpp \
	Abstract3D/Angle3D.cpp \
	Abstract3D/Transformation3D.cpp \
	Abstract3D/Undex3D.cpp \
\
	Abstract2D/Point2D.cpp \
	Abstract2D/SizeRatio2D.cpp \
\
	Abstract1D/DepthFactors.cpp \
\
	Graphics/ShaderCode.cpp \
	Graphics/Shader/BaseShader.cpp \
	Graphics/Buffer/BufferArray.cpp \
	Graphics/Buffer/BaseBuffer.cpp \
\
	Graphics/Attribute/AttributeLocation.cpp \
	Graphics/Attribute/AttributeBase.cpp \
	Graphics/Attribute/AttribPoint3D.cpp \
	Graphics/Attribute/AttribAngle3D.cpp \
	Graphics/Attribute/AttribTrans3D.cpp \
	Graphics/Attribute/AttribPoint2D.cpp \
\
	Graphics/Uniform/Base/UniformBase.cpp \
	Graphics/Uniform/Base/MultiformBase.cpp \
\
	Graphics/Uniform/Abstract3D/UniPoint3D.cpp \
	Graphics/Uniform/Abstract3D/UniAngle3D.cpp \
	Graphics/Uniform/Abstract3D/UniTrans3D.cpp \
	Graphics/Uniform/Abstract1D/UniDepthFactors.cpp \
	Graphics/Uniform/Abstract2D/UniPoint2D.cpp \
	Graphics/Uniform/Abstract2D/UniSizeRatio2D.cpp \
\
	Graphics/Buffer/PolyHedra_3D_InstData.cpp \
	Graphics/Buffer/PolyHedra_3D_Buffer.cpp \
	Graphics/Buffer/PolyHedra_3D_Instances.cpp \
	Graphics/Shader/PolyHedra_3D_Shader.cpp \
\
	PolyHedra.cpp \
	TextureArray.cpp \
	TimeMeasure.cpp \
	Window.cpp



FILES_OBJ = $(FILES_SRC:.cpp=.o)

DIR_SRC = src/
DIR_OBJ = obj/

FILES_ABS_OBJ = $(addprefix $(DIR_OBJ), $(FILES_OBJ))



ARC_X = 
ARC_X_DIR = obj/arc/

ARC_OPENGL_PATH = other/OpenGL/
ARC_OPENGL = $(ARC_OPENGL_PATH)openGL.a

ARC_FILEPARSER_PATH = other/FileParse/
ARC_FILEPARSER = $(ARC_FILEPARSER_PATH)fileParser.a



$(NAME) : $(FILES_ABS_OBJ)
	@mkdir -p $(ARC_X_DIR)
	ar -x $(ARC_OPENGL) --output ./obj/arc
	ar -x $(ARC_FILEPARSER) --output ./obj/arc
	ar -x E:/Utility/glfw-3.4.bin.WIN64/lib-mingw-w64/libglfw3.a --output ./obj/arc
	ar -rcs $(NAME) $(FILES_ABS_OBJ) $(ARC_X_DIR)* -lgdi32
#	ar -rcs $(NAME) $(FILES_ABS_OBJ) $(ARC_X_DIR)*

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


