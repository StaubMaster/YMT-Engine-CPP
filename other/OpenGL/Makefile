
NAME = openGL.a
FLAGS = -Wall -Wextra -Werror



FILES_SRC = \
	glad/glad.c

FILES_OBJ = $(FILES_SRC:.c=.o)





################################################################

$(NAME) : $(FILES_OBJ)
	ar -rcs $(NAME) $(FILES_OBJ)

all:
	$(MAKE) $(FILES_OBJ)
	$(MAKE) $(NAME)

clean:
	rm -f $(FILES_OBJ)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

################################################################





%.o : %.c
	cc $(FLAGS) -c $^ -o $@







################################################################

LIBRARYS = $(NAME)
INCLUDES = ../

librarys:
	@echo $(LIBRARYS)

includes:
	@echo $(INCLUDES)

.PHONY: librarys includes

################################################################





#ifeq ($(OS), Windows_NT)
#	CheckOS := Windows
#else
#	CheckOS := $(shell uname -s)
#endif
#
#ifeq ($(CheckOS), Windows)
#LIBRARYS += \
#	-lglfw3 \
#	-lOpenCL \
#	-lgdi32
#endif
#
#ifeq ($(CheckOS), Darwin)
#LIBRARYS += \
#	-lglfw
#endif

#	dosent want to work ?
#	make librarys only gives $(NAME)
#	maybe I'm doing something wrong
#	also the order matters
#	openCL isnt needed for regular openGL stuff
#	but when I include it later I might need to use -lgdi32 a second time
#	which would be unoptimal


