#include "Buffer.h"


Buffer::Buffer(void)
{
}


Buffer::~Buffer(void)
{
	delete this;
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
		Read1=read1;
}
void Buffer:: setRead2(std::bitset<16> read2)
{
		Read2=read2;
}
void Buffer:: setSignEx(std::bitset<16> signex)
{
		SignEx=signex;
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
	{return Read1;}
	std::bitset<16> Buffer:: getRead2()
	{return Read2;}
	std::bitset<16> Buffer:: getSignEx()
	{return SignEx;}
