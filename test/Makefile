
COMPILER = c++

FLAGS = -Wall -Wextra -Werror



MAINS = \
	inst.cpp \
	basic_openCL.cpp \
	better_openCL.cpp \
	my_openCL.cpp

EXES = $(MAINS:.cpp=.exe)

MAINS_DIR = mains/



ARC_NAME = \
	YMT.a

ARC_DIR = ../

ARC = $(addprefix $(ARC_DIR), $(ARC_NAME))



all:
	$(MAKE) -C $(ARC_DIR) all
	@$(MAKE) $(EXES)

clean:
	$(MAKE) -C $(ARC_DIR) fclean
	rm -f $(EXES)

fclean:
	$(MAKE) -C $(ARC_DIR) clean
	@$(MAKE) clean
	rm -f $(EXES)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re



%.exe : $(MAINS_DIR)%.cpp
	$(COMPILER) $(FLAGS) -I ../include -I ../other -o $@ $^ $(ARC) E:/Utility/msys32/ucrt64/lib/libOpenCL.dll.a -lgdi32

$(ARC) :
	@$(MAKE) -C $(ARC_DIR) all


