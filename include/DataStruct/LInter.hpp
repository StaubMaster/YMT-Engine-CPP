
#ifndef  L_INTER_HPP
# define L_INTER_HPP

struct LInter
{
	private:
		float _T0;
		float _T1;

	private:
		LInter();
		LInter(float t0, float f1);

	public:
		static LInter T0();
		static LInter T1();

	public:
		float Calc(float val0, float val1);
};

#endif
