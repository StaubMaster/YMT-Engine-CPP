#ifndef  SKIN_BASE_HPP
# define SKIN_BASE_HPP

# include "Miscellaneous/ContainerDynamic.hpp"
//# include "Texture/TextureBase.hpp"

# include "Parsing/ParsingCommand.hpp"

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
		struct ParsingEnvironmentData : public ParsingCommand::EnvironmentData
		{
			SkinBase * Skin;
			ParsingEnvironmentData(const FileContext & file);
			void Parse(const ParsingCommand & cmd) override;

			void Parse_Type(const ParsingCommand & cmd);
			void Parse_Format(const ParsingCommand & cmd);
		};
	public:
		virtual void Parse(const ParsingCommand & cmd) = 0;
	public:
		static SkinBase * Load(const FileContext & file);
};

#endif
