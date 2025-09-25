
#ifndef ENTRY_CONTAINER_DYNAMIC_HPP
# define ENTRY_CONTAINER_DYNAMIC_HPP

# include "EntryContainerBase.hpp"
# include <iostream>

/*
	has a Dynamic size similar to a vector
	is fully packed
	so there is no space between Entrys
	there might be space after the Entrys
	but Length denotes the end of Entry space and the start of empty space
*/

template<typename T>
class EntryContainerDynamic : public EntryContainerBase<T>
{
	public:
		int Length;

	public:
		EntryContainerDynamic() : EntryContainerBase<T>(0)
		{
			Length = 0;
			std::cout << "++++ EntryContainerDynamic\n";
		}
		virtual ~EntryContainerDynamic()
		{
			std::cout << "---- EntryContainerDynamic\n";
		}

	private:
		void CopyNewSize(int limit)
		{
			T * data = new T[limit];

			for (int i = 0; i < Length; i++)
			{
				data[i] = this -> Data[i];
			}

			delete [] (this -> Data);
			this -> Data = data;
			this -> Size = limit;
		}
		void Grow(int size)
		{
			std::cout << "Grow() " << Length << " + " << size << " > " << (this -> Size) << " ?\n";
			if (Length + size > this -> Size)
			{
				CopyNewSize(Length + size);
			}
		}
	public:
		void Trim()
		{
			CopyNewSize(Length);
		}

	protected:
		void RemapEntrys() override
		{
			int offset = 0;
			for (int i = 0; i < (int)(this -> EntryRefs.size()); i++)
			{
				this -> EntryRefs[i].Offset = offset;
				offset += this -> EntryRefs[i].Length;
				this -> EntryRefs[i].EntryIndex = i;
			}
		}

		void FreeEntry(int idx) override
		{
			if (idx < 0 && idx >= (int)(this -> EntryRefs.size()))
			{
				std::cout << "EntryContainer: Index " << idx << " out of Range.";
				return;
			}
			this -> Changed = true;

			typename EntryContainerBase<T>::Entry & entry = (this -> EntryRefs[idx]);
			int off0 = entry.Offset;
			int off1 = entry.Length + off0;
			this -> EntryRefs.erase(this -> EntryRefs.begin() + idx);

			RemapEntrys();

			while (off1 < Length)
			{
				this -> Data[off0] = this -> Data[off1];
				off0++;
				off1++;
			}
			this -> Size = off0;
		}
	public:
		typename EntryContainerBase<T>::Entry * Alloc(int size) override
		{
			Grow(size);
			typename EntryContainerBase<T>::Entry * entry = this -> AllocEntry(Length, size);
			Length += size;
			return entry;
		}





	private:
		static void TestShowIndexe(EntryContainerBase<int>::Entry ** entrys, int count)
		{
			std::cout << "Indexe: " << count << "\n";
			for (int i = 0; i < count; i++)
			{
				std::cout << "[" << i << "]" << entrys[i] -> EntryIndex << "\n";
			}
		}
		static void TestShowData(EntryContainerDynamic<T> * container)
		{
			std::cout << "Data: " << (container -> Length) << "\n";
			for (int i = 0; i < container -> Length; i++)
			{
				std::cout << "[" << i << "]" << container -> Data[i] << "\n";
			}
		}
	public:
		static void Test()
		{
			std::cout << "EntryContainerDynamic<> Test >>>>\n";

			EntryContainerDynamic<int> * container = new EntryContainerDynamic<int>();

			EntryContainerBase<int>::Entry ** entry = new EntryContainerBase<int>::Entry *[5];
			entry[0] = container -> Alloc(2);
			entry[1] = container -> Alloc(1);
			entry[2] = container -> Alloc(3);
			entry[3] = container -> Alloc(1);
			entry[4] = container -> Alloc(3);

			TestShowIndexe(entry, 5);
 
			TestShowData(container);

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < entry[i] -> Length; j++)
				{
					(*entry[i])[j] = (i * 10 + j);
				}
			}

			TestShowData(container);

			std::cout << "Dispose 1\n";
			entry[1] -> Dispose();

			TestShowData(container);
			TestShowIndexe(entry, 5);

			std::cout << "Dispose 2\n";
			entry[2] -> Dispose();

			TestShowData(container);
			TestShowIndexe(entry, 5);

			std::cout << "New\n";
			entry[1] = container -> Alloc(2);

			TestShowData(container);
			TestShowIndexe(entry, 5);

			for (int i = 0; i < 5; i++)
			{
				//delete entry[i];
			}
			delete [] entry;
			delete container;
			std::cout << "EntryContainerDynamic<> Test <<<<\n";
		}
};

#endif
