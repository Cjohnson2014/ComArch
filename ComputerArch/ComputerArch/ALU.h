#ifndef ALU_H
#define ALU_H

#include <bitset>

class ALU {

    public:

        enum ALUOp {
            AND = 1,
            ADD = 2,
            XOR = 3,
            OR  = 4,
            SUB = 5,
            ANDI = 6,
            ORI = 7,
            SLT = 8,
            SLL = 9,
            SRL = 10,
            ADDI = 11,
            BNE = 12,
            SUBI = 13,
        };

        ~ALU();

        ALU *setOp(int op);
        // ALU *setInput(std::bitset<4> a, std::bitset<4> b);
        ALU *setInput(std::bitset<16> a, std::bitset<16> b);
        
        std::bitset<16> execute();

        std::bitset<1> getZeroBit();

    private:

        int op;

        std::bitset<4> a4;
        std::bitset<4> b4;

        std::bitset<16> a16;
        std::bitset<16> b16;

        std::bitset<1> zeroBit;

};

#endif
