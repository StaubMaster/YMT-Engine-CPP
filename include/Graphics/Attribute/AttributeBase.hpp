
#ifndef  ATTRIBUTE_BASE_HPP
# define ATTRIBUTE_BASE_HPP

class AttributeBase
{
	public:
		AttributeBase();
		virtual ~AttributeBase();

	public:
		virtual void Bind(const unsigned char * & offset) const = 0;
};

#endif
