#pragma once
#include <bitset>
class Buffer
{
public:
	Buffer(void);
	~Buffer(void);
	void 
	void setReadWrite(bool readWrite);
	void setAluSrc(bool aluSrc);
	void setJump(bool jump);
	void setMemtoReg(bool memoReg);
	void setBranch(bool branch);
	void setMemWrite(bool memwrite);
	void setRegwrite(bool regwerite);
	void setAluOp(int aluop);
	void setRead1(std::bitset<16> read1);
	void setRead2(std::bitset<16> read2);
	void setSignEx(std::bitset<16> signex);
	
	bool getAluSrc();
	bool getJump();
	bool getMemtoReg();
	bool getBranch();
	bool getMemWrite();
	bool getRegwrite();
	int getAluOp();
	std::bitset<16> getRead1();
	std::bitset<16> getRead2();
	std::bitset<16> getSignEx();

private:
		bool ReadWrite;
		bool AluSrc;
		bool Jump;
		bool MemtoReg;
		bool Branch;
		bool MemWrite;
		bool MemRead;
		bool RegWrite;
		int AluOp;
		std::bitset<16> Read1;
		std::bitset<16> Read2;
		std::bitset<16> SignEx;

};

