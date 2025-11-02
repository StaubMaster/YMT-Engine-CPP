
#ifndef  ENTRY_CONTAINER_BASE_HPP
# define ENTRY_CONTAINER_BASE_HPP

# include "Miscellaneous/ContainerDynamic.hpp"

# include <vector>
# include <iostream>
# include <sstream>

/*
	EntryContainer holds any data
	instead of adding something
	you instead get an Entry in the Container
		it has a fixes size
		when an entry the others might get moved around
		so pointers cant be used here
		the Entry has an Indexer that is used to change things in the main Container
*/

/*
	right now pointers to the Entrys are returned
	but when a Entry is added, it Points to a vector
	which changes Memory when it changes size

	so this is bad

	just return a Copy of the data ?

	no, because when the Container changes,
	it needs to change the Offset in the Entry

	so the outside needs a Pointer so it stays up to date
	and the Container needs a Poitner to update it

	so use new to Allocate them
	but then the question is where to delete them ?
	the Container allocates them and is guarenteed to know all of them

	but then the outside might have an invalid pointer
	but that would only happen after the Container was deleted
	so just make sure that dosent happen
*/

template <typename T>
class EntryContainerBase
{
	public:
		class Entry
		{
			private:
			public:
				EntryContainerBase<T> * Container;
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

					//std::cout << "++++ Entry()\n";
				}
				Entry(const Entry & other)
				{
					Container = other.Container;
					EntryIndex = other.EntryIndex;

					Offset = other.Offset;
					Length = other.Length;

					//std::cout << "++++ Entry(other)\n";
				}
				Entry(EntryContainerBase<T> * container, int entry_idx, int off, int len)
				{
					Container = container;
					EntryIndex = entry_idx;

					Offset = off;
					Length = len;

					//std::cout << "++++ Entry(container)\n";
				}
				virtual ~Entry()
				{
					//std::cout << "---- Entry()\n";
				};

			public:
				T& operator[](int idx)
				{
					//std::cout << "EntryContainerBase: [" << idx << "] " << Offset << "|" << Length << "(" << Container << ":" << (Container -> Data) << ":" << (Container -> Size) << ")" << EntryIndex << "\n";
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
						//std::cout << "---- Entry.Dispose()\n";
					}
				}
		};

	public:
		ContainerDynamic<Entry*> EntryRefs;
		T * Data;
		int Size;
		bool Changed;

	public:
		std::string ToInfo() const
		{
			std::ostringstream ss;
			ss << "(" << this << ":" << Data << ":" << Size << ")";
			return ss.str();
		}

	public:
		EntryContainerBase(int size)
		{
			EntryRefs = ContainerDynamic<Entry*>();
			Data = new T[size];
			Size = size;
			Changed = false;
			//std::cout << "++++ EntryContainerBase\n";
		}
		~EntryContainerBase()
		{
			for (unsigned int i = 0; i < EntryRefs.Count(); i++)
			{
				delete EntryRefs[i];
			}
			//std::cout << "---- EntryContainerBase\n";
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
			int idx = EntryRefs.Count();
			Entry * entry = new Entry(this, idx, off, len);
			EntryRefs.Insert(entry);
			Changed = true;
			return entry;
		}

	public:
		virtual Entry * Alloc(int size) = 0;
};

#endif
