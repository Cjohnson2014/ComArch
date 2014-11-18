#include "Pc.h"
#include <bitset>
#include <string>


Pc::Pc(){
	current=std::bitset<16>(0);
}
Pc::~Pc()
{
	delete this;
}

void Pc::set(int input)
{
     current=input;
}

int Pc::get(){
	return current;
}
