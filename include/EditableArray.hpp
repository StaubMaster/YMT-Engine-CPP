#ifndef EDITABLE_ARRAY_HPP
# define EDITABLE_ARRAY_HPP

# include <iostream>

template <typename ItemType> class EditableArray
{
	public:
		unsigned int Length;
	private:
		ItemType * Memory;
		unsigned int Limit;

	public:
		EditableArray()
		{
			Length = 0;
			Memory = new ItemType[0];
			Limit = 0;
		}
		~EditableArray()
		{
			delete [] Memory;
		}

	public:
		ItemType & operator[](unsigned int idx)
		{
			return Memory[idx];
		}

	public:
		unsigned int	Insert(const ItemType & item)
		{
			if (Length == Limit)
			{
				unsigned int limit;
				if (Limit == 0) { limit = 1; }
				else { limit = Limit * 2; }
			
				ItemType * mem  = new ItemType[limit];
				for (unsigned int i = 0; i < Limit; i++)
				{
					mem[i] = Memory[i];
				}
			
				delete [] Memory;
				Memory = mem;
				Limit = limit;
			}
		
			int idx = Length;
			Memory[Length] = item;
			Length++;
			return idx;
		}
		ItemType		Remove(unsigned int idx)
		{
			ItemType item = Memory[idx];
			for (unsigned int i = idx + 1; idx < Length; i++)
			{
				Memory[idx - 1] = Memory[idx];
			}
			return item;
		}

	public:
		void Trim()
		{

		}
};

#endif