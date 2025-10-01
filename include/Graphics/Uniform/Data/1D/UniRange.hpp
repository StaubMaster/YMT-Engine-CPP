
#ifndef  UNI_RANGE_HPP
# define UNI_RANGE_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Uniform/Base/GenericMultiformBase.hpp"

# include "DataDec.hpp"

class BaseShader;

class UniRange : public GenericUniformBase<Range>
{
	private:
		int LocationMin;
		int LocationLen;
		int LocationMax;

	public:
		UniRange(std::string name, BaseShader & shader);

	public:
		void PutData(Range val) override;
};

# include "DataStruct/Range.hpp"

class MultiRange : public GenericMultiformBase<UniRange, Range>
{
	public:
		MultiRange(std::string name);
};

#endif
