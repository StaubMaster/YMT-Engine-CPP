#ifndef  KEYS_HPP
# define KEYS_HPP

/*
store an Array of Keystates
to determin Up:Down:Pressed:Released of Keys

putting everything would be a lot of empty space
put into arrays whereever possible

48 to 57	Numbers
65 to 90	Letters
256 to 269	Control0
280 to 284	Locks (and other)
290 to 314	Function
320 to 336	KeyPad
340 to 348	Control1

automatically create arrays
these wont ever change so nah
*/

/*
	right now these still use GLFW Tokens.
	which act weird sometimes dont properly work sometimes
	might just be IntelliSense not understanding my genius
*/

struct KeyState
{
	unsigned char State;

	void	SetDown();
	void	SetUp();
	void	SetPressed();
	void	SetReleased();

	bool	GetDown() const;
	bool	GetUp() const;
	bool	GetPressed() const;
	bool	GetReleased() const;

	void	Frame();
};

struct KeyData
{
	KeyState		State;
	unsigned short	Token;
	//	store string of what this is ?
	//	at that point I would have to set thigns individually

	//std::string	ToString() const;
};

struct KeyDataArray
{
	unsigned short	TokenMin;
	unsigned short	TokenMax;

	unsigned short	KeysCount;
	KeyData	*		Keys;

	KeyDataArray();
	KeyDataArray(unsigned short tokenMin, unsigned int tokenMax);
	~KeyDataArray();

	KeyDataArray(const KeyDataArray & other);
	KeyDataArray & operator =(const KeyDataArray & other);

	bool			Has(unsigned short token) const;
	KeyData	&		operator [](unsigned short token);
	const KeyData &	operator [](unsigned short token) const;

	void	Frame();
};

struct KeyDataArrayArray
{
	unsigned int KeyArraysCount;
	KeyDataArray * KeyArrays;

	KeyDataArrayArray(unsigned int count);
	~KeyDataArrayArray();

	bool			Has(unsigned short token) const;
	KeyData &		operator [](unsigned short token);
	const KeyData &	operator [](unsigned short token) const;

	void	Frame();
};

#endif
