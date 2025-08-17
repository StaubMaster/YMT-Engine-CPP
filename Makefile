
NAME = a.exe
COMPILER = c++

FLAGS = -Wall -Wextra -Werror



FILES_SRC = \
\
	Window.cpp \
	PolyHedra.cpp \
	PolyHedraBuffer.cpp \
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
	Abstract3D/Point3D.cpp \
	Abstract3D/Angle3D.cpp \
	Abstract3D/Transformation3D.cpp \
	Abstract3D/Undex3D.cpp \
\
	Abstract2D/Point2D.cpp \
\
	main.cpp

FILES_OBJ = $(FILES_SRC:.cpp=.o)

DIR_SRC = src/
DIR_OBJ = obj/



ARC_OPENGL_PATH = ./OpenGL
ARC_OPENGL = $(ARC_OPENGL_PATH)/openGL.a



$(NAME): $(addprefix $(DIR_OBJ), $(FILES_OBJ)) $(ARC_OPENGL)
	$(COMPILER) $(FLAGS) -o $(NAME) $(addprefix $(DIR_OBJ), $(FILES_OBJ)) $(ARC_OPENGL) E:/Utility/glfw-3.4.bin.WIN64/lib-mingw-w64/libglfw3.a -lgdi32

all:
	@$(MAKE) $(addprefix $(DIR_OBJ), $(FILES_OBJ))
	@$(MAKE) $(NAME)

clean:
	rm -f $(addprefix $(DIR_OBJ), $(FILES_OBJ))

fclean:
	@$(MAKE) clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re



$(DIR_OBJ)%.o : $(DIR_SRC)%.cpp
	@mkdir -p $(dir $@)
	$(COMPILER) $(FLAGS) -I include -c $^ -o $@


