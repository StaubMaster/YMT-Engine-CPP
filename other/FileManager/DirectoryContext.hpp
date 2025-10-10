
#ifndef  DIRECTORY_CONTEXT_HPP
# define DIRECTORY_CONTEXT_HPP

# include <string>
# include <exception>

class FileContext;

class DirectoryContext
{
	public:
		std::string DirPath;
	
	public:
		DirectoryContext(std::string dir_path);
		static DirectoryContext Here();

	public:
		bool Exists() const;
		//	check Permissions
		DirectoryContext Trim() const;	//	removes unneeded ./ and ../

		bool IsFile() const;		//	checks if this is actually a File that Exists
		FileContext ToFile() const;	//	Convert to FileContext
		
		bool IsAbsolute() const;
		bool IsRelative() const;
		DirectoryContext ToAbsolute() const;
		DirectoryContext ToRelative(const DirectoryContext & root) const;

		/*	Compate if 2 Directorys are the same ?
			make both Absolute, Trim and compare the string
			there might be a better way
		*/

		bool HasParent() const;
		bool HasChild(std::string name) const;
		DirectoryContext Parent() const;
		DirectoryContext Child(std::string name) const;

		FileContext * Files() const;			//	all Files in this Directory
		DirectoryContext * Directorys() const;	//	all Directorys in this Directory
		//	return a vector or other selfdeleting container instead ?

	public:
		FileContext File(std::string name) const;

	private:
		class Exception_DirectoryProblem : public std::exception
		{
			private: std::string Text;
			public: Exception_DirectoryProblem(const std::string & dir_path);
			public: const char * what() const noexcept;
		};
		class Exception_DirectoryNotFound : public std::exception
		{
			private: std::string Text;
			public: Exception_DirectoryNotFound(const std::string & dir_path);
			public: const char * what() const noexcept;
		};

};

#endif
