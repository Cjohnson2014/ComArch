#ifndef IM_H_INCLUDED
#define IM_H_INCLUDED

#include <iostream>
#include <bitset>
#include <string>

#define ARRAY_SIZE 1

class IM {

    public:

        static const std::bitset<16> machinecode[ARRAY_SIZE];

        IM();
        ~IM();

        IM setIMRead(bool IMRead);

        IM setIMAddress(std::bitset<16> IMaddress);

        bool getIMRead();

        std::bitset<16> getReadDataIM();

    private:

        bool IMRead;

        std::bitset<16> IMaddress;

        std::bitset<16> readDataIM;
};

#endif // IM_H_INCLUDED
