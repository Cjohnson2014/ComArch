#include "IFIDBuffer.h"

#include <bitset>

int IFIDBuffer::getProgramCounter()
{
    return this->programCounter;
}

std::bitset<16> IFIDBuffer::getInstructionMemory()
{
    return this->instructionMemory;
}

void IFIDBuffer::setProgramCounter(int pc)
{
    this->programCounter = pc;
}
void IFIDBuffer::setInstructionMemory(std::bitset<16> im)
{
    this->instructionMemory = im;
}
