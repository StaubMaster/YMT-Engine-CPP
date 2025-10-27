


FANCY_NAME := YMT/examples
COLOR_REPO := \e[38;2;127;127;127m
COLOR_TYPE := \e[38;2;127;255;127m
COLOR_FILE := \e[38;2;127;127;255m
COLOR_NONE := \e[m



COMPILER = c++ -std=c++11
FLAGS = -Wall -Wextra -Werror



ifeq ($(OS), Windows_NT)
	CheckOS := Windows
else
	CheckOS := $(shell uname -s)
endif

ifeq ($(CheckOS), Windows)
OS_ARGS := \
	-lglfw3 \
	-lOpenCL \
	-lgdi32
endif

ifeq ($(CheckOS), Darwin)
OS_ARGS := \
	-lglfw
endif





MAINS = \
	LightTest.cpp
#	DefaultInstances.cpp
#	test.cpp
#	ParticleSimulation.cpp \
#	OBJ_Parse.cpp \

EXES = $(MAINS:.cpp=.exe)

MAINS_DIR = mains/



ARC = \
	../other/OpenGL/openGL.a
#	../YMT.a \
#	../other/FileManager/FileManager.a







################################################################
#                  Standard Makefile Commands                  #
################################################################

all:
	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) $(EXES) -s

clean: repos_clean
	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"

fclean: repos_fclean
	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) clean -s
	@rm -f $(EXES)

re:
	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) fclean -s
	@$(MAKE) all -s

.PHONY: all clean fclean re

################################################################





%.exe : $(MAINS_DIR)%.cpp repos
	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Compiling: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(COMPILER) $(FLAGS) $(ARGS_INCLUDES) -o $@ $< $(ARGS_LIBRARYS) $(OS_ARGS)





################################################################
#                     Environment Variables                    #
################################################################

LIBRARYS = 
INCLUDES = 

ARGS_LIBRARYS = $(foreach library, $(LIBRARYS), $(library))
ARGS_INCLUDES = $(foreach include, $(INCLUDES), -I$(include))

librarys:
	@echo '===='
	@echo $(LIBRARYS)
	@echo '===='
	@echo $(ARGS_LIBRARYS)
	@echo '===='

includes:
	@echo '===='
	@echo $(INCLUDES)
	@echo '===='
	@echo $(ARGS_INCLUDES)
	@echo '===='

.PHONY: librarys includes

################################################################





################################################################
#                             REPO                             #
################################################################

YMT_DIR := ..
LIBRARYS += $(foreach library, $(shell $(MAKE) -C $(YMT_DIR) -s librarys), $(YMT_DIR)/$(library))
INCLUDES += $(foreach include, $(shell $(MAKE) -C $(YMT_DIR) -s includes), $(YMT_DIR)/$(include))

repos:
#	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) -C $(YMT_DIR) -s

repos_all:
#	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) -C $(YMT_DIR) all -s

repos_clean:
#	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) -C $(YMT_DIR) clean -s

repos_fclean:
#	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) -C $(YMT_DIR) fclean -s

repos_rm:
#	@echo -e "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) -C $(YMT_DIR) repos_rm -s

.PHONY: repos

################################################################
