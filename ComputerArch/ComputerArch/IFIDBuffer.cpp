#include "IFIDBuffer.h"

#include <bitset>

std::bitset<16> IFIDBuffer::getProgramCounter()
{
    return this->instructionMemory;
}

std::bitset<16> IFIDBuffer::getInstructionMemory()
{
    return this->instructionMemory;
}

void IFIDBuffer::setProgramCounter(std::bitset<16> pc)
{
    this->programCounter = pc;
}
void IFIDBuffer::setInstructionMemory(std::bitset<16> im)
{
    this->instructionMemory = im;
}
