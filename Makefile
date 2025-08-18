


#NAME = a.exe
NAME = YMT.a
COMPILER = c++
FLAGS = -Wall -Wextra -Werror



FILES_SRC = \
\
	Abstract3D/Point3D.cpp \
	Abstract3D/Angle3D.cpp \
	Abstract3D/Transformation3D.cpp \
	Abstract3D/Undex3D.cpp \
\
	Abstract2D/Point2D.cpp \
\
	Graphics/ShaderCode.cpp \
	Graphics/BaseShader.cpp \
	Graphics/BaseBuffer.cpp \
\
	Graphics/Uniform/UniBase.cpp \
	Graphics/Uniform/Float/UniFloatN.cpp \
	Graphics/Uniform/Float/UniFloat1.cpp \
	Graphics/Uniform/Float/UniFloat2.cpp \
	Graphics/Uniform/Float/UniFloat3.cpp \
	Graphics/Uniform/Float/UniTransformation3D.cpp \
	Graphics/Uniform/Float/UniDepth.cpp \
	Graphics/Uniform/Float/UniScale.cpp \
\
	PolyHedra.cpp \
	PolyHedraBuffer.cpp \
	PolyHedraShader.cpp \
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
	cd $(ARC_X_DIR) && ar -x ../../$(ARC_OPENGL)
	cd $(ARC_X_DIR) && ar -x ../../$(ARC_FILEPARSER)
	cd $(ARC_X_DIR) && ar -x E:/Utility/glfw-3.4.bin.WIN64/lib-mingw-w64/libglfw3.a
	ar -rcs $(NAME) $(FILES_ABS_OBJ) $(ARC_X_DIR)* -lgdi32

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


