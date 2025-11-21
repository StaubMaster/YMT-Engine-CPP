
#include "Keys.hpp"

#define KEYSTATE_BITS	0b111
#define KEYSTATE_UD_BIT	0b001
#define KEYSTATE_U_BIT	0b000
#define KEYSTATE_D_BIT	0b001
#define KEYSTATE_PR_BIT	0b110
#define KEYSTATE_P_BIT	0b010
#define KEYSTATE_R_BIT	0b100

void KeyState::SetDown()
{
	State = (State & (~KEYSTATE_UD_BIT)) | KEYSTATE_D_BIT;
}
void KeyState::SetUp()
{
	State = (State & (~KEYSTATE_UD_BIT)) | KEYSTATE_U_BIT;
}
void KeyState::SetPressed()
{
	State = (State & (~KEYSTATE_PR_BIT)) | KEYSTATE_P_BIT;
	SetDown();
}
void KeyState::SetReleased()
{
	State = (State & (~KEYSTATE_PR_BIT)) | KEYSTATE_R_BIT;
	SetUp();
}

bool KeyState::GetDown() const
{
	return (State & KEYSTATE_UD_BIT) == KEYSTATE_D_BIT;
}
bool KeyState::GetUp() const
{
	return (State & KEYSTATE_UD_BIT) == KEYSTATE_U_BIT;
}
bool KeyState::GetPressed() const
{
	return (State & KEYSTATE_PR_BIT) == KEYSTATE_P_BIT;
}
bool KeyState::GetReleased() const
{
	return (State & KEYSTATE_PR_BIT) == KEYSTATE_R_BIT;
}

void KeyState::Frame()
{
	State = State & (~KEYSTATE_PR_BIT);
}





/*std::string KeyData::ToString() const
{
	std::string str;
	if (State.GetUp())		{ str += 'U'; } else { str += '_'; }
	if (State.GetDown())	{ str += 'D'; } else { str += '_'; }
	if (State.GetPressed())	{ str += 'P'; } else { str += '_'; }
	if (State.GetReleased()){ str += 'R'; } else { str += '_'; }
	return str;
}*/





//#include <iostream>

KeyDataArray::KeyDataArray()
{
	//std::cout << "++++ KeyDataArray() ...\n";
	TokenMin = 0;
	TokenMax = 0;
	KeysCount = 0;
	Keys = new KeyData[KeysCount];
	//std::cout << "++++ KeyDataArray() done\n";
}
KeyDataArray::KeyDataArray(unsigned short tokenMin, unsigned int tokenMax)
{
	//std::cout << "++++ KeyDataArray(tokenMin, tokenNax) ....\n";
	TokenMin = tokenMin;
	TokenMax = tokenMax;
	KeysCount = (TokenMax - TokenMin) + 1;
	Keys = new KeyData[KeysCount];
	for (unsigned int i = 0; i < KeysCount; i++)
	{
		Keys[i].State.State = 0;
		Keys[i].Token = i + TokenMin;
	}
	//std::cout << "++++ KeyDataArray(tokenMin, tokenNax) done\n";
}
KeyDataArray::~KeyDataArray()
{
	//std::cout << "---- KeyDataArray() ....\n";
	delete[] Keys;
	//std::cout << "---- KeyDataArray() done\n";
}
KeyDataArray::KeyDataArray(const KeyDataArray & other)
{
	//std::cout << "==== KeyDataArray() ...\n";
	TokenMin = other.TokenMin;
	TokenMax = other.TokenMax;
	KeysCount= other.KeysCount;
	Keys = new KeyData[KeysCount];
	for (unsigned int i = 0; i < KeysCount; i++)
	{
		Keys[i] = other.Keys[i];
	}
	//std::cout << "==== KeyDataArray() done\n";
}
KeyDataArray & KeyDataArray::operator =(const KeyDataArray & other)
{
	//std::cout << "==== operator KeyDataArray() ...\n";
	delete[] Keys;
	TokenMin = other.TokenMin;
	TokenMax = other.TokenMax;
	KeysCount= other.KeysCount;
	Keys = new KeyData[KeysCount];
	for (unsigned int i = 0; i < KeysCount; i++)
	{
		Keys[i] = other.Keys[i];
	}
	//std::cout << "==== operator KeyDataArray() done\n";
	return *this;
}
bool	KeyDataArray::Has(unsigned short token) const
{
	return (token >= TokenMin && token <= TokenMax);
}
KeyData & KeyDataArray::operator [](unsigned short token)
{
	return Keys[token - TokenMin];
}
const KeyData & KeyDataArray::operator [](unsigned short token) const
{
	return Keys[token - TokenMin];
}
void	KeyDataArray::Frame()
{
	for (unsigned int i = 0; i < KeysCount; i++)
	{
		Keys[i].State.Frame();
	}
}





KeyDataArrayArray::KeyDataArrayArray(unsigned int count)
{
	//std::cout << "++++ KeyDataArrayArray() ...\n";
	KeyArraysCount = count;
	KeyArrays = new KeyDataArray[KeyArraysCount];
	//std::cout << "++++ KeyDataArrayArray() done\n";
}
KeyDataArrayArray::~KeyDataArrayArray()
{
	//std::cout << "---- KeyDataArrayArray() ...\n";
	delete[] KeyArrays;
	//std::cout << "---- KeyDataArrayArray() done\n";
}

bool	KeyDataArrayArray::Has(unsigned short token) const
{
	for (unsigned int i = 0; i < KeyArraysCount; i++)
	{
		if (KeyArrays[i].Has(token))
		{
			return true;
		}
	}
	return false;
}
KeyData & KeyDataArrayArray::operator [](unsigned short token)
{
	for (unsigned int i = 0; i < KeyArraysCount; i++)
	{
		if (KeyArrays[i].Has(token))
		{
			return KeyArrays[i][token];
		}
	}
	throw "Key Token not in Array";
}
const KeyData & KeyDataArrayArray::operator [](unsigned short token) const
{
	for (unsigned int i = 0; i < KeyArraysCount; i++)
	{
		if (KeyArrays[i].Has(token))
		{
			return KeyArrays[i][token];
		}
	}
	throw "Key Token not in Array";
}

void	KeyDataArrayArray::Frame()
{
	for (unsigned int i = 0; i < KeyArraysCount; i++)
	{
		KeyArrays[i].Frame();
	}
}


