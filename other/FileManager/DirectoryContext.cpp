
#include "DirectoryContext.hpp"
#include "FileContext.hpp"
#include <sys/stat.h>

DirectoryContext::DirectoryContext(std::string dir_path) :
	DirPath(dir_path) { }



bool DirectoryContext::Exists() const
{
	struct stat sb;
	return (stat(DirPath.c_str(), &sb) == 0 && (sb.st_mode & S_IFDIR) != 0);
}



FileContext DirectoryContext::File(std::string name) const
{
	return FileContext(DirPath + "/" + name);
}





DirectoryContext::Exception_DirectoryProblem::Exception_DirectoryProblem(const std::string & dir_path)
{
	Text = "DirectoryContext: Problem with Directory '" + dir_path + "'.";
}
const char * DirectoryContext::Exception_DirectoryProblem::what() const noexcept
{
	return Text.c_str();
}



DirectoryContext::Exception_DirectoryNotFound::Exception_DirectoryNotFound(const std::string & dir_path)
{
	Text = "DirectoryContext: Directory '" + dir_path + "' not found.";
}
const char * DirectoryContext::Exception_DirectoryNotFound::what() const noexcept
{
	return Text.c_str();
}
