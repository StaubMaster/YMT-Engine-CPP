
#ifndef  DEPTH_FACTORS_HPP
# define DEPTH_FACTORS_HPP

struct DepthFactors
{
	private:
		float Near;
		float Far;

		float Diff;
		float Summ;
		float Mul2;

		float Factor0;
		float Factor1;

	public:
		DepthFactors();
		DepthFactors(float near, float far);

	private:
		void Calc();
	public:
		void ChangeNear(float near);
		void ChangeFar(float far);
};

#endif
