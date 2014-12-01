#include "Buffer.h"


Buffer::Buffer(void)
{
    this->rd = 0;
    this->Jump = 0;
    this->memReadData = 0;
    this->ReadWrite = 0;
    this->Read1 = 0;
    this->Read2 = 0;
    this->RegWrite = 0;
    this->MemRead = 0;
    this->add = 0;
    this->instruction = 0;
    this->addResult = 0;
    this->MemWrite = 0;
    this->MemtoReg = 0;
    this->SignEx = 0;
    this->pc = 0;
    this->AluSrc = 0;
    this->AluOp = 0;
    this->AluZero = 0;
    this->AluResult = 0;
    this->Branch = 0;
    this->rs = 0;
    this->rt = 0;
}


void Buffer::setReadWrite(bool readWrite)
{
    ReadWrite=readWrite;
}
void Buffer:: setAluSrc(bool aluSrc){
    AluSrc=aluSrc;

}
void Buffer:: setJump(bool jump){
    Jump=jump;
}
void Buffer:: setMemtoReg(bool memoReg)
{
    MemtoReg=memoReg;
}
void Buffer:: setBranch(bool branch)
{
    Branch=branch;
}
void Buffer::setMemWrite(bool memwrite)
{
    MemWrite=memwrite;
}
void Buffer:: setRegwrite(bool regwerite)
{
    RegWrite=regwerite;
}
void Buffer:: setAluOp(int aluop)
{
    AluOp=aluop;
}
void Buffer:: setRead1(std::bitset<16> read1)
{
    this->Read1=read1;
}
void Buffer::setRead2(std::bitset<16> read2)
{
    this->Read2=read2;
}
void Buffer:: setSignEx(std::bitset<16> signex)
{
    SignEx=signex;
}

void Buffer::setRegDst(std::bitset<4> rd)
{
    this->rd = rd;
}

void Buffer::setpc(int pc)
{
    this->pc = pc;
}

void Buffer::setrt(std::bitset<4> rt)
{
    this->rt = rt;
}

void Buffer::setrs(std::bitset<4> rs)
{
    this->rs = rs;
}

std::bitset<4> Buffer::getrs()
{
    return this->rs;
}

std::bitset<4> Buffer::getrt()
{
    return this->rt;
}

int Buffer::getpc()
{
    return this->pc;
}

std::bitset<4> Buffer::getRegDst()
{
    return this->rd;
}



bool Buffer:: getAluSrc(){
    return AluSrc;
}
bool Buffer:: getJump()
{return Jump;}
bool Buffer:: getMemtoReg()
{return MemtoReg;}
bool Buffer:: getBranch()
{return Branch;}
bool Buffer:: getMemWrite()
{return MemWrite;}
bool Buffer:: getRegwrite()
{return RegWrite;}
int  Buffer:: getAluOp()
{return AluOp;}
std::bitset<16> Buffer:: getRead1()
{return this->Read1;}
std::bitset<16> Buffer:: getRead2()
{return this->Read2;}
std::bitset<16> Buffer:: getSignEx()
{return SignEx;}

void Buffer::setAdd(int add){Buffer::add= add;}
int Buffer::getAdd(){return add;}
void Buffer::setInstruction(std::bitset<16> instruction){Buffer::instruction=instruction;}
std::bitset<16> Buffer::getInstruction(){return instruction;}
void Buffer::setAddResult(int addResult){Buffer::addResult=addResult;}
int Buffer::getAddResult(){return addResult;}
void Buffer::setAluZero(int AluZero){Buffer::AluZero=AluZero;}
int Buffer::getAluZero(){return AluZero;}
void Buffer::setAluResult(std::bitset<16> AluResult){this->AluResult=AluResult;}
std::bitset<16> Buffer::getAluresult(){return this->AluResult;}
std::bitset<16> Buffer::getMemoryReadData(){return memReadData;}
void Buffer::setMemoryRead(std::bitset<16> memReadData){this->memReadData=memReadData;}
