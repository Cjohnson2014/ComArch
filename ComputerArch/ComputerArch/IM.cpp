#include "IM.h"

#include <bitset>
#include <iostream>

const std::bitset<16> IM::machinecode[ARRAY_SIZE] = {
    ///* Test 1: No forwarding, no hazards
    std::bitset<16>(std::string("0000000100110111")),
    std::bitset<16>(std::string("0101100110010111")),
    std::bitset<16>(std::string("0110101110110011")),
    std::bitset<16>(std::string("0001100001111010"))
    //*/
    /* Test 2
    std::bitset<16>(std::string("0011010101101000")),
    std::bitset<16>(std::string("1101010110010000")),
    std::bitset<16>(std::string("1100010101000100")),
    std::bitset<16>(std::string("0111001000011000"))
    */
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

