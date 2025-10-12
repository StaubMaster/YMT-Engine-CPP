
#ifndef  UINT_HPP
# define UINT_HPP

# include <stdint.h>
# include <string>

#define  UINT8_BIT_LIMIT 0b111
#define UINT16_BIT_LIMIT 0b1111
#define UINT32_BIT_LIMIT 0b11111
#define UINT64_BIT_LIMIT 0b111111

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;



//	uint8
std::string	uint_Chr(uint8 val);

std::string	ToBase2(uint8 val, uint8 num = UINT8_BIT_LIMIT);
std::string	ToBase16(uint8 val);

//	uint16
std::string	ToBase2(uint16 val, uint8 num = UINT16_BIT_LIMIT);
std::string	ToBase2(uint16 val, char seperator, uint8 num = UINT16_BIT_LIMIT);
std::string	ToBase16(uint16 val);
std::string	ToBase16(uint16 val, char seperator);

//	uint32
std::string	uint_Chr(uint32 val);

std::string	ToBase2(uint32 val, uint8 num = UINT32_BIT_LIMIT);
std::string	ToBase2(uint32 val, char seperator, uint8 num = UINT32_BIT_LIMIT);
std::string	ToBase16(uint32 val);
std::string	ToBase16(uint32 val, char seperator);

//	uint64
std::string	ToBase2(uint64 val, uint8 num = UINT64_BIT_LIMIT);
std::string	ToBase2(uint64 val, char seperator, uint8 num = UINT64_BIT_LIMIT);
std::string	ToBase16(uint64 val);
std::string	ToBase16(uint64 val, char seperator);

#endif
