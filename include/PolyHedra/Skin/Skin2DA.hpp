#ifndef  SKIN_2DA_HPP
# define SKIN_2DA_HPP

# include "PolyHedra/Skin/SkinGenericBase.hpp"
# include "PolyHedra/Skin/Skin2D_Data.hpp"
# include "Graphics/Texture/Texture2DArray.hpp"

# include "Miscellaneous/ContainerDynamic.hpp"

# include "DataStruct/Point2D.hpp"
# include "DataStruct/Point3D.hpp"

class Skin2DA : public SkinGenericBase<Skin2DCorner, Skin2DFaceCorner, Skin2DFace>
{
	public:
		unsigned int W;
		unsigned int H;

	public:
		Skin2DA();
		~Skin2DA();
	
	public:
		TextureBase * ToTexture() const override;

	public:
		void Parse(const ParsingCommand & cmd) override;
		void Parse_W(const ParsingCommand & cmd);
		void Parse_H(const ParsingCommand & cmd);
		void Parse_File(const ParsingCommand & cmd);
		void Parse_t(const ParsingCommand & cmd);
};

#endif
