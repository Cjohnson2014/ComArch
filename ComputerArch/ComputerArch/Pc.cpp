#include "Pc.h"
<<<<<<< HEAD
#include <bitset>
#include <string>


Pc::Pc(){
	current=0;
}
Pc::~Pc()
{
	delete this;
}
=======
>>>>>>> origin/master

void Pc::set(int input)
{
     this->current = input;
}

int Pc::get(){
	return this->current;
}
