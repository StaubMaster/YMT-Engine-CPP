#include "Debug.hpp"
#include "FileContext.hpp"
#include "DirectoryContext.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <vector>



std::string Debug::TimeStamp()
{
	//	[YYYY:MM:DD hh.mm.ss]
	//	[YYYY-MM-DD hh-mm-ss]
	//	[YYYY-DDD hh-mm-ss]

	std::time_t now_t = std::time(NULL);
	std::tm * now = std::localtime(&now_t);

	std::stringstream ss;
	ss << std::setfill('0');
	ss << "[ ";
	ss << std::setw(4) << ((now -> tm_year) + 1900) << "-";
	ss << std::setw(2) << ((now -> tm_mon) + 1) << "-";
	ss << std::setw(2) << ((now -> tm_mday)) << " ";
	ss << std::setw(2) << ((now -> tm_hour)) << "-";
	ss << std::setw(2) << ((now -> tm_min)) << "-";
	ss << std::setw(2) << ((now -> tm_sec));
	ss << " ]";

	return ss.str();
}



std::ostream & operator <<(std::ostream & log, Debug::LogChange & type)
{
	if (type == Debug::Done)
	{
		std::string timestamp = Debug::TimeStamp();

		std::vector<std::string> lines;
		{
			std::stringstream ss(Debug::Log.str());
			std::string line;
			while (std::getline(ss, line, '\n'))
			{
				lines.push_back(line);
			}
		}
		Debug::Log = std::ostringstream();

		std::string padding = std::string(timestamp.length(), ' ');
		for (size_t i = 0; i < lines.size(); i++)
		{
			if (i == 0)
			{ Debug::LogFile << timestamp; }
			else
			{ Debug::LogFile << padding; }
			Debug::LogFile << " ";
			Debug::LogFile << lines[i];
			Debug::LogFile << "\n";
		}
		Debug::LogFile.flush();
		return Debug::Log;
	}
	return log;
}



Debug::LogChange Debug::Done = '\x04';
std::ostringstream Debug::Log;
std::ofstream Debug::LogFile;



void Debug::NewFileInDir(const DirectoryContext & dir)
{
	if (Debug::LogFile.is_open())
	{
		Debug::LogFile.close();
	}
	Debug::Log = std::ostringstream();

	std::string timestamp = TimeStamp();
	FileContext file(dir.File(timestamp + ".log"));

	Debug::LogFile.open(file.Path.ToString(), std::ofstream::out | std::ofstream::trunc); //std::ofstream::app ?
	Debug::LogFile << "New Log File " << TimeStamp() << "\n";
}
