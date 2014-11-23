#include "Adder4.h"

adder4::adder4()
{
	
}

adder4::~adder4()
{
	delete this;
}

std::bitset<16> adder4::get()
{
	return this->addVal;
}
