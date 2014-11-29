#ifndef IDEXBUFF_H
#define IDEXBUFF_H 

#include <bitset>

class IdExBuff {

    public:

        IdExBuff();
        ~IdExBuff();

        void setReadWrite(bool readWrite);
        void setAluSrc(bool alusrc);
        void setJump(bool jump);
        void setMemtoReg(bool memtoreg);
        void setBranch(bool branch);
        void setMemWrite(bool memwrite);
        void setRegwrite(bool regwrite);
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
        bool RegWrite;
        int AluOp;
        std::bitset<16> Read1;
        std::bitset<16> Read2;
        std::bitset<16> SignEx;

};

#endif
