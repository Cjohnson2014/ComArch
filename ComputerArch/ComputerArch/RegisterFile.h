#ifndef REGISTERFILE_H
#define REGISTERFILE_H

#include <iostream>
#include <bitset>

class RegisterFile {

    public:

        RegisterFile();
        ~RegisterFile();

        void set(std::bitset<16> rf);

        RegisterFile setRegWrite(bool regWrite);
        // RegisterFile setRegRead(bool regRead);

        RegisterFile setRs(std::bitset<4> rs);
        RegisterFile setRd(std::bitset<4> rd);
        RegisterFile setRt(std::bitset<4> rt);

        std::bitset<4> getOpCode();
        std::bitset<4> getRs();
        std::bitset<4> getRd();
        std::bitset<4> getRt();

        std::bitset<16> getSignExtend();

        RegisterFile setWd(std::bitset<4> wd);

        bool getRegWrite();
        // bool getRegRead();

        std::bitset<4> getRead1();
        std::bitset<4> getRead2();


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
};

#endif
