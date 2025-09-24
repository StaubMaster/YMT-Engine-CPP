
#ifndef ENTRY_CONTAINER_BASE_HPP
# define ENTRY_CONTAINER_BASE_HPP

# include <vector>
# include <iostream>

/*
	EntryContainer holds any data
	instead of adding something
	you instead get an Entry in the Container
		it has a fixes size
		when an entry the others might get moved around
		so pointers cant be used here
		the Entry has an Indexer that is used to change things in the main Container
*/

template <typename T>
class EntryContainerBase
{
	public:
		class Entry
		{
			private:
				EntryContainerBase<T> * Container;
			public:
				int EntryIndex;

			public:
				int Offset;
				int Length;

			public:
				Entry()
				{
					Container = NULL;
					EntryIndex = -1;

					Offset = 0;
					Length = 0;

					std::cout << "++++ Entry()\n";
				}
				Entry(const Entry & other)
				{
					Container = other.Container;
					EntryIndex = other.EntryIndex;

					Offset = other.Offset;
					Length = other.Length;

					std::cout << "++++ Entry(other)\n";
				}
				Entry(EntryContainerBase<T> * container, int entry_idx, int off, int len)
				{
					Container = container;
					EntryIndex = entry_idx;

					Offset = off;
					Length = len;

					std::cout << "++++ Entry(container)\n";
				}
				virtual ~Entry()
				{
					std::cout << "---- Entry()\n";
				};

			public:
				T& operator[](int idx)
				{
					if (idx < 0 || idx >= Length)
					{
						std::cout << "EntryContainerBase::Entry Index out of Range.";
					}
					Container -> Changed = true;
					return Container -> Data[idx + Offset];
				}

			public:
				bool IsValid()
				{
					return (Container != NULL);
				}
				void UnReference()
				{
					Container = NULL;
					EntryIndex = -1;

					Offset = 0;
					Length = 0;
				}

			public:
				void Dispose()
				{
					if (IsValid())
					{
						Container -> FreeEntry(EntryIndex);
						UnReference();
						std::cout << "---- Entry.Dispose()\n";
					}
				}
		};

	public:
		std::vector<Entry> EntryRefs;
		T * Data;
		int Size;
		bool Changed;

	public:
		EntryContainerBase(int size)
		{
			EntryRefs = std::vector<Entry>();
			Data = new T[size];
			Size = size;
			Changed = false;
			std::cout << "++++ EntryContainerBase\n";
		}
		~EntryContainerBase()
		{
			std::cout << "---- EntryContainerBase\n";
			delete [] Data;
		}
		void Dispose()
		{
			for (int i = 0; i < EntryRefs.size(); i++)
			{
				EntryRefs[i].UnReferance();
			}
		}

	protected:
		virtual void RemapEntrys() = 0;

		virtual void FreeEntry(int idx) = 0;
		Entry * AllocEntry(int off, int len)
		{
			int idx = EntryRefs.size();
			EntryRefs.push_back(Entry(this, EntryRefs.size(), off, len));
			Changed = true;
			return &(EntryRefs[idx]);
		}

	public:
		virtual Entry * Alloc(int size) = 0;
};

#endif
