
#include "BitStream.hpp"

BitStream::BitStream(const uint8 * ptr, uint32 len) :
	Data(ptr),
	Len(len),
	Index(0)
{

}

BitStream::BitStream(const std::string & str) :
	Data((const uint8 *)str.c_str()),
	Len(str.size()),
	Index(0)
{
	
}



uint32	BitStream::get_BitIndex() const
{
	return (Index & 0b111);
}
/*void	BitStream::set_BitIndex(uint32 idx)
{
	Index = ((Index | 0b111) ^ 0b111) | (idx & 0b111);
}*/
uint32	BitStream::get_ByteIndex() const
{
	return (Index >> 3);
}
/*void	BitStream::set_ByteIndex(uint32 idx)
{
	Index = (Index & 0b111) | (idx << 3);
}*/
void	BitStream::set_Index(uint32 bits, uint32 bytes)
{
	Index = (bytes << 3) | (bits & 0b111);
}



uint32	BitStream::bits(uint32 num, uint8 extra)
{
	if (num == 0)
		return (0);
	num = ((num - 1) & 0b11111) + 1;
	uint32	mun = 32 - num;

	uint32	bitI = get_BitIndex();
	uint32	byteI = get_ByteIndex();

	uint32 sum;
	if (bitI == 0)
	{
		sum =
			(((uint32)Data[byteI + 0]) >> (bitI)) |
			(((uint32)Data[byteI + 1]) << (8 - bitI)) |
			(((uint32)Data[byteI + 2]) << (16 - bitI)) |
			(((uint32)Data[byteI + 3]) << (24 - bitI));
	}
	else
	{
		sum =
			(((uint32)Data[byteI + 0]) >> (bitI)) |
			(((uint32)Data[byteI + 1]) << (8 - bitI)) |
			(((uint32)Data[byteI + 2]) << (16 - bitI)) |
			(((uint32)Data[byteI + 3]) << (24 - bitI)) |
			(((uint32)Data[byteI + 4]) << (32 - bitI));
	}

	if ((extra & BITSTREAM_REV) != 0)
		sum = (ReverseBits(sum) >> mun);
	sum = sum & (0xFFFFFFFF >> mun);

	if ((extra & BITSTREAM_STAY) == 0)
		Index += num;

	if (get_ByteIndex() > Len)
		throw LenReachedException();

	return (sum);
}

const uint8 *	BitStream::DataAtIndex(uint32 skipBytes) const
{
	return Data + get_ByteIndex() + skipBytes;
}
void	BitStream::moveIndex(uint32 skip)
{
	uint32	idx = get_ByteIndex();
	if (get_BitIndex() != 0)
		idx++;
	idx += skip;
	if (idx > Len)
		throw LenReachedException();
	set_Index(0, idx);
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



uint8	BitStream::GetBits8(uint8 bit_count)
{
	uint32	bitI = get_BitIndex();
	uint32	byteI = get_ByteIndex();

	uint8 val = 0;
	if (bitI != 0)
	{
		val |= ((uint8)Data[byteI + 0]) >> (bitI);
		byteI++;
	}

	for (uint8 i = 0; i < UINT8_BYTE_COUNT; i++)
	{
		val |= ((uint8)Data[byteI + i]) << ((i * 8) - bitI);
	}

	val = val & (0xFF >> (UINT8_BIT_COUNT - bit_count));
	return val;
}
uint16	BitStream::GetBits16(uint8 bit_count)
{
	uint32	bitI = get_BitIndex();
	uint32	byteI = get_ByteIndex();

	uint16 val = 0;
	if (bitI != 0)
	{
		val |= ((uint16)Data[byteI + 0]) >> (bitI);
		byteI++;
	}

	for (uint8 i = 0; i < UINT16_BYTE_COUNT; i++)
	{
		val |= ((uint16)Data[byteI + i]) << ((i * 8) - bitI);
	}

	val = val & (0xFFFF >> (UINT16_BIT_COUNT - bit_count));
	return val;
}
uint32	BitStream::GetBits32(uint8 bit_count)
{
	uint32	bitI = get_BitIndex();
	uint32	byteI = get_ByteIndex();

	uint32 val = 0;
	if (bitI != 0)
	{
		val |= ((uint32)Data[byteI]) >> (bitI);
		byteI++;
	}

	for (uint8 i = 0; i < UINT32_BYTE_COUNT; i++)
	{
		val |= ((uint32)Data[byteI + i]) << ((i * 8) - bitI);
	}

	val = val & (0xFFFFFFFF >> (UINT32_BIT_COUNT - bit_count));
	return val;
}
uint64	BitStream::GetBits64(uint8 bit_count)
{
	uint32	bitI = get_BitIndex();
	uint32	byteI = get_ByteIndex();

	uint64 val = 0;
	if (bitI != 0)
	{
		val |= ((uint64)Data[byteI + 0]) >> (bitI);
		byteI++;
	}

	for (uint8 i = 0; i < UINT64_BYTE_COUNT; i++)
	{
		val |= ((uint64)Data[byteI + i]) << ((i * 8) - bitI);
	}

	val = val & (0xFFFFFFFFFFFFFFFF >> (UINT64_BIT_COUNT - bit_count));
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
