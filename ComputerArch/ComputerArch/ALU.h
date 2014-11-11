#ifndef ALU_H
#define ALU_H

#include <bitset>

class ALU {

    public:

        enum ALUOp {
            AND = 1,
            ADD = 2,
            XOR = 3,
            OR  = 4
        };

        ALU();
        ~ALU();

        ALU setOp(ALUOp op);
        ALU setInput(std::bitset<4> a, std::bitset<16> b);
        
        void execute();

        std::bitset<1> getZeroBit();

    private:

        ALUOp op;

        std::bitset<4> a;
        std::bitset<16> b;

        std::bitset<1> zeroBit;

};

#endif
