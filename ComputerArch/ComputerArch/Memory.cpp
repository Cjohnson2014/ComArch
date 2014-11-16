#include "Memory.h"

#include <bitset>

Memory::Memory()
{
    // nothing here yet
}

Memory::~Memory()
{
    delete this;
}

Memory Memory::setMemWrite(bool memWrite)
{
    this->memWrite = memWrite;
    return *this;
}

Memory Memory::setMemRead(bool memRead)
{
    this->memRead = memRead;
    return *this;
}

Memory Memory::setAddress(std::bitset<16> address)
{
    this->address = address;
    return *this;
}

Memory Memory::setWriteDataMem(std::bitset<16> writeDataMem)
{
    this->writeDataMem = writeDataMem;
    return *this;
}

bool Memory::getMemWrite()
{
    return this->memWrite;
}

bool Memory::getMemRead()
{
    return this->memRead;
}

std::bitset<16> Memory::getReadDataMem()
{
    return this->readDataMem;
}

