
#ifndef BITSTREAM_HPP
# define BITSTREAM_HPP
# include "uint.hpp"

class BitStream
{
	public:
		const uint8*	Data;
		const uint32	Len;
		uint32			Index;

	public:
		BitStream(const uint8 * ptr, uint32 len);
		BitStream(const std::string & str);

	public:
		const uint8 *	DataAtIndex(uint32 skipBytes = 0) const;

	public:
		uint32	GetBitIndex() const;
		uint32	GetByteIndex() const;

	public:
		void	MoveToNextByte();
		void	MoveBytes(uint32 count = 1);
		void	MoveBits(uint32 count = 1);

	public:
		uint8	GetBits8(uint8 bit_count = UINT8_BIT_COUNT) const;
		uint16	GetBits16(uint8 bit_count = UINT16_BIT_COUNT) const;
		uint32	GetBits32(uint8 bit_count = UINT32_BIT_COUNT) const;
		uint64	GetBits64(uint8 bit_count = UINT64_BIT_COUNT) const;

		uint8	GetMoveBits8(uint8 bit_count = UINT8_BIT_COUNT);
		uint16	GetMoveBits16(uint8 bit_count = UINT16_BIT_COUNT);
		uint32	GetMoveBits32(uint8 bit_count = UINT32_BIT_COUNT);
		uint64	GetMoveBits64(uint8 bit_count = UINT64_BIT_COUNT);

	private:
		class LenReachedException : public std::exception { public: const char * what() const throw(); };
};

#endif
