#ifndef POLYHEDRA_INST_BUFFER
# define POLYHEDRA_INST_BUFFER

# include "Graphics/BaseBuffer.hpp"
# include "Graphics/Buffer/PolyHedra_MainData.hpp"

# include "Abstract2D/Point2D.hpp"
# include "Abstract3D/Point3D.hpp"
# include "Abstract3D/Undex3D.hpp"
# include "Abstract3D/Transformation3D.hpp"

# include "PolyHedraData.hpp"

class YMT::PolyHedra::BufferInst : public BaseBuffer
{
	private:
		unsigned int & MainID;
		unsigned int & InstID;
		unsigned int MainCount;
		unsigned int InstCount;

	public:
		BufferInst();
		~BufferInst();

	public:
		void DataPolyHedra(int count, const PolyHedra_MainData * data);
		void DataTrans(int count, const Transformation3D * data);
		void Draw();
};

#endif