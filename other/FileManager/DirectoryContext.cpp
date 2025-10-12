
#include "DirectoryContext.hpp"
#include "FileContext.hpp"

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <cctype>

#include <iostream>



DirectoryContext::DirectoryContext() :
	Path(""),
	Info("")
{ }
DirectoryContext::DirectoryContext(std::string path) :
	Path(path),
	Info(path)
{ }
DirectoryContext::DirectoryContext(FilePath path) :
	Path(path),
	Info(path.ToString())
{ }



DirectoryContext::DirectoryContext(const DirectoryContext & other) :
	Path(other.Path),
	Info(Path.ToString())
{ }
DirectoryContext & DirectoryContext::operator =(const DirectoryContext & other)
{
	Path = other.Path;
	Info = FileInfo(Path.ToString());
	return *this;
}



DirectoryContext DirectoryContext::Here()
{
	return DirectoryContext(FilePath::Here());
}



bool DirectoryContext::Exists() const
{
	return (Info.Valid && Info.Mode.IsDirectory());
}

bool DirectoryContext::IsFile() const
{
	return (Info.Valid && Info.Mode.IsFile());
}
FileContext DirectoryContext::ToFile() const
{
	return FileContext(Path);
}



std::vector<FilePath> DirectoryContext::Children() const
{
	DIR * dir = opendir(Path.ToString().c_str());
	if (dir == NULL)
	{
		std::cout << "DirectoryContext: Error: opendir\n";
	}

	std::vector<FilePath> children;

	struct dirent * ent;
	ent = readdir(dir);
	while (ent != NULL)
	{
		children.push_back(FilePath(std::string(ent -> d_name)));
		ent = readdir(dir);
	}

	if (closedir(dir) != 0)
	{
		std::cout << "DirectoryContext: Error: closedir\n";
	}
	return children;
}
std::vector<FileContext> DirectoryContext::Files() const
{
	std::vector<FilePath> paths = Children();

	std::vector<FileContext> files;

	for (size_t i = 0; i < paths.size(); i++)
	{
		FileInfo info(paths[i].ToString());
		if (info.Mode.IsFile())
		{
			files.push_back(FileContext(paths[i]));
		}
	}

	return files;
}
std::vector<DirectoryContext> DirectoryContext::Directorys() const
{
	std::vector<FilePath> paths = Children();

	std::vector<DirectoryContext> dirs;

	for (size_t i = 0; i < paths.size(); i++)
	{
		FileInfo info(paths[i].ToString());
		if (info.Mode.IsDirectory())
		{
			dirs.push_back(DirectoryContext(paths[i]));
		}
	}

	return dirs;
}



bool DirectoryContext::HasFile(std::string name) const
{
	FileInfo info(Path.Child(name).ToString());
	return (info.Valid && info.Mode.IsFile());
}
FileContext DirectoryContext::File(std::string name) const
{
	return FileContext(Path.Child(name));
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
