
#include "FileContext.hpp"

#include "Format/Image.hpp"
#include "Format/PNG/PNG.hpp"

#include <sys/stat.h>
#include <fstream>



FileContext::FileContext(std::string file_path) :
	FilePath(file_path) { }



bool FileContext::Exists() const
{
	struct stat sb;
	return (stat(FilePath.c_str(), &sb) == 0 && (sb.st_mode & S_IFREG) != 0);
}
std::string FileContext::Path() const
{
	//	everything before last /
	//	or everything if non is found
	//	including /
	return "";
}
std::string FileContext::Name() const
{
	//	everything after last /
	//	or everything if non is found
	//	including /
	//	shouldn't happen
	return "";
}
std::string FileContext::Extension() const
{
	size_t idx = FilePath.find_last_of('.');
	if (idx != std::string::npos)
	{
		return FilePath.substr(idx);
	}
	return "";
}



std::string FileContext::LoadText() const
{
	std::ifstream file(FilePath, std::ios::binary);
	if (!file.is_open())
	{
		throw Exception_FileProblem(FilePath);
	}

	std::string file_text;
	char	binary_block[1024];

	file.read(binary_block, 1024);
	while (!file.eof())
	{
		file_text += std::string(binary_block, 1024);
		file.read(binary_block, 1024);
	}
	file_text += std::string(binary_block, file.gcount());

	return (file_text);
}
void FileContext::SaveText(std::string text) const
{
	(void)text;
}



Image * FileContext::LoadImagePNG() const
{
	return PNG::Load(*this);
}





FileContext::Exception_FileProblem::Exception_FileProblem(const std::string & file_path)
{
	Text = "FileContext: Problem with File '" + file_path + "'.";
}
const char * FileContext::Exception_FileProblem::what() const noexcept
{
	return Text.c_str();
}



FileContext::Exception_FileNotFound::Exception_FileNotFound(const std::string & file_path)
{
	Text = "FileContext: File '" + file_path + "' not found.";
}
const char * FileContext::Exception_FileNotFound::what() const noexcept
{
	return Text.c_str();
}
