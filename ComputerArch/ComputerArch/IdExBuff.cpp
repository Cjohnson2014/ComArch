#include "IdExBuff.h"


IdExBuff::IdExBuff(void)
{
}


IdExBuff::~IdExBuff(void)
{
    delete this;
}

void IdExBuff::setReadWrite(bool readWrite)
{
    ReadWrite=readWrite;
}

void IdExBuff:: setAluSrc(bool aluSrc){
    AluSrc=aluSrc;

}

void IdExBuff:: setJump(bool jump){
    Jump=jump;
}

void IdExBuff:: setMemtoReg(bool memoReg)
{
    MemtoReg=memoReg;
}

void IdExBuff:: setBranch(bool branch)
{
    Branch=branch;
}

void IdExBuff::setMemWrite(bool memwrite)
{
    MemWrite=memwrite;
}
void IdExBuff:: setRegwrite(bool regwerite)
{
    RegWrite=regwerite;
}
void IdExBuff:: setAluOp(int aluop)
{
    AluOp=aluop;
}
void IdExBuff:: setRead1(std::bitset<16> read1)
{
    Read1=read1;
}
void IdExBuff:: setRead2(std::bitset<16> read2)
{
    Read2=read2;
}
void IdExBuff:: setSignEx(std::bitset<16> signex)
{
    SignEx=signex;
}

bool IdExBuff:: getAluSrc(){
    return AluSrc;
}

bool IdExBuff:: getJump()
{return Jump;}

bool IdExBuff:: getMemtoReg()
{return MemtoReg;}

bool IdExBuff:: getBranch()
{return Branch;}

bool IdExBuff:: getMemWrite()
{return MemWrite;}

bool IdExBuff:: getRegwrite()
{return RegWrite;}

int  IdExBuff:: getAluOp()
{return AluOp;}

std::bitset<16> IdExBuff:: getRead1()
{return Read1;}

std::bitset<16> IdExBuff:: getRead2()
{return Read2;}

std::bitset<16> IdExBuff:: getSignEx()
{return SignEx;}

