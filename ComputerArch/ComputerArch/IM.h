#ifndef IM_H_INCLUDED
#define IM_H_INCLUDED

#include <iostream>
#include <bitset>
#include <string>

#define ARRAY_SIZE 7

class IM {

    public:

        static const std::bitset<16> machinecode[ARRAY_SIZE];

        IM(std::bitset<16> init);
        ~IM();

        IM setIMRead(bool IMRead);

        void setIMAddress(int IMaddress);

        bool getIMRead();

        std::bitset<16> getReadDataIM();

    private:

        bool IMRead;

        int IMaddress;

        std::bitset<16> readDataIM;
};

#endif // IM_H_INCLUDED
