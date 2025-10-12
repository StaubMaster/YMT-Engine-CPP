#include "FileInfo.hpp"
#include "FileMode.hpp"

#include <iostream>



bool stat_default(struct stat * info)
{
	(void)info;
	return false;
}
bool stat_copy(bool valid, const struct stat * other, struct stat * info)
{
	*info = *other;
	return valid;
}

FileInfo::FileInfo() :
	Valid(stat_default(&info)),
	Mode(info.st_mode),
	ID_User(info.st_uid),
	ID_Group(info.st_gid),
	ID_Device(info.st_dev),
	ID_Special(info.st_rdev),
	TimeLastAccess(info.st_atime),
	TimeLastModify(info.st_mtime),
	TimeLastChange(info.st_ctime),
	Size(info.st_size)
{ }
FileInfo::FileInfo(std::string path) :
	Valid(stat(path.c_str(), &info) == 0),
	Mode(info.st_mode),
	ID_User(info.st_uid),
	ID_Group(info.st_gid),
	ID_Device(info.st_dev),
	ID_Special(info.st_rdev),
	TimeLastAccess(info.st_atime),
	TimeLastModify(info.st_mtime),
	TimeLastChange(info.st_ctime),
	Size(info.st_size)
{ }



FileInfo::FileInfo(const FileInfo & other) :
	Valid(stat_copy(other.Valid, &(other.info), &info)),
	Mode(info.st_mode),
	ID_User(info.st_uid),
	ID_Group(info.st_gid),
	ID_Device(info.st_dev),
	ID_Special(info.st_rdev),
	TimeLastAccess(info.st_atime),
	TimeLastModify(info.st_mtime),
	TimeLastChange(info.st_ctime),
	Size(info.st_size),
	info(other.info)
{ }
FileInfo & FileInfo::operator = (const FileInfo & other)
{
	Valid = other.Valid;
	info = other.info;
	return *this;
}


