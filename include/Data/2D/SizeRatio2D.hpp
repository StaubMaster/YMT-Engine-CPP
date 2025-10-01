
#ifndef  SIZE_RATIO_2D_HPP
# define SIZE_RATIO_2D_HPP

struct SizeRatio2D
{
	public:
		float W;
		float H;
		float RatioW;
		float RatioH;

	public:
		SizeRatio2D();
		SizeRatio2D(float w, float h);

	private:
		void Calc();
};

#endif
