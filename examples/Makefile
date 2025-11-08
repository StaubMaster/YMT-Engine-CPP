


################################################################
#                           OS Stuff                           #
################################################################

ifeq ($(OS), Windows_NT)
	CheckOS := Windows
else
	CheckOS := $(shell uname -s)
endif

FANCY_NAME := YMT/examples

ifeq ($(CheckOS), Windows)
OS_ARGS := \
	-lglfw3 \
	-lOpenCL \
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



COMPILER = c++ -std=c++11
FLAGS = -Wall -Wextra -Werror

MAINS = \
	OBJ_Parse.cpp
#	LightTest.cpp
#	DefaultInstances.cpp
#	test.cpp
#	ParticleSimulation.cpp

EXES = $(MAINS:.cpp=.exe)

MAINS_DIR = mains/





################################################################
#                  Standard Makefile Commands                  #
################################################################

all:
	@mkdir logs/
	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) $(EXES) -s

clean: repos_clean
	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"

fclean: repos_fclean
	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) clean -s
	@rm -f $(EXES)

re:
	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) fclean -s
	@$(MAKE) all -s

.PHONY: all clean fclean re

################################################################





%.exe : $(MAINS_DIR)%.cpp repos
	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Compiling: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(COMPILER) $(FLAGS) $(ARGS_INCLUDES) -o $@ $< $(ARGS_LIBRARYS) $(OS_ARGS)





################################################################
#                     Environment Variables                    #
################################################################

LIBRARYS = 
INCLUDES = 

ARGS_LIBRARYS = $(foreach library, $(LIBRARYS), $(library))
ARGS_INCLUDES = $(foreach include, $(INCLUDES), -I$(include))

librarys:
	@$(FANCY_ECHO) '===='
	@$(FANCY_ECHO) $(LIBRARYS)
	@$(FANCY_ECHO) '===='
	@$(FANCY_ECHO) $(ARGS_LIBRARYS)
	@$(FANCY_ECHO) '===='

includes:
	@$(FANCY_ECHO) '===='
	@$(FANCY_ECHO) $(INCLUDES)
	@$(FANCY_ECHO) '===='
	@$(FANCY_ECHO) $(ARGS_INCLUDES)
	@$(FANCY_ECHO) '===='

.PHONY: librarys includes

################################################################





################################################################
#                             REPO                             #
################################################################

YMT_DIR := ..
LIBRARYS += $(foreach library, $(shell $(MAKE) -C $(YMT_DIR) -s librarys), $(YMT_DIR)/$(library))
INCLUDES += $(foreach include, $(shell $(MAKE) -C $(YMT_DIR) -s includes), $(YMT_DIR)/$(include))

work:
	$(MAKE) -C $(YMT_DIR) work -s
	@$(MAKE) $(EXES) -s

repos:
#	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) -C $(YMT_DIR) -s

repos_all:
#	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) -C $(YMT_DIR) all -s

repos_clean:
#	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) -C $(YMT_DIR) clean -s

repos_fclean:
#	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) -C $(YMT_DIR) fclean -s

repos_rm:
#	@$(FANCY_ECHO) "$(COLOR_REPO)$(FANCY_NAME): $(COLOR_TYPE)Target: $(COLOR_FILE)$@$(COLOR_NONE)"
	@$(MAKE) -C $(YMT_DIR) repos_rm -s

.PHONY: repos

################################################################
