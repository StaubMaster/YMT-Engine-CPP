#ifndef  SKIN_BASE_HPP
# define SKIN_BASE_HPP

# include "Miscellaneous/ContainerDynamic.hpp"
//# include "Texture/TextureBase.hpp"

namespace YMT
{
	class PolyHedra;
};

class TextureBase;

class Image;
class FileContext;
class LineCommand;

class SkinBase
{
	public:
		ContainerDynamic<Image *> Images;
		const FileContext * File;

	public:
		SkinBase();
		virtual ~SkinBase();

	public:
		virtual void Done() = 0;

		virtual TextureBase * ToTexture() const = 0;

	public:
		struct ParsingEnvironmentData
		{
			const FileContext & File;
			SkinBase * Skin;

			ParsingEnvironmentData(const FileContext & file);

			void Parse_Type(const LineCommand & cmd);
			void Parse_Format(const LineCommand & cmd);
			void Parse(const LineCommand & cmd);
		};
	public:
		virtual void Parse(const LineCommand & cmd) = 0;
	public:
		static SkinBase * Load(const FileContext & file);
};

#endif
