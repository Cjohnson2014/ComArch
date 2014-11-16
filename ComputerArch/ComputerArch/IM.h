#ifndef IM_H_INCLUDED
#define IM_H_INCLUDED

#include <iostream>
#include <bitset>

class IM {

    public:
        IM();
        ~IM();

        IM setIMWrite(bool IMWrite);
        IM setIMRead(bool IMRead);

        IM setIMAddress(std::bitset<16> IMaddress);
        IM setWriteDataIM(std::bitset<16> writeDataIM);

        bool getIMWrite();
        bool getIMRead();

        std::bitset<16> getReadDataIM();

    private:

        bool IMWrite;
        bool IMRead;

        std::bitset<16> IMaddress;

        std::bitset<16> writeDataIM;

        std::bitset<16> readDataIM;
};

#endif // IM_H_INCLUDED
