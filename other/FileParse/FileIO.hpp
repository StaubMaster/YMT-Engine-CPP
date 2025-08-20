#ifndef FILE_IO_HPP
# define FILE_IO_HPP

# include <iostream>
# include <fstream>

class FileIO
{
	public:
		static std::string Read(const std::string & path);
};

#endif