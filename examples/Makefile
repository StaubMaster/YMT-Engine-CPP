
COMPILER = c++ -std=c++11

FLAGS = -Wall -Wextra -Werror



MAINS = \
	DefaultInstances.cpp \
	test.cpp
#	LightTest.cpp \
	OBJ_Parse.cpp \
	ParticleSimulation.cpp \

EXES = $(MAINS:.cpp=.exe)

MAINS_DIR = mains/



ARC = \
	../YMT.a \
	../other/OpenGL/openGL.a



ifeq ($(OS), Windows_NT)	# Windows dosent have uname
	CheckOS := Windows
else						# everywhere else does
	CheckOS := $(shell uname -s)
endif

ifeq ($(CheckOS), Windows)	#	these files are only there on my System. change to check for those files, else throw an error ?
OS_ARGS := \
	E:/Utility/glfw-3.4.bin.WIN64/lib-mingw-w64/libglfw3.a \
	E:/Utility/msys32/ucrt64/lib/libOpenCL.dll.a \
	-lgdi32
endif

ifeq ($(CheckOS), Darwin)
OS_ARGS := \
	-lglfw
endif





################################################################
#                  Standard Makefile Commands                  #
################################################################

#	check everything to see if something needs to be recompiled
all:
	@$(MAKE) $(FM_ARC)
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







################################################################
#                 Interaction with Repositroys                 #
################################################################

#	clean on all other repos
rclean:
	$(MAKE) -C $(FM_DIR) clean

#	fclean on all other repos
rfclean:
	$(MAKE) -C $(FM_DIR) fclean

#	remove directory of repos
rrm:
	rm -rf $(FM_DIR)

################################################################





%.exe : $(MAINS_DIR)%.cpp $(ARC)
	$(COMPILER) $(FLAGS) -I../include -I../other -I../other/FileManager/include -o $@ $^ $(FM_ARC) $(OS_ARGS)

$(ARC) :
	@$(MAKE) -C $(ARC_DIR) all





FM_DIR := ../other/FileManager
FM_HTTPS := https://github.com/StaubMaster/CPP-FileManager.git
FM_ARC := $(FM_DIR)/FileManager.a

$(FM_ARC): $(FM_DIR)
	$(MAKE) -C $(FM_DIR) all

$(FM_DIR):
	git clone $(FM_HTTPS) $(FM_DIR)


