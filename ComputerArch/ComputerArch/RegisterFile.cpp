#include "RegisterFile.h"

#include <bitset>

RegisterFile::RegisterFile()
{
    // nothing here yet
}

RegisterFile::~RegisterFile()
{
    delete this;
}

RegisterFile* RegisterFile::setRegWrite(bool regWrite)
{
    this->regWrite = regWrite;
    return this;
}

RegisterFile* RegisterFile::setRegRead(bool regRead)
{
    this->regRead = regRead;
    return this;
}

RegisterFile* RegisterFile::setRs(std::bitset<4> rs)
{
    this->rs = rs;
    return this;
}

RegisterFile* RegisterFile::setRd(std::bitset<4> rd)
{
    this->rd = rd;
    return this;
}

RegisterFile* RegisterFile::setRt(std::bitset<4> rt)
{
    this->rt = rt;
    return this;
}

RegisterFile* RegisterFile::setWd(std::bitset<4> wd)
{
    this->wd = wd;
    return this;
}

std::bitset<4> RegisterFile::getRead1()
{
    return this->read1;
}

std::bitset<4> RegisterFile::getRead2()
{
    return this->read2;
}
