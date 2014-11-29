#include "DataMemory.h"

#include <bitset>

std::bitset<16> DataMemory::get(int location)
{
    return this->memory[location];
}

void DataMemory::set(int location, std::bitset<16> input)
{
    this->memory[location] = input;
}
