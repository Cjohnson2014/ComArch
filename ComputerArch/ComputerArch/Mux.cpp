#include "Mux.h"

Mux::Mux()
{
	this->output=0;
	this->input1=0;
	this->input0=0;
}

Mux::~Mux()
{
	// delete this;
}


void Mux::setControlLine(bool control)
{
    this->contol=control;
}

std::bitset<16> Mux::getOutput(){
    this->output=input0;
    if(this->contol)
    {
        this->output=input1;
    }
    return this->output;
}

void Mux::setInput1(std::bitset<16> input1)
{
    this->input1=input1;
}

void Mux::setInput0(std::bitset<16> input0)
{
    this->input0=input0;
}
