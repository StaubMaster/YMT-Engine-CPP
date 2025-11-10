
NAME := openGL.a
FLAGS := -Wall -Wextra -Werror



FILES_SRC := \
	openGL.cpp \
	glad/glad.c

FILES_OBJ := $(FILES_SRC)
FILES_OBJ := $(FILES_OBJ:.c=.o)
FILES_OBJ := $(FILES_OBJ:.cpp=.o)





################################################################
#                           OS Stuff                           #
################################################################

ifeq ($(OS), Windows_NT)
	CheckOS := Windows
else
	CheckOS := $(shell uname -s)
endif

FANCY_NAME := Examples

ifeq ($(CheckOS), Windows)
OS_ARGS := \
	-lglfw3 \
	-lgdi32

FANCY_ECHO := echo -e
COLOR_REPO := \e[38;2;127;127;127m
COLOR_TYPE := \e[38;2;127;255;127m
COLOR_FILE := \e[38;2;127;127;255m
COLOR_NONE := \e[m

endif

ifeq ($(CheckOS), Darwin)
OS_ARGS := \
	-lglfw

FANCY_ECHO := echo
COLOR_REPO := \033[38;2;127;127;127m
COLOR_TYPE := \033[38;2;127;255;127m
COLOR_FILE := \033[38;2;127;127;255m
COLOR_NONE := \033[m

endif

################################################################





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

%.o : %.cpp
	c++ -std=c++11 $(FLAGS) -c $^ -o $@







################################################################

LIBRARYS = $(NAME)
INCLUDES = ../
ARGUMENTS = $(OS_ARGS)

librarys:
	@echo $(LIBRARYS)

includes:
	@echo $(INCLUDES)

arguments:
	@echo $(ARGUMENTS)

.PHONY: librarys includes arguments

################################################################


