#pragma once
#include <bitset>
class Buffer
{
public:
	Buffer(void);
	~Buffer(void);
	void setAdd(int add);
	int getAdd();
	void setInstruction(std::bitset<16> instruction);
	std::bitset<16> getInstruction();
	void setAddResult(int addResult);
	int getAddResult();
	void setAluZero(int AluZero);
	int getAluZero();
	void setAluResult(std::bitset<16> Alu);
	std::bitset<16>getAluresult();
	std::bitset<16> getMemoryReadData();
	void setMemoryRead(std::bitset<16> memReadData);
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
		int add;
		std::bitset<16> instruction;
		int addResult;
		int AluZero;
		std::bitset<16> AluResult;
		std::bitset<16>memReadData;
	
};

