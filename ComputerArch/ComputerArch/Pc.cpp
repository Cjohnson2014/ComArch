#include "Pc.h"
#include <bitset>
#include <string>

Pc::Pc(){
	current=std::bitset<16>(0);
}
<<<<<<< HEAD
void Pc::set(std::bitset<16>input)
{
     current=input;
}
std::bitset<16>Pc::get(){
=======

Pc::~Pc(){

}

std::bitset<16> Pc::get(){
>>>>>>> cdeeb4ae1f5fdde31191fb42794b619b9842c413
	return current;
}
