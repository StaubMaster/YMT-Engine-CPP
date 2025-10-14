


NAME = fileManager.a
COMPILER = c++ -std=c++11
FLAGS = -Wall -Wextra -Werror

FILES_CPP = \
	FilePath.cpp \
	FileInfo.cpp \
	FileMode.cpp \
	FileContext.cpp \
	DirectoryContext.cpp \
	\
	Format/Image.cpp \
	\
	Parsing/uint.cpp \
	Parsing/BitStream.cpp \
	Parsing/ByteStream.cpp \
	Parsing/LineCommand.cpp \
	Parsing/DebugManager.cpp

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

all:
	$(MAKE) $(FILES_O)
	ar -rcs $(NAME) $(FILES_O)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $^ -o $@

clean:
	rm -f $(FILES_O)

fclean:
	rm -f $(FILES_O)
	rm -f $(NAME)

re:	fclean all

.Phony: all clean fclean re
