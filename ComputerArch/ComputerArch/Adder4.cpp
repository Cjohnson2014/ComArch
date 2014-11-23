#include "Adder4.h"

Adder4::adder4()
{
	
}

Adder4::~adder4()
{
	delete this;
}

std::bitset<16> Adder4::get()
{
	return this->addVal;
}
