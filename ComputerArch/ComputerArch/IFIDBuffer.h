#ifndef IFIDBUFFER_H
#define IFIDBUFFER_H

#include <bitset>

class IFIDBuffer {

    public:
        int getProgramCounter();
        std::bitset<16> getInstructionMemory();
        void setProgramCounter(int pc);
        void setInstructionMemory(std::bitset<16> im);

    private:
        int programCounter;
        std::bitset<16> instructionMemory;

};

#endif

