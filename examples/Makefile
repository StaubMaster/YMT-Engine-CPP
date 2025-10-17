
COMPILER = c++ -std=c++11
FLAGS = -Wall -Wextra -Werror





ifeq ($(OS), Windows_NT)	# Windows dosent have uname
	CheckOS := Windows
else						# everywhere else does
	CheckOS := $(shell uname -s)
endif

ifeq ($(CheckOS), Windows)	#	these files are only there on my System. change to check for those files, else throw an error ?
OS_ARGS := \
	-lglfw3 \
	-lOpenCL \
	-lgdi32
endif

#	works but still different from Mac

ifeq ($(CheckOS), Darwin)
OS_ARGS := \
	-lglfw
endif





MAINS = \
	DefaultInstances.cpp \
	test.cpp
#	LightTest.cpp \
	ParticleSimulation.cpp \
	OBJ_Parse.cpp \

EXES = $(MAINS:.cpp=.exe)

MAINS_DIR = mains/



ARC = \
	../YMT.a \
	../other/OpenGL/openGL.a
#	../other/FileManager/FileManager.a







################################################################
#                  Standard Makefile Commands                  #
################################################################

#	check everything to see if something needs to be recompiled
all:
	@$(foreach arc, $(ARC), \
		echo '[' 'all' $(arc) ']' ; \
		$(MAKE) -C $(dir $(arc)) all || exit 1 ; \
	)
	@echo '[ all Done ]'
	@$(MAKE) $(EXES)

#	remove Everything created my this Makefile except the final output
clean:
	@$(foreach arc, $(ARC), \
		echo '[' 'clean' $(arc) ']' ; \
		$(MAKE) -C $(dir $(arc)) clean || exit 1 ; \
	)
	@echo '[ clean Done ]'

#	remove everything that this makefile created
fclean:
	@$(foreach arc, $(ARC), \
		echo '[' 'fclean' $(arc) ']' ; \
		$(MAKE) -C $(dir $(arc)) fclean || exit 1 ; \
	)
	@echo '[ fclean Done ]'
	@$(MAKE) clean
	rm -f $(EXES)

#	fclean and all ?
re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re

################################################################







%.exe : $(MAINS_DIR)%.cpp $(ARC)
	$(COMPILER) $(FLAGS) -I../include -I../other -I../other/FileManager/include -o $@ $^ $(OS_ARGS)

$(ARC) :
	@$(MAKE) -C $(ARC_DIR) all





test:
	$(MAKE) -C ../ env
	@echo $(var0)


