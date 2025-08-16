#ifndef EDITABLE_ARRAY_HPP
# define EDITABLE_ARRAY_HPP

template<typename ItemType>
class EditableArray
{
	private:
		ItemType * Memory;
		unsigned int Count;
		unsigned int Length;

	public:
		EditableArray();
		~EditableArray();

	public:
		ItemType & operator[](unsigned int);

	public:
		unsigned int	Insert(const ItemType & item);
		ItemType		Remove(unsigned int idx);

	public:
		void Trim();
};

#endif