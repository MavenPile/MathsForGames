#pragma once
#include <cstdint>

struct Colour
{
private:

	unsigned int m_colour;	//	usually four bytes

	std::uint32_t color;	//	using the cstdint header, this unsigned int is guaranteed to only be four bytes

public:	//	methods

	Colour()
	{
		m_colour = 0x000000ff;
	}

	Colour(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
	{
		m_colour = red << 24, green << 16, blue << 8, alpha << 0;
	}

	~Colour()
	{

	}

	unsigned char GetRed() const
	{
		return m_colour >> 24;	//	the >> operator slides the bits in the direction of the arrows by 24 spaces. The implicit conversion from unsigned int to char cuts off bits after the first byte
	}

	unsigned char GetGreen() const
	{
		return m_colour >> 16;
	}

	unsigned char GetBlue() const
	{
		return m_colour >> 8;
	}

	unsigned char GetAlpha() const
	{
		return m_colour >> 0;	//	not sure if these functions are correct, just assuming this is what to do
	}

	void SetRed(unsigned char red)
	{
		unsigned int v = red << 24;	//	creates a value 'v', then push the input value into the red position, which is 24 bits to the left
									//	v = redvalue 00000000 00000000 00000000

		m_colour = m_colour & 0x00ffffff;	//	the & operator clears out the red position bits with the 00 after the 0x, the ff values, combined with &, make no changes to the other colours
										//	10011100 00011010 11111100 11111111 & 00000000 11111111 11111111 11111111 => 00000000 00011010 11111100 11111111

		m_colour = m_colour | v;	//	uses the '|' or 'or' operator to copy the values of 'v' into 'colour'. When one or both bits in comparison are set, aka '1', then the '|' operator outputs a '1', otherwise outputs '0'.
	}

	void SetGreen(unsigned char green)
	{
		unsigned int v = green << 16;

		m_colour = m_colour & 0xff00ffff;

		m_colour = m_colour | v;
	}

	void SetBlue(unsigned char blue)
	{
		unsigned int v = blue << 8;

		m_colour = m_colour & 0xffff00ff;

		m_colour = m_colour | v;
	}

	void SetAlpha(unsigned char alpha)
	{
		unsigned int v = alpha << 0;

		m_colour = m_colour & 0xffffff00;

		m_colour = m_colour | v;
	}
};

