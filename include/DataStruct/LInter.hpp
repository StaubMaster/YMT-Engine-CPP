
#ifndef  L_INTER_HPP
# define L_INTER_HPP

struct LInter
{
	private:
		float _T0;
		float _T1;

	public:
		LInter();
	private:
		LInter(float t0, float f1);

	public:
		static LInter T0();
		static LInter T1();

	public:
		float Calc(float val0, float val1);

	public:
		void SetT0(float val);
		void SetT1(float val);

		float GetT0();
		float GetT1();
};

#endif
