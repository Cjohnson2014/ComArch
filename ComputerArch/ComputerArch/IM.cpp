#include "IM.h"

#include <bitset>

const std::bitset<16> IM::machinecode[ARRAY_SIZE] = {
    std::bitset<16>(std::string("0101000001110001"))
};

IM::IM()
{
    // nothing here yet
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

IM IM::setIMAddress(std::bitset<16> IMaddress)
{
    this->IMaddress = IMaddress;
    return *this;
}

bool IM::getIMRead()
{
    return this->IMRead;
}

std::bitset<16> IM::getReadDataIM()
{
    return this->readDataIM;
}

