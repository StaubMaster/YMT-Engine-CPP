#include "LineCommand.hpp"



LineCommand::LineCommand(std::string text)
{
	std::stringstream stream(text);
	std::string segment;
	while (std::getline(stream, segment, ' '))
	{
		Args.push_back(segment);
	}
}
