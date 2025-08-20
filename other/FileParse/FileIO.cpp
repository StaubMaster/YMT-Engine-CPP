#include "FileIO.hpp"



std::string FileIO::Read(const std::string & path)
{
	std::ifstream file(path, std::ios::binary);
	if (!file.is_open())
	{
		std::cout << "FileIO: Bad File\n";
		return "";
	}

	std::string file_data;
	char	binary_block[1024];

	file.read(binary_block, 1024);
	while (!file.eof())
	{
		file_data += std::string(binary_block, 1024);
		file.read(binary_block, 1024);
	}
	file_data += std::string(binary_block, file.gcount());

	return (file_data);
}
