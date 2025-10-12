
#include "FileManager/FileContext.hpp"
#include "FileManager/FilePath.hpp"
#include "FileManager/FileInfo.hpp"
#include "FileManager/FileMode.hpp"
#include "FileManager/DirectoryContext.hpp"

#include <vector>
#include <iostream>



int main(int argc, char * argv [])
{
	//std::cout << "here\n";
	//DirectoryContext here = DirectoryContext::Here();
	//std::cout << "Path: " << here.DirPath << "\n";

	//std::cout << "\n";
	/*for (int i = 0; i < argc; i++)
	{
		std::string str(argv[i]);
		
		std::cout << "[" << i << "]" << str << "|" << "\n";

		DirectoryContext dir(str);
		std::cout << "Path:" << dir.DirPath << "\n";
		std::cout << "IsAbs: " << dir.IsAbsolute() << "\n";
		std::cout << "IsRel: " << dir.IsRelative() << "\n";
		std::cout << "\n";

		DirectoryContext dirA = dir.ToAbsolute();
		std::cout << "Path:" << dirA.DirPath << "\n";
		std::cout << "IsAbs: " << dirA.IsAbsolute() << "\n";
		std::cout << "IsRel: " << dirA.IsRelative() << "\n";
		std::cout << "\n";

		DirectoryContext dirR = dirA.ToRelative(here);
		std::cout << "Path:" << dirR.DirPath << "\n";
		std::cout << "IsAbs: " << dirR.IsAbsolute() << "\n";
		std::cout << "IsRel: " << dirR.IsRelative() << "\n";
		std::cout << "\n";
	}*/

	//FileContext file(argv[0]);
	//std::cout << "Valid: " << file.Info.Valid << "\n";
	//std::cout << "Mode: " << file.Info.Mode << "\n";
	//std::cout << "ID_U: " << file.Info.ID_User << "\n";
	//std::cout << "ID_G: " << file.Info.ID_Group << "\n";
	//std::cout << "ID_D: " << file.Info.ID_Device << "\n";
	//std::cout << "ID_S: " << file.Info.ID_Special << "\n";
	//std::cout << "Time Access: " << file.Info.TimeLastAccess << "\n";
	//std::cout << "Time Modify: " << file.Info.TimeLastModify << "\n";
	//std::cout << "Time Change: " << file.Info.TimeLastChange << "\n";
	//std::cout << "Size: " << file.Info.Size << "\n";

	FilePath here = FilePath::Here();
	std::cout << "Here:" << here << "\n";
	std::cout << "\n";

	std::string Path_Arr [] = {
		R"(E:\Programmieren\C++\YMT Engine\examples\file.exe)",
		R"(E:\Programmieren\C++\YMT Engine\examples\another\dir\file.exe)",
		R"(E:\Programmieren\C++\file.exe)",
	};
	int Path_Num = 3;

	for (int i = 0; i < Path_Num; i++)
	{
		std::cout << "Path: " << Path_Arr[i] << "\n";
		FilePath path(Path_Arr[i]);

		//std::cout << path.ToString() << "\n";
		//std::cout << "Abs|Rel: " << path.IsAbsolute() << "|" << path.IsRelative() << "\n";
		//std::cout << "\n";

		//std::cout << "Str : " << path.ToString() << "\n";
		//std::cout << "Abs : " << path.ToAbsolute().ToString() << "\n";
		//std::cout << "Rel : " << path.ToRelative(here).ToString() << "\n";

		FileContext file(path);
		std::cout << "Dir : " << file.Directory() << "\n";
		std::cout << "Name: " << file.Name() << "\n";
		std::cout << "Ext : " << file.Extension() << "\n";
		std::cout << "Prnt: " << file.Path.Parent().ToString() << "\n";
		std::cout << "Chld: " << file.Path.Child("file").ToString() << "\n";

		DirectoryContext dir(file.Directory());
		if (dir.Exists())
		{
			std::vector<DirectoryContext> dirs = dir.Directorys();
			for (unsigned int i = 0; i < dirs.size(); i++)
			{
				std::cout << dirs[i].Path << "\n";
			}

			std::vector<FileContext> files = dir.Files();
			for (unsigned int i = 0; i < files.size(); i++)
			{
				std::cout << files[i].Path << "\n";
			}
		}

		std::cout << "\n";
	}

	//FileContext file("Makefile");
	//std::cout << "\n################################################################\n";
	//std::cout << file.LoadText();
	//std::cout << "\n################################################################\n";

	(void)argc;
	(void)argv;
}
