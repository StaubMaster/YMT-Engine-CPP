
#ifndef  CONTAINER_DYNAMIC_HPP
# define CONTAINER_DYNAMIC_HPP

# include <exception>
# include <iostream>

/* I created this because vector dosent have a few things that I would like to have
	Remove a epecific Index can be done but is ugly
	Trimming is C++11, which I use but still

*/

template <typename ItemType>
class ContainerDynamic
{
	public:
		//enum MemoryGrowType
		//{
		//	GrowFixed,	//	dont change Size when Inserting
		//	GrowFit,	//	increase memory by how much is needed
		//	GrowDouble,	//	double current Memory
		//};
		//enum MemoryTrimType
		//{
		//	TrimFixed,	//	dont change Size when Removing
		//	TrimFit,	//	decrease Memory by how much is needed
		//	TrimLeave,	//	dont decease Memory
		//};

	private:
		class Exception_OutOfRange : public std::exception { const char * what() const noexcept { return "Index was out of Range."; } };

	private:
		unsigned int Limit;
		ItemType * Memory;
		unsigned int _Count;

	public:
		ContainerDynamic()
		{
			Limit = 0;
			Memory = new ItemType[0];
			_Count = 0;
		}
		~ContainerDynamic()
		{
			delete [] Memory;
		}

	public:
		unsigned int Count() const
		{
			return _Count;
		}
		ItemType * ToPointer() const
		{
			return Memory;
		}

	public:
		ItemType & operator [] (unsigned int udx)
		{
			if (udx >= _Count) { throw Exception_OutOfRange(); }
			return Memory[udx];
		}

	private:
		static unsigned int BinarySize(unsigned int size)
		{
			for (unsigned char shift = 31; shift < 32; shift--)
			{
				unsigned int new_size = 0xFFFFFFFF >> shift;
				if (new_size >= size)
				{
					return new_size;
				}
			}
			return 0;
		}
		void NewSize(unsigned int limit)
		{
			unsigned int count = _Count;
			if (limit < _Count) { count = limit; }

			ItemType * memory = new ItemType[limit];
			for (unsigned int i = 0; i < count; i++)
			{
				memory[i] = Memory[i];
			}
			delete [] Memory;

			_Count = count;
			Limit = limit;
			Memory = memory;
		}
	public:
		void Trim()
		{
			if (_Count < Limit)
			{
				NewSize(_Count);
			}
		}

	public:
		unsigned int	Insert(ItemType item)
		{
			if (_Count + 1 >= Limit)
			{
				NewSize(BinarySize(_Count + 1));
			}

			unsigned int udx = _Count;
			Memory[_Count] = item;
			_Count++;
			return udx;
		}
		ItemType		Remove(unsigned int udx)
		{
			ItemType item = Memory[udx];
			for (unsigned int i = udx + 1; i < Count; i++)
			{
				Memory[udx - 1] = Memory[udx];
			}
			_Count--;
			return item;
		}
};

#endif
