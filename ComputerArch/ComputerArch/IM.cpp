#include "IM.h"

#include <bitset>
#include <iostream>

const std::bitset<16> IM::machinecode[ARRAY_SIZE] = {
    std::bitset<16>(std::string("0000000100110111"))
};

IM::IM(std::bitset<16> init)
{
    this->readDataIM = init;
}

IM::~IM()
{
    delete this;
}

IM IM::setIMRead(bool IMRead)
{
    this->IMRead = IMRead;
    return *this;
}

void IM::setIMAddress(int IMaddress)
{
    if (IMaddress >= 0)
    {
        this->IMaddress = IMaddress;
        this->readDataIM = machinecode[IMaddress];
    }
}

bool IM::getIMRead()
{
    return this->IMRead;
}

std::bitset<16> IM::getReadDataIM()
{
    return this->readDataIM;
}

