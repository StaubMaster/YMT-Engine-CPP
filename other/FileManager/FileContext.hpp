
#ifndef  FILE_CONTEXT_HPP
# define FILE_CONTEXT_HPP

# include <string>
# include <exception>

class Image;

class DirectoryContext;

class FileContext
{
	public:
		std::string FilePath;

	public:
		FileContext(std::string file_path);

	public:
		bool Exists() const;
		//	check Permissions

		bool IsDirectory() const;				//	check if Path is actually a Directory that exists
		DirectoryContext ToDirectory() const;	//	Convert to DirectoryContext

		bool IsAbsolute() const;
		bool IsRelative() const;
		FileContext ToAbsolute() const;
		FileContext ToRelative(const DirectoryContext & root) const;

		std::string Path() const;
		std::string Name() const;
		std::string Extension() const;

	public:
		std::string LoadText() const;
		void SaveText(std::string text) const;

		Image * LoadImagePNG() const;

	private:
		class Exception_FileProblem : public std::exception
		{
			private: std::string Text;
			public: Exception_FileProblem(const std::string & file_path);
			public: const char * what() const noexcept;
		};
		class Exception_FileNotFound : public std::exception
		{
			private: std::string Text;
			public: Exception_FileNotFound(const std::string & file_path);
			public: const char * what() const noexcept;
		};
};

#endif
