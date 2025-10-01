
#ifndef  RANGE_HPP
# define RANGE_HPP

struct Range
{
	public:
		float Min;
		float Len;
		float Max;

	public:
		Range();
		Range(float min, float max);

	public:
		void ChangeMin(float min);
		void ChangeMax(float max);
};

#endif
