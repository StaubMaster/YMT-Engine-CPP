
COMPILER = c++ -std=c++11

FLAGS = -Wall -Wextra -Werror



MAINS = \
	test.cpp
#	DefaultInstances.cpp \
	LightTest.cpp \
	OBJ_Parse.cpp \
	ParticleSimulation.cpp \

EXES = $(MAINS:.cpp=.exe)

MAINS_DIR = mains/



ARC = \
	../YMT.a \
	../other/OpenGL/openGL.a \
	../other/FileManager/fileManager.a



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

#	#include "..." search starts here:
#	#include <...> search starts here:
#	 ../include
#	 ../other
#	 E:/Utility/msys32/ucrt64/bin/../lib/gcc/x86_64-w64-mingw32/15.2.0/../../../../include/c++/15.2.0
#	 E:/Utility/msys32/ucrt64/bin/../lib/gcc/x86_64-w64-mingw32/15.2.0/../../../../include/c++/15.2.0/x86_64-w64-mingw32
#	 E:/Utility/msys32/ucrt64/bin/../lib/gcc/x86_64-w64-mingw32/15.2.0/../../../../include/c++/15.2.0/backward
#	 E:/Utility/msys32/ucrt64/bin/../lib/gcc/x86_64-w64-mingw32/15.2.0/include
#	 E:/Utility/msys32/ucrt64/bin/../lib/gcc/x86_64-w64-mingw32/15.2.0/../../../../include
#	 E:/Utility/msys32/ucrt64/bin/../lib/gcc/x86_64-w64-mingw32/15.2.0/include-fixed
#	End of search list.

#	GLFW/glfw3.h is in E:\Utility\glfw-3.4.bin.WIN64\include

ifeq ($(CheckOS), Darwin)
OS_ARGS := \
	-lglfw
endif

#	echo | gcc -E -Wp,-v -
#	get Paths searched by gcc
#		-E	
#		-Wp,	"bypass the compiler driver and pass option directly through to the preprocessor"
#			v ?
#		-v		verbose ? prints commands used by compiler
#		-		???
#	or just use -v when compiling



#	all		check everything to see if something needs to be recompiled
#	clean	remove everything except final output
#			so only the final .exe or also all the .a ?
#	fclean	remove everything
#			including included Libraries ?
#	re		fclean and all ?

all:
	@$(foreach arc, $(ARC), \
		echo '[' 'all' $(arc) ']' ; \
		$(MAKE) -C $(dir $(arc)) all || exit 1 ; \
	)
	@echo '[ all Done ]'
	@$(MAKE) $(EXES)

clean:
	@$(foreach arc, $(ARC), \
		echo '[' 'clean' $(arc) ']' ; \
		$(MAKE) -C $(dir $(arc)) clean || exit 1 ; \
	)
	@echo '[ clean Done ]'

fclean:
	@$(foreach arc, $(ARC), \
		echo '[' 'fclean' $(arc) ']' ; \
		$(MAKE) -C $(dir $(arc)) fclean || exit 1 ; \
	)
	@echo '[ fclean Done ]'
	@$(MAKE) clean
	rm -f $(EXES)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re



%.exe : $(MAINS_DIR)%.cpp $(ARC)
	$(COMPILER) $(FLAGS) -I../include -I../other -o $@ $^ $(OS_ARGS)

$(ARC) :
	@$(MAKE) -C $(ARC_DIR) all
