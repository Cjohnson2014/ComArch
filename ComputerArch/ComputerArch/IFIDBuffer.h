#ifndef IFIDBUFFER_H
#define IFIDBUFFER_H

#include <bitset>

class IFIDBuffer {

    public:
        std::bitset<16> getProgramCounter();
        std::bitset<16> getInstructionMemory();
        void setProgramCounter(std::bitset<16> pc);
        void setInstructionMemory(std::bitset<16> im);

    private:
        std::bitset<16> programCounter;
        std::bitset<16> instructionMemory;

};

#endif

