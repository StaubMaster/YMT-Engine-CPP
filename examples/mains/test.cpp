
#include "FileManager/FileContext.hpp"
#include "FileManager/FilePath.hpp"
#include "FileManager/FileInfo.hpp"
#include "FileManager/FileMode.hpp"
#include "FileManager/DirectoryContext.hpp"

#include "FileManager/Parsing/uint.hpp"

#include <vector>
#include <iostream>



void FileDirContextPathInfoMode_Stuff(int argc, char * argv [])
{
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

	(void)argc;
	(void)argv;
}

uint8 Random8()
{
	return std::rand();
}
uint16 Random16()
{
	short n0 = std::rand();
	short n1 = std::rand();
	return (n0 << 0) ^ (n1 << 1);
}
uint32 Random32()
{
	uint32 n0 = Random16();
	uint32 n1 = Random16();
	return (n0 << 0) ^ (n1 << 16);
}
uint64 Random64()
{
	uint64 n0 = Random32();
	uint64 n1 = Random32();
	return (n0 << 0) ^ (n1 << 32);
}

void UIntTest()
{
	for (int i = 0; i < 64; i++)
	{
		//uint8 n = Random8();
		//uint16 n = Random16();
		//uint32 n = Random32();
		uint64 n = Random64();

		//std::cout << "Bit: " << uint_Bit(n8) << " " << uint_Bit(n16) << " " << uint_Bit(n32) << " " << uint_Bit(n64) << "\n";

		std::cout << "Bit: " << ToBase2(n) << "\n";
		std::cout << "Bit: " << ToBase2(n, ' ') << "\n";
		std::cout << "Hex: " << ToBase16(n) << "\n";
		std::cout << "Hex: " << ToBase16(n, ' ') << "\n";
	}
}

int main(int argc, char * argv [])
{
	//FileDirContextPathInfoMode_Stuff(argc, argv);
	UIntTest();

	(void)argc;
	(void)argv;
}
