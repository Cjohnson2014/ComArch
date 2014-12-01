#include "IM.h"

#include <bitset>
#include <iostream>

std::bitset<16> IM::machinecode[ARRAY_SIZE] = {

    /* Test 1: No forwarding, no hazards
    std::bitset<16>(std::string("0000000100110111")),
    std::bitset<16>(std::string("0101100110010111")),
    std::bitset<16>(std::string("0110101110110011")),
    std::bitset<16>(std::string("0001100001111010"))
    */

    /* Test 2: memory test
    std::bitset<16>(std::string("0011010101101000")),
    std::bitset<16>(std::string("1101010110010000")),
    std::bitset<16>(std::string("1100010101000010")),
    std::bitset<16>(std::string("0111001000011000"))
    */

    /* Test 3: branch and jump
    std::bitset<16>(std::string("1110000000000010")),
    std::bitset<16>(std::string("0010001101001000")),
    std::bitset<16>(std::string("1011010100000010")),
    std::bitset<16>(std::string("0010001101001000")),
    std::bitset<16>(std::string("1000010110010011"))
    */

    /* Test 4
    std::bitset<16>(std::string("0101000001110001")),
    std::bitset<16>(std::string("0111011001001000")),
    std::bitset<16>(std::string("1111011001100001")),
    std::bitset<16>(std::string("1101010110010100"))
    */

    /* Test 5: data hazards, forwarding should solve
    std::bitset<16>(std::string("0000000100111000")),
    std::bitset<16>(std::string("0101100010010111")),
    std::bitset<16>(std::string("0110101110110011")),
    std::bitset<16>(std::string("0001101101111010"))
    */

    //* Test 6: data hazard, load word, needs one stall
    std::bitset<16>(std::string("0000000100111000")),
    std::bitset<16>(std::string("1101010110010010")),
    std::bitset<16>(std::string("0001100101111010")),
    //*/
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

void IM::setIMData(int location, std::bitset<16> imData)
{
    this->machinecode[location] = imData;
}
