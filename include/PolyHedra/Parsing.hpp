#ifndef  POLYHEDRA_PARSING_HPP
# define POLYHEDRA_PARSING_HPP

# include "PolyHedra/PolyHedra.hpp"
# include "Parsing/ParsingCommand.hpp"

# include <string>
# include <exception>

class FileContext;

namespace YMT
{
struct PolyHedra::ParsingData : public ParsingCommand::EnvironmentData
{
	//	Line
	//	have ParsingCommand here instead of as Parameter
	//	have the full Line String here

	PolyHedra *				PH;
	PolyHedra::Template *	Data;
	unsigned int	CornerOffset;
	unsigned int	FaceOffset;

	ParsingData(const FileContext & file);
	~ParsingData();

	void Parse(const ParsingCommand & cmd) override;

	void Parse_Type(const ParsingCommand & cmd);
	void Parse_Format(const ParsingCommand & cmd);
	void Parse_Skin(const ParsingCommand & cmd);

	void Parse_Corner(const ParsingCommand & cmd);
	void Parse_Face(const ParsingCommand & cmd);

	void Parse_Offset(const ParsingCommand & cmd);
	void Parse_Belt(const ParsingCommand & cmd, bool direction, bool closure);
	void Parse_Band(const ParsingCommand & cmd, bool direction, bool closure);
	void Parse_Fan(const ParsingCommand & cmd, bool direction, bool closure);
	void Parse_CircleOLD(const ParsingCommand & cmd);
	void Parse_Circle(const ParsingCommand & cmd, bool direction);
};
};

#endif
