
#ifndef  FILE_INFO_HPP
# define FILE_INFO_HPP

#include "FileMode.hpp"

#include <sys/stat.h>

#include <string>

class FileInfo
{
	public:
		bool Valid;
		FileMode Mode;

		const short & ID_User;
		const short & ID_Group;
		const unsigned int & ID_Device;
		const unsigned int & ID_Special;

		const long long & TimeLastAccess;
		const long long & TimeLastModify;
		const long long & TimeLastChange;

		const long & Size;

	private:
		struct stat info;

	public:
		FileInfo();
		FileInfo(std::string path);

		FileInfo(const FileInfo & other);
		FileInfo & operator = (const FileInfo & other);
};

#endif
