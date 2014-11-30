#include "Control.h"
#include "ALU.h"

#include <bitset>
#include <string>

void Control::update(std::bitset<4> opCode)
{
    this->jump = false;
    this->regDst = false;
    this->memToReg = false;
    this->aluSrc = false;
    this->branch = false;
    this->memWrite = false;
    this->memRead = false;
    this->regWrite = false;

    switch (opCode.to_ulong())
    {
        case 0: // add
            this->aluOp = ALU::ADD;
            this->regWrite = true;
            this->regDst = true;

            break;

        case 1: // sub
            this->aluOp = ALU::SUB;
            this->regWrite = true;
            this->regDst = true;

            break;

        case 2: // or
            this->aluOp = ALU::OR;
            this->regWrite = true;
            this->regDst = true;

            break;

        case 3: // exclusive or
            this->aluOp = ALU::XOR;
            this->regWrite = true;
            this->regDst = true;

            break;

        case 4: // and
            this->aluOp = ALU::AND;
            this->regWrite = true;
            this->regDst = true;

            break;

        case 5: // add immediate
            this->aluOp = ALU::ADDI;
            this->regWrite = true;
            this->aluSrc = true;

            break;

        case 6: // or immediate
            this->aluOp = ALU::ORI;
            this->regWrite = true;
            this->aluSrc = true;

            break;

        case 7: // set less than
            this->aluOp = ALU::SLT;
            this->regDst = true;

            break;
            
        case 8: // shift left
            this->aluOp = ALU::SLL;
            this->regWrite = true;

            break;

        case 9: // shift right
            this->aluOp = ALU::SRL;
            this->regWrite = true;

            break;

        case 10: // branch equal
            this->aluOp = ALU::SUB;
            this->branch = true;

            break;

        case 11: // branch not equal
            this->aluOp = ALU::SUB;

            break;

        case 12: // store word
            this->aluOp = ALU::ADD;
            this->memWrite = true;
            this->aluSrc = true;

            break;

        case 13: // load word
            this->aluOp = ALU::ADD;
            this->regWrite = true;
            this->memToReg = true;
            this->aluSrc = true;

            break;

        case 14: // jump
            this->jump = true;

            break;
    }
}

bool Control::getMemToReg()
{
    return memToReg;
}

bool Control::getJump()
{
    return jump;
}

bool Control::getBranch()
{
    return branch;
}

int Control::getAluOp()
{
    return aluOp;
}

bool Control::getAluSrc()
{
    return aluSrc;
}

bool Control::getRegDst()
{
    return regDst;
}

bool Control::getMemRead()
{
    return memRead;
}

bool Control::getMemWrite()
{
    return memWrite;
}

bool Control::getRegWrite()
{
    return regWrite;
}

