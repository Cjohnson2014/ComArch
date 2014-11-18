#include "Adder4.h"

adder4::adder4()
{
	
}

adder4::~adder4()
{
	delete this;
}

std::bitset<16> get()
{
	return addValue;
}