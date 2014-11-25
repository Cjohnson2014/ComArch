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

void RegisterFile::set(std::bitset<16> rf)
{
    this->rf = rf;

    std::bitset<4> opCode;
    opCode[0] = rf[12];
    opCode[1] = rf[13];
    opCode[2] = rf[14];
    opCode[3] = rf[15];

    std::bitset<4> rs;
    rs[0] = rf[4];
    rs[1] = rf[5];
    rs[2] = rf[6];
    rs[3] = rf[7];

    std::bitset<4> rt;
    rt[0] = rf[8];
    rt[1] = rf[9];
    rt[2] = rf[10];
    rt[3] = rf[11];

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

RegisterFile RegisterFile::setRd(std::bitset<4> rd)
{
    this->rd = rd;
    return *this;
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
    return this->read1;
}

std::bitset<16> RegisterFile::getRead2()
{
    return this->read2;
}
