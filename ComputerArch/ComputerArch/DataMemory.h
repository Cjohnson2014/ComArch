#ifndef DATAMEMORY_H
#define DATAMEMORY_H

#include <bitset>

#define MEM_SIZE 50

class DataMemory {

    public:

        DataMemory();
        std::bitset<16> get(int location);
        void set(int location, std::bitset<16> input); 
        void setAddress(std::bitset<4> address);
        void setWriteData(std::bitset<16> wd);
        void setControlLines(bool memWrite, bool memRead);

    private:

        std::bitset<16> memory[MEM_SIZE];
        std::bitset<16> wd;
        std::bitset<4> address;

        bool memWrite;
        bool memRead;

};

#endif
