
NAME = fileManager.a

FILES_CPP = \
	FileContext.cpp \
	DirectoryContext.cpp \
	Format/Image.cpp \
	\
	Parsing/DebugManager.cpp \
	Parsing/uint.cpp \
	Parsing/BitStream.cpp \
	Parsing/DataStream.cpp

FILES_PNG_CPP = \
	Format/PNG/Chunk.cpp \
	Format/PNG/ZLIB.cpp \
	Format/PNG/Huffman.cpp \
	Format/PNG/DEFLATE.cpp \
	Format/PNG/PNG_Filter.cpp \
	Format/PNG/PNG_IHDR.cpp \
	Format/PNG/PNG.cpp

FILES_O = $(FILES_CPP:.cpp=.o)
FILES_O += $(FILES_PNG_CPP:.cpp=.o)

Flags = -Wall -Wextra -Werror

all:
	$(MAKE) $(FILES_O)
	ar -rcs $(NAME) $(FILES_O)

%.o: %.cpp
	c++ $(Flags) -c $^ -o $@

clean:
	rm -f $(FILES_O)

fclean:
	rm -f $(FILES_O)
	rm -f $(NAME)

re:	fclean all

.Phony: all clean fclean re
