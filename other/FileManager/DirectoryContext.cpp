
#include "DirectoryContext.hpp"
#include "FileContext.hpp"

#include <sys/stat.h>
#include <unistd.h>
#include <cctype>

#include <iostream>
#include <sstream>
#include <vector>



DirectoryContext::DirectoryContext(std::string dir_path) :
	DirPath(dir_path) { }
DirectoryContext DirectoryContext::Here()
{
	char path[PATH_MAX];
	if (getwd(path) == NULL)
	{
		std::cout << "Error getting current Dir\n";
	}
	return DirectoryContext(std::string(path));
}



bool DirectoryContext::Exists() const
{
	struct stat sb;
	return (stat(DirPath.c_str(), &sb) == 0 && (sb.st_mode & S_IFDIR) != 0);
}



bool DirectoryContext::IsFile() const
{
	struct stat sb;
	return (stat(DirPath.c_str(), &sb) == 0 && (sb.st_mode & S_IFREG) != 0);
}
FileContext DirectoryContext::ToFile() const
{
	return FileContext(DirPath);
}



//	this is Different for Windows and Mac
#if defined(_WIN32)
//	Windows:	https://learn.microsoft.com/en-us/dotnet/standard/io/file-path-formats
bool DirectoryContext::IsAbsolute() const
{
	if (DirPath.size() < 3) { return false; }

	if (!std::isalpha(DirPath[0])) { return false; }
	if (DirPath[1] != ':') { return false; }
	if (DirPath[2] != '/' && DirPath[2] != '\\') { return false; }

	return true;
}
bool DirectoryContext::IsRelative() const
{
	return !IsAbsolute();
}
#endif

#if defined(__APPLE__)
bool DirectoryContext::IsAbsolute() const
{
	if (DirPath.size() < 1) { return false; }

	if (DirPath[0] != '/') { return false; }

	return true;
}
bool DirectoryContext::IsRelative() const
{
	return !IsAbsolute();
}
#endif
//	alternatively, get Here. compare if beginning is the same ?
//	but it might have ../ in it



DirectoryContext DirectoryContext::ToAbsolute() const
{
	if (IsAbsolute()) { return DirectoryContext(DirPath); }
	DirectoryContext here = Here();
	return DirectoryContext(here.DirPath + "/" + DirPath);
}

/*	ToRelative()
	dosent handle ./ and ../ for now

	this:	/Users/dgerold/test
	root:	/Users/dgerold/Desktop/self/YMT/examples
	return:	../../../../test

	this:	/Users/dgerold/Desktop/self/YMT/examples/another/dir/test
	root:	/Users/dgerold/Desktop/self/YMT/examples
	return:	another/dir/test
	return:	./another/dir/test	?

	some of the things being done here might be useful in other funcitons
	make a PathHelper thing ?
*/

DirectoryContext DirectoryContext::ToRelative(const DirectoryContext & root) const
{
	if (IsRelative())
	{
		return ToAbsolute().ToRelative(root);
	}

	//std::cout << "this: " << DirPath << "\n";
	//std::cout << "root: " << root.DirPath << "\n";

	std::vector<std::string> this_segments;
	{
		std::stringstream ss(DirPath);
		std::string segment;
		while (std::getline(ss, segment, '/'))
		{
			this_segments.push_back(segment);
		}
	}

	std::vector<std::string> root_segments;
	{
		std::stringstream ss(root.DirPath);
		std::string segment;
		while (std::getline(ss, segment, '/'))
		{
			root_segments.push_back(segment);
		}
	}

	//std::cout << "this | ";
	//for (size_t i = 0; i < this_segments.size(); i++) { std::cout << this_segments[i] << " | "; }
	//std::cout << "\n";

	//std::cout << "root | ";
	//for (size_t i = 0; i < root_segments.size(); i++) { std::cout << root_segments[i] << " | "; }
	//std::cout << "\n";

	size_t i;
	for (i = 0; i < this_segments.size() && i < root_segments.size(); i++)
	{
		if (this_segments[i] != root_segments[i])
		{
			break;
		}
	}

	std::string relPath;

	for (size_t j = i; j < root_segments.size(); j++)
	{
		relPath += "../";
	}

	for (size_t j = i; j < this_segments.size(); j++)
	{
		if (j != i) { relPath += "/"; }
		relPath += this_segments[j];
	}

	return DirectoryContext(relPath);
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
