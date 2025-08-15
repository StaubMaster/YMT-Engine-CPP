
NAME = a.exe

FLAGS = -Wall -Wextra -Werror



FILES_SRC = \
	main.cpp

FILES_OBJ = $(FILES_SRC:.cpp=.o)

DIR_SRC = src
DIR_OBJ = obj



ARC_OPENGL_PATH = ./OpenGL
ARC_OPENGL = $(ARC_OPENGL_PATH)/openGL.a



$(NAME): $(DIR_OBJ)/$(FILES_OBJ) $(ARC_OPENGL)
	c++ $(FLAGS) -o $(NAME) $(DIR_OBJ)/$(FILES_OBJ) $(ARC_OPENGL) E:/Utility/glfw-3.4.bin.WIN64/lib-mingw-w64/libglfw3.a -lgdi32

all:
	$(MAKE) $(DIR_OBJ)/$(FILES_OBJ)
	$(MAKE) $(NAME)

clean:
	rm -f $(DIR_OBJ)/$(FILES_OBJ)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re



$(DIR_OBJ)/%.o : $(DIR_SRC)/%.cpp
	c++ $(FLAGS) -c $^ -o $@


