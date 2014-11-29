#include "RegisterFile.h"
#include <iostream>
#include <bitset>

RegisterFile::RegisterFile()
{
    // nothing here yet
}

RegisterFile::~RegisterFile()
{
    delete this;
}

void RegisterFile::setRegisterValue(int reg, std::bitset<16> bit)
{

    switch (reg)
    {
        case 0:
            this->zero = bit;
            break;

        case 1:
            this->v0 = bit;
            break;

        case 2:
            this->v1 = bit;
            break;

        case 3:
            this->v2 = bit;
            break;

        case 4:
            this->v3 = bit;
            break;

        case 5:
            this->a0 = bit;
            break;

        case 6:
            this->a1 = bit;
            break;

        case 7:
            this->t0 = bit;
            break;

        case 8:
            this->t1 = bit;
            break;

        case 9:
            this->t2 = bit;
            break;

        case 10:
            this->t3 = bit;
            break;

        case 11:
            this->t4 = bit;
            break;

        case 12:
            this->t5 = bit;
            break;

        case 13:
            this->t6 = bit;
            break;

        case 14:
            this->t7 = bit;
            break;

        case 15:
            this->t8 = bit;
            break;

    }

}

std::bitset<16> RegisterFile::getRegisterValue(int reg)
{

    switch (reg)
    {
        case 0:
            return this->zero;
            break;

        case 1:
            return this->v0;
            break;

        case 2:
            return this->v1;
            break;

        case 3:
            return this->v2;
            break;

        case 4:
            return this->v3;
            break;

        case 5:
            return this->a0;
            break;

        case 6:
            return this->a1;
            break;

        case 7:
            return this->t0;
            break;

        case 8:
            return this->t1;
            break;

        case 9:
            return this->t2;
            break;

        case 10:
            return this->t3;
            break;

        case 11:
            return this->t4;
            break;

        case 12:
            return this->t5;
            break;

        case 13:
            return this->t6;
            break;

        case 14:
            return this->t7;
            break;

        case 15:
            return this->t8;
            break;

    }

    return 0;
}


void RegisterFile::set(std::bitset<16> rf)
{
    this->rf = rf;

    std::bitset<4> opCode;
    opCode[0] = rf[12];
    opCode[1] = rf[13];
    opCode[2] = rf[14];
    opCode[3] = rf[15];

    std::bitset<4> rt;
    rt[0] = rf[4];
    rt[1] = rf[5];
    rt[2] = rf[6];
    rt[3] = rf[7];

    std::bitset<4> rs;
    rs[0] = rf[8];
    rs[1] = rf[9];
    rs[2] = rf[10];
    rs[3] = rf[11];

    std::bitset<4> rd;
    rd[0] = rf[0];
    rd[1] = rf[1];
    rd[2] = rf[2];
    rd[3] = rf[3];

    std::bitset<16> signExtend;
    signExtend[0] = rf[0];
    signExtend[1] = rf[1];
    signExtend[2] = rf[2];
    signExtend[3] = rf[3];

    for (int i = 15; i > 3; i--)
    {
        signExtend[i] = std::bitset<1>(std::string("0"))[0];
    }

    this->opCode = opCode;
    this->rs = rs;
    this->rt = rt;
    this->rd = rd;
    this->signExtend = signExtend;
}

RegisterFile RegisterFile::setRegWrite(bool regWrite)
{
    this->regWrite = regWrite;
    return *this;
}

/*
RegisterFile RegisterFile::setRegRead(bool regRead)
{
    this->regRead = regRead;
    return *this;
}
*/

std::bitset<4> RegisterFile::getOpCode()
{
    return this->opCode;
}

std::bitset<4> RegisterFile::getRs()
{
    return this->rs;
}

std::bitset<4> RegisterFile::getRd()
{
    return this->rd;
}

std::bitset<4> RegisterFile::getRt()
{
    return this->rt;
}

std::bitset<16> RegisterFile::getSignExtend()
{
    return this->signExtend;
}

RegisterFile RegisterFile::setRs(std::bitset<4> rs)
{
    this->rs = rs;
    return *this;
}

void RegisterFile::setRd(std::bitset<4> rd)
{
    this->rd = rd;
}

RegisterFile RegisterFile::setRt(std::bitset<4> rt)
{
    this->rt = rt;
    return *this;
}

RegisterFile RegisterFile::setWd(std::bitset<4> wd)
{
    this->wd = wd;
    return *this;
}

bool RegisterFile::getRegWrite()
{
    return this->regWrite;
}
/*
bool RegisterFile::getRegRead()
{
    return this->regRead;
}
*/
std::bitset<16> RegisterFile::getRead1()
{
    return this->getRegisterValue((this->rs).to_ulong());
}

std::bitset<16> RegisterFile::getRead2()
{
    return this->getRegisterValue((this->rt).to_ulong());
}
