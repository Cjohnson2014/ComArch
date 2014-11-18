#ifndef REGISTERFILE_H
#define REGISTERFILE_H

#include <iostream>
#include <bitset>

class RegisterFile {

    public:

        RegisterFile();
        ~RegisterFile();

        // RegisterFile setRegWrite(bool regWrite);
        RegisterFile setRegRead(bool regRead);

        RegisterFile setRs(std::bitset<4> rs);
        RegisterFile setRd(std::bitset<4> rd);
        RegisterFile setRt(std::bitset<4> rt);

        RegisterFile setWd(std::bitset<4> wd);

        bool getRegWrite();
        // bool getRegRead();

        std::bitset<16> getRead1();
        std::bitset<16> getRead2();


    private:

        bool regWrite;
        // bool regRead;

        std::bitset<4> rs;
        std::bitset<4> rd;
        std::bitset<4> rt;

        std::bitset<4> wd;

        std::bitset<16> read1;
        std::bitset<16> read2;
};

#endif
