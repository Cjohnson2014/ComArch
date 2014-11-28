#include "ALU.h"

#include <bitset>

ALU::~ALU()
{
    delete this;
}

ALU ALU::setOp(ALUOp op)
{
    this->op = op;
    return *this;
}

ALU ALU::setInput(std::bitset<4> a, std::bitset<4> b)
{
    this->a4 = a;
    this->b4 = b;
    return *this;
}

ALU ALU::setInput(std::bitset<4> a, std::bitset<16> b)
{
    std::bitset<16> extend = std::bitset<16>(std::string("0000000000000000"));
    extend[15] = a[3];
    extend[14] = a[2];
    extend[13] = a[1];
    extend[12] = a[0];

    this->a16 = extend;
    this->b16 = b;
    return *this;
}

std::bitset<4> ALU::execute()
{

    bool is4 = true;
    std::bitset<4> result4;
    std::bitset<16> result16;

    switch (this->op)
    {
        case ALU::AND:
            result4 = this->a4 & this->b4;
            break;

        case ALU::OR:
            result4 = this->a4 | this->b4;
            break;

        case ALU::SLL:
            result4 = this->a4 << (this->b4).to_ulong();
            break;

        case ALU::SRL:
            result4 = this->a4 >> (this->b4).to_ulong();
            break;

        case ALU::XOR:
            result4 = this->a4 ^ this->b4;
            break;

        case ALU::BEQ:
            result4 = std::bitset<4>((this->a4).to_ulong() - (this->b4).to_ulong());
            break;

        case ALU::BNE:
            result4 = std::bitset<4>((this->a4).to_ulong() - (this->b4).to_ulong());
            break;

        case ALU::SUB:
            result4 = std::bitset<4>((this->a4).to_ulong() - (this->b4).to_ulong());
            break;

        case ALU::ADD:
            result4 = std::bitset<4>((this->a4).to_ulong() + (this->b4).to_ulong());
            break;

        case ALU::SLT:
            result4 = std::bitset<4>((this->a4).to_ulong() - (this->b4).to_ulong());
            break;
 
        case ALU::ANDI:
            is4 = false;
            result16 = this->a16 & this->b16;
            break;

        case ALU::ORI:
            is4 = false;
            result16 = this->a16 | this->b16;
            break;

        case ALU::ADDI:
            is4 = false;
            result16 = std::bitset<16>((this->a16).to_ulong() + (this->b16).to_ulong());
            break;
    }

    if (!is4)
    {
        if (result16.to_ulong() == 0)
        {
            this->zeroBit = 1;
        }
        else
        {
            this->zeroBit = 0;
        }

        result4[3] = result16[15];
        result4[2] = result16[14];
        result4[1] = result16[13];
        result4[0] = result16[12];
    }
    else
    {
        if (result4.to_ulong() == 0)
        {
            this->zeroBit = 1;
        }
        else
        {
            this->zeroBit = 0;
        }
    }

    return result4;
}

std::bitset<1> ALU::getZeroBit()
{
    return this->zeroBit;
}

