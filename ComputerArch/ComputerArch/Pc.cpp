#include "Pc.h"
#include <bitset>
#include <string>

Pc::Pc(){
	current=std::bitset<16>(0);
}
void Pc::set(std::bitset<16>input)
{
     current=input;
}
std::bitset<16>Pc::get(){
	return current;
}