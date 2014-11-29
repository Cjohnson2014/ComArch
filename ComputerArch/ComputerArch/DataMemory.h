#ifndef DATAMEMORY_H
#define DATAMEMORY_H

#include <bitset>

#define MEM_SIZE 20

class DataMemory {

    public:

        std::bitset<16> get(int location);
        void set(int location, std::bitset<16> input); 

    private:

        std::bitset<16> memory[MEM_SIZE];

};

#endif
