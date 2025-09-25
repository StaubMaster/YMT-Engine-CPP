#ifndef POS_COL_BUFFER
# define POS_COL_BUFFER

# include "Graphics/BaseBuffer.hpp"
# include "Graphics/Buffer/PolyHedra_MainData.hpp"

# include "Abstract2D/Point2D.hpp"
# include "Abstract3D/Point3D.hpp"
# include "Abstract3D/Undex3D.hpp"



class PolyHedraBuffer : public BaseBuffer
{
	private:
		unsigned int & MainID;
		unsigned int Count;

	public:
		PolyHedraBuffer();
		~PolyHedraBuffer();

	public:
		void Data(int count, const PolyHedra_MainData * data);

		void Draw();
};

#endif