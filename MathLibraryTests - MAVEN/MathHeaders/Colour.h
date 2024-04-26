#pragma once

namespace MathClasses
{
    struct Colour
    {
	public:	//	VARIABLES

		unsigned int colour;	//	usually four bytes

		//	an unsigned bit can only have a positive value

		//std::uint32_t colour;

	public:	//	CONSTRUCTORS

		Colour()
		{
			colour = 0x000000ff;
		}

		Colour(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
		{
			unsigned int temp;
			
			colour = red << 24;
			
			temp = green << 16;

			colour = colour | temp;

			temp = 0;

			temp = blue << 8;

			colour = colour | temp;

			temp = 0;

			temp = alpha << 0;

			colour = colour | temp;
		}

		~Colour()
		{

		}

	public:	//	METHODS

		unsigned char GetRed() const	//	unsigned char holds only one byte, cutting off all but the right-most eight bits
		{
			return colour >> 24;	//	the >> operator slides the bits in the direction of the arrows by 24 spaces. The implicit conversion from unsigned int to char cuts off bits after the first byte
		}

		unsigned char GetGreen() const
		{
			return colour >> 16;	//	it seems that the 'return' will only return the right-most byte when converted to the unsigned char, so we push the relevant values to the right-most bits
		}

		unsigned char GetBlue() const
		{
			return colour >> 8;
		}

		unsigned char GetAlpha() const
		{
			return colour >> 0;	//	not sure if these functions are correct, just assuming this is what to do
		}

		void SetRed(unsigned char red)
		{
			unsigned int v = red << 24;	//	creates a value 'v', then push the input value into the red position, which is 24 bits to the left
			//	v = redvalue 00000000 00000000 00000000

			colour = colour & 0x00ffffff;	//	the & operator clears out the red position bits with the 00 after the 0x, the ff values, combined with &, make no changes to the other colours
			//	10011100 00011010 11111100 11111111 & 00000000 11111111 11111111 11111111 => 00000000 00011010 11111100 11111111

			colour = colour | v;	//	uses the '|' or 'or' operator to copy the values of 'v' into 'colour'. When one or both bits in comparison are set, aka '1', then the '|' operator outputs a '1', otherwise outputs '0'.
		}

		void SetGreen(unsigned char green)
		{
			unsigned int v = green << 16;

			colour = colour & 0xff00ffff;

			colour = colour | v;
		}

		void SetBlue(unsigned char blue)
		{
			unsigned int v = blue << 8;

			colour = colour & 0xffff00ff;

			colour = colour | v;
		}

		void SetAlpha(unsigned char alpha)
		{
			unsigned int v = alpha << 0;

			colour = colour & 0xffffff00;

			colour = colour | v;
		}

	public: //	OPERATORS

		bool operator == (Colour compare)
		{
			if (colour == compare.colour)
			{
				return true;
			}

			return false;
		}
    };
}