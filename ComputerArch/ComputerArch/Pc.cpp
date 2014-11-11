#include "Pc.h"
#include <bitset>
#include <string>

Pc::Pc(){
	current=std::bitset<16>(0);
}

Pc::get(){
	return current;
}