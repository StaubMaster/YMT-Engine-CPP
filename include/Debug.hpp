
#ifndef  DEBUG_LOG_HPP
# define DEBUG_LOG_HPP

# include <iosfwd>
# include <fstream>

class FileContext;
class DirectoryContext;

namespace Debug
{
/*
	<< appends to a temporary stringstream
	at the end of Message, append 0x04 (End of Transmission)
	after that, add extra info stuff to Message
		like timestamp and type
	then output Message to file and clear temporary stream
	how to do additional info ?
	just set with functions
	then clear at end of message
*/

/*	Multithreading
	have a seperate stream for each thread
	at beginning to thread, generate a temporary stream for that thread
	do that when we get there
*/

	std::string TimeStamp();

	typedef char LogChange;

	extern LogChange Done;

	extern std::ostringstream Log;
	extern std::ofstream LogFile;

	/*
		seperate for LogFile and other stuff
		maybe LogDebug, LogError, LogInfo
		all that stuff from the C# ConsoleLog
		but those include adding stuff to the stream
		how would I do that ?

		Log should also add TimeStamp
		so I need to intercept the output anyway ?

		how to handle MultiLine output
		out Timestamp on first Line
		and Pad rest

		would this be better on a seperate thread ?
		so the handling dosent slow down the main thread ?
	*/

	void NewFileInDir(const DirectoryContext & dir);
};

std::ostream & operator <<(std::ostream & log, Debug::LogChange & type);

#endif
