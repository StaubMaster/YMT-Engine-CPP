
#ifndef  TIME_MEASIRE_HPP
# define TIME_MEASIRE_HPP

class TimeMeasure
{
	private:
		const int Limit = 1024;

		double * Memory;
		int Count;
		int Index;

		double TimeStamp;

	public:
		TimeMeasure();
		~TimeMeasure();

	public:
		void T0();
		void T1();
		double Average();
};

#endif
