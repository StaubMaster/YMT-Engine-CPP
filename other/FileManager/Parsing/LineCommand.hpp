
#include <string>

#include <vector>
#include <sstream>

#include <iostream>

#include "../FileContext.hpp"

class LineCommand
{
	public:
		std::vector<std::string> Args;
	public:
		LineCommand(std::string text);



	public:
template <typename ObjectType>
static void Split(const FileContext & file, ObjectType & object, void (ObjectType::*func)(const LineCommand &))
{
	std::stringstream stream(file.LoadText());
	std::string segment;
	while (std::getline(stream, segment, '\n'))
	{
		(object.*func)(LineCommand(segment));
	}
}



};
