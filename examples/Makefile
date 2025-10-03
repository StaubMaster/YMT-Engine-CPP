
COMPILER = c++ -std=c++11

FLAGS = -Wall -Wextra -Werror



MAINS = \
	OBJ_Parse.cpp \
	DefaultInstances.cpp \
	ParticleSimulation.cpp \
	LightTest.cpp

EXES = $(MAINS:.cpp=.exe)

MAINS_DIR = mains/



ARC = \
	../YMT.a \
	../other/OpenGL/openGL.a \
	../other/FileManager/fileManager.a

WIN_ARGS = \
	E:/Utility/glfw-3.4.bin.WIN64/lib-mingw-w64/libglfw3.a \
	E:/Utility/msys32/ucrt64/lib/libOpenCL.dll.a \
	-lgdi32

MAC_ARGS = \
	-lglfw

#	pretty sure I can add these directories to some environment PATH variable
#	but I cant really find which path ?
#	not sure if the documentation sucks, if google sucks, or if I'm just stupid



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
	$(COMPILER) $(FLAGS) -I ../include -I ../other -o $@ $^ $(WIN_ARGS)
#	$(COMPILER) $(FLAGS) -I ../include -I ../other -o $@ $^ $(MAC_ARGS)

$(ARC) :
	@$(MAKE) -C $(ARC_DIR) all


