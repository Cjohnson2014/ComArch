#include "Pc.h"
#include <bitset>
#include <string>


Pc::Pc(){
	this->current=0;
}

void Pc::set(int input)
{
     this->current = input;
}

int Pc::get(){
	return this->current;
}
