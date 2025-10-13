
#include "BitStream.hpp"

BitStream::BitStream(const uint8 * ptr, uint32 len) :
	Data(ptr),
	Len(len),
	Index(0)
{ }

BitStream::BitStream(const std::string & str) :
	Data((const uint8 *)str.c_str()),
	Len(str.size()),
	Index(0)
{ }



const uint8 *	BitStream::DataAtIndex(uint32 skipBytes) const
{
	return Data + GetByteIndex() + skipBytes;
}



uint32	BitStream::GetBitIndex() const
{
	return (Index & 0b111);
}
uint32	BitStream::GetByteIndex() const
{
	return (Index >> 3);
}



void	BitStream::MoveToNextByte()
{
	uint32 bit = GetBitIndex();
	if (bit != 0)
	{
		Index += (8 - bit);
	}
}
void	BitStream::MoveBytes(uint32 count)
{
	Index += count << 3;
}
void	BitStream::MoveBits(uint32 count)
{
	Index += count;
}



uint8	BitStream::GetBits8(uint8 bit_count) const
{
	if (bit_count == 0) { return 0; }
	bit_count = ((bit_count - 1) & UINT8_BIT_LIMIT) + 1;

	uint32	bitI = GetBitIndex();
	uint32	byteI = GetByteIndex();

	uint8 val = 0;
	uint8 byte_count = UINT8_BYTE_COUNT;
	if (bitI != 0)
	{
		val |= ((uint8)Data[byteI]) >> (bitI);
		byte_count++;
	}

	for (uint8 i = 0; i < byte_count; i++)
	{
		val |= ((uint8)Data[byteI + i]) << ((i * 8) - bitI);
	}

	if (bit_count != UINT8_BIT_COUNT)
	{
		val = val & (0xFF >> (UINT8_BIT_COUNT - bit_count));
	}
	return val;
}
uint16	BitStream::GetBits16(uint8 bit_count) const
{
	if (bit_count == 0) { return 0; }
	bit_count = ((bit_count - 1) & UINT16_BIT_LIMIT) + 1;

	uint32	bitI = GetBitIndex();
	uint32	byteI = GetByteIndex();

	uint16 val = 0;
	uint8 byte_count = UINT16_BYTE_COUNT;
	if (bitI != 0)
	{
		val |= ((uint16)Data[byteI]) >> (bitI);
		byte_count++;
	}

	for (uint8 i = 0; i < byte_count; i++)
	{
		val |= ((uint16)Data[byteI + i]) << ((i * 8) - bitI);
	}

	if (bit_count != UINT16_BIT_COUNT)
	{
		val = val & (0xFFFF >> (UINT16_BIT_COUNT - bit_count));
	}
	return val;
}
uint32	BitStream::GetBits32(uint8 bit_count) const
{
	if (bit_count == 0) { return 0; }
	bit_count = ((bit_count - 1) & UINT32_BIT_LIMIT) + 1;

	uint32	bitI = GetBitIndex();
	uint32	byteI = GetByteIndex();

	uint32 val = 0;

	uint8 byte_count = UINT32_BYTE_COUNT;
	if (bitI != 0)
	{
		val |= ((uint32)Data[byteI]) >> (bitI);
		byte_count++;
	}
	for (uint8 i = 0; i < byte_count; i++)
	{
		val |= ((uint32)Data[byteI + i]) << ((i * 8) - bitI);
	}

	if (bit_count != UINT32_BIT_COUNT)
	{
		val = val & (0xFFFFFFFF >> (UINT32_BIT_COUNT - bit_count));
	}
	return val;
}
uint64	BitStream::GetBits64(uint8 bit_count) const
{
	if (bit_count == 0) { return 0; }
	bit_count = ((bit_count - 1) & UINT64_BIT_LIMIT) + 1;

	uint32	bitI = GetBitIndex();
	uint32	byteI = GetByteIndex();

	uint64 val = 0;
	uint8 byte_count = UINT64_BYTE_COUNT;
	if (bitI != 0)
	{
		val |= ((uint64)Data[byteI]) >> (bitI);
		byte_count++;
	}

	for (uint8 i = 0; i < byte_count; i++)
	{
		val |= ((uint64)Data[byteI + i]) << ((i * 8) - bitI);
	}

	if (bit_count != UINT64_BIT_COUNT)
	{
		val = val & (0xFFFFFFFFFFFFFFFF >> (UINT64_BIT_COUNT - bit_count));
	}
	return val;
}



uint8	BitStream::GetMoveBits8(uint8 bit_count)
{
	uint8 val = GetBits8(bit_count);
	MoveBits(bit_count);
	return val;
}
uint16	BitStream::GetMoveBits16(uint8 bit_count)
{
	uint16 val = GetBits16(bit_count);
	MoveBits(bit_count);
	return val;
}
uint32	BitStream::GetMoveBits32(uint8 bit_count)
{
	uint32 val = GetBits32(bit_count);
	MoveBits(bit_count);
	return val;
}
uint64	BitStream::GetMoveBits64(uint8 bit_count)
{
	uint64 val = GetBits64(bit_count);
	MoveBits(bit_count);
	return val;
}





const char * BitStream::LenReachedException::what() const throw() { return "BitStream Length reached"; }
