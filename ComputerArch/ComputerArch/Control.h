#ifndef CONTROL_H
#define CONTROL_H

#include "ALU.h"

#include <bitset>

class Control {

    public:

        void update(std::bitset<4> opCode);

        int getAluOp();

        bool getJump();
        bool getRegDst();
        bool getMemToReg();
        bool getAluSrc();
        bool getBranch();
        bool getMemWrite();
        bool getMemRead();
        bool getRegWrite();

   private:
 
        int aluOp;

        bool jump;
        bool regDst;
        bool memToReg;
        bool aluSrc;
        bool branch;
        bool memWrite;
        bool memRead;
        bool regWrite;

};

#endif
