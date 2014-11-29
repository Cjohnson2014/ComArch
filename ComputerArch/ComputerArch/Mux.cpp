#include "Mux.h"

void Mux::setControlLine(bool control)
	{
		Mux::contol=control;
	}
std::bitset<16> Mux::getOutput(){
	output=input0;
		if(Mux::contol)
		{
			output=input1;
		}
		return output;
	}
void Mux::setInput1(std::bitset<16> input1)
	{
		Mux::input1=input1;
	}
void Mux::setInput0(std::bitset<16> input0)
	{
		Mux::input0=input0;
	}