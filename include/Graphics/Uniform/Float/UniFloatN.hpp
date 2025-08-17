#ifndef UNI_FLOAT_N_HPP
# define UNI_FLOAT_N_HPP

# include "../UniBase.hpp"

class UniFloatN : public UniBase
{
	protected:
		int Count;
		int Size;
		const float * UpdateData;

	protected:
		UniFloatN(const BaseShader * program, const std::string & name, int count, int len);
		virtual ~UniFloatN();

	public:
		void Update();

	public:
		virtual void Set(const float * data) = 0;
};

#endif