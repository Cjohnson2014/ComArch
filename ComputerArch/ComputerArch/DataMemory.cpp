#include "DataMemory.h"

#include <bitset>

DataMemory::DataMemory()
{
    this->memWrite = true;
    this->memRead = true;
}

std::bitset<16> DataMemory::get(int location)
{
    return this->memory[location];
}

void DataMemory::set(int location, std::bitset<16> input)
{
    if (this->memWrite)
    {
        this->memory[location] = input;
    }
}

void DataMemory::setAddress(std::bitset<4> address)
{
    this->address = address;
}

void DataMemory::setWriteData(std::bitset<16> wd)
{
    this->wd = wd;
}

void DataMemory::setControlLines(bool memWrite, bool memRead)
{
    this->memWrite = memWrite;
    this->memRead = memRead;
}
