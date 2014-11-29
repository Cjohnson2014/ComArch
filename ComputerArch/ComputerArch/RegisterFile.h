#ifndef REGISTERFILE_H
#define REGISTERFILE_H

#include <iostream>
#include <bitset>

class RegisterFile {

    public:

        enum Register {
            $zero = 0,
            $v0 = 1,
            $v1 = 2,
            $v2 = 3,
            $v3 = 4,
            $a0 = 5,
            $a1 = 6,
            $t0 = 7,
            $t1 = 8,
            $t2 = 9,
            $t3 = 10,
            $t4 = 11,
            $t5 = 12,
            $t6 = 13,
            $t7 = 14,
            $t8 = 15
        };

        RegisterFile();
        ~RegisterFile();

        void setRegisterValue(int reg, std::bitset<16> bit);
        std::bitset<16> getRegisterValue(int reg);

        void set(std::bitset<16> rf);

        RegisterFile setRegWrite(bool regWrite);
        // RegisterFile setRegRead(bool regRead);

        RegisterFile setRs(std::bitset<4> rs);
        void setRd(std::bitset<4> rd);
        RegisterFile setRt(std::bitset<4> rt);

        std::bitset<4> getOpCode();
        std::bitset<4> getRs();
        std::bitset<4> getRd();
        std::bitset<4> getRt();

        std::bitset<16> getSignExtend();

        RegisterFile setWd(std::bitset<4> wd);

        bool getRegWrite();
        // bool getRegRead();

        std::bitset<16> getRead1();
        std::bitset<16> getRead2();


    private:

        bool regWrite;
        // bool regRead;

        std::bitset<16> rf;

        std::bitset<4> opCode;
        std::bitset<4> rs;
        std::bitset<4> rd;
        std::bitset<4> rt;

        std::bitset<16> signExtend;

        std::bitset<4> wd;

        std::bitset<16> zero;
        std::bitset<16> v0;
        std::bitset<16> v1;
        std::bitset<16> v2;
        std::bitset<16> v3;
        std::bitset<16> a0;
        std::bitset<16> a1;
        std::bitset<16> t0;
        std::bitset<16> t1;
        std::bitset<16> t2;
        std::bitset<16> t3;
        std::bitset<16> t4;
        std::bitset<16> t5;
        std::bitset<16> t6;
        std::bitset<16> t7;
        std::bitset<16> t8;
};

#endif
