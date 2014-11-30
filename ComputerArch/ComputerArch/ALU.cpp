#include "ALU.h"

#include <bitset>

ALU::~ALU()
{
    delete this;
}

ALU *ALU::setOp(int op)
{
    this->op = op;
    return this;
}

ALU *ALU::setInput(std::bitset<16> a, std::bitset<16> b)
{
    this->a16 = a;
    this->b16 = b;
    return this;
}

std::bitset<16> ALU::execute()
{
    std::bitset<16> result16;

    switch (this->op)
    {
        case ALU::AND:
            result16 = this->a16 & this->b16;
            break;

        case ALU::OR:
            result16 = this->a16 | this->b16;
            break;

        case ALU::SLL:
            result16 = this->a16 << (this->b16).to_ulong();
            break;

        case ALU::SRL:
            result16 = this->a16 >> (this->b16).to_ulong();
            break;

        case ALU::XOR:
            result16 = this->a16 ^ this->b16;
            break;

        case ALU::SUB:
            result16 = std::bitset<16>((this->a16).to_ulong() - (this->b16).to_ulong());
            break;

        case ALU::ADD:
            result16 = std::bitset<16>((this->a16).to_ulong() + (this->b16).to_ulong());
            break;

        case ALU::SLT:
            result16 = std::bitset<16>((this->a16).to_ulong() - (this->b16).to_ulong());

            if ((long)result16.to_ulong() < 0)
            {
                result16 = std::bitset<16>(0x0001);
            }
            else
            {
                result16 = std::bitset<16>(0x0000);
            }

            break;
 
        case ALU::ANDI:
            result16 = this->a16 & this->b16;
            break;

        case ALU::ORI:
            result16 = this->a16 | this->b16;
            break;

        case ALU::ADDI:
            result16 = std::bitset<16>((this->a16).to_ulong() + (this->b16).to_ulong());
            break;
    }

    if (result16.to_ulong() == 0)
    {
        this->zeroBit = 1;
    }
    else
    {
        this->zeroBit = 0;
    }

    return result16;
}

std::bitset<1> ALU::getZeroBit()
{
    return this->zeroBit;
}

