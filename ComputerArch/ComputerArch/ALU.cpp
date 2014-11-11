#include "ALU.h"

#include <bitset>

ALU::ALU()
{

}

ALU::~ALU()
{
    delete this;
}

ALU ALU::setOp(ALUOp op)
{
    this->op = op;
    return *this;
}

ALU ALU::setInput(std::bitset<4> a, std::bitset<16> b)
{
    this->a = a;
    this->b = b;
    return *this;
}

void ALU::execute()
{
    // actual alu execution will go in here
}

std::bitset<1> ALU::getZeroBit()
{
    return this->zeroBit;
}

