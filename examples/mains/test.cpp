
#include "FileManager/DirectoryContext.hpp"

#include <iostream>



int main(int argc, char * argv [])
{
	std::cout << "here\n";
	DirectoryContext here = DirectoryContext::Here();
	std::cout << "Path: " << here.DirPath << "\n";

	std::cout << "\n";
	for (int i = 0; i < argc; i++)
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
	}
}
