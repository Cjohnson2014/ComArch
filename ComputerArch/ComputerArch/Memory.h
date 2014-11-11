#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED

#include <iostream>
#include <bitset>

class Memory {

    public:
        Memory();
        ~Memory();

        Memory* setMemWrite(bool MemWrite);
        Memory* setMemRead(bool MemRead);

        Memory* setAddress(std::bitset<16> address);
        Memory* setWriteDataMem(std::bitset<16> writeDataMem);

        bool getMemWrite();
        bool getMemRead();

        std::bitset<16> getReadDataMem();

    private:

        bool memWrite;
        bool memRead;

        std::bitset<16> address;

        std::bitset<16> writeDataMem;

        std::bitset<16> readDataMem;
};

#endif // MEMORY_H_INCLUDED
