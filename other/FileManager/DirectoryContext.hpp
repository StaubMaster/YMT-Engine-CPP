
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

	public:
		bool Exists() const;

	public:
		FileContext File(std::string name);

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
