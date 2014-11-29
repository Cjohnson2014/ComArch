// ComputerArch.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <bitset>

// our headers
#include "Pc.h"
#include "RegisterFile.h"
#include "IM.h"
#include "ALU.h"
#include "Control.h"
#include "Mux.h"
#include "DataMemory.h"

// using standard namespace
using namespace std;

/**
 * Begin main execution
 */
int main(int argc, char* argv[])
{
    // printing out values just so I don't get a
    // unused variable warning (bugging me)
    cout << "arg count: " << argc << endl;
    cout << "arg vals: " << argv << endl;

    int i = -1;

    Pc Pc;
    Control control;
    DataMemory dm;

    IM *im = new IM(bitset<16>(string("0000000000000000")));
    RegisterFile *rf = new RegisterFile();
    ALU *alu = new ALU();

    Mux regDstMux;
    Mux aluSrcMux;
    Mux memToRegMux;

    bitset<16> aluResult;
    bitset<16> zero = bitset<16>(0x0000);

    rf->setRegisterValue(RegisterFile::$v0, bitset<16>(0x0040));
    rf->setRegisterValue(RegisterFile::$v1, bitset<16>(0x1010));
    rf->setRegisterValue(RegisterFile::$v2, bitset<16>(0x000f));
    rf->setRegisterValue(RegisterFile::$v3, bitset<16>(0x00f0));
    rf->setRegisterValue(RegisterFile::$a0, bitset<16>(0x0010));
    rf->setRegisterValue(RegisterFile::$a1, bitset<16>(0x0005));
    
    dm.set(RegisterFile::$a0, bitset<16>(0x0101));
    dm.set(RegisterFile::$a0 + 1, bitset<16>(0x0110));
    dm.set(RegisterFile::$a0 + 2, bitset<16>(0x0011));
    dm.set(RegisterFile::$a0 + 3, bitset<16>(0x00f0));
    dm.set(RegisterFile::$a0 + 4, bitset<16>(0x00ff));

    Pc.set(i);

    for (int j = 0; j < 8; j++)
    {
        /*
         * WB Stage
         */

        memToRegMux.setInput0(aluResult);
        memToRegMux.setInput1(dm.get(aluResult.to_ulong()));
        memToRegMux.setControlLine(control.getMemToReg());

        /*
         * MEM Stage
         */

        dm.setControlLines(control.getMemWrite(), control.getMemRead());
        dm.set(aluResult.to_ulong(), rf->getRead2());


        /*
         * EX Stage
         */

        aluSrcMux.setInput0(rf->getRead2());
        aluSrcMux.setInput1(rf->getSignExtend());
        aluSrcMux.setControlLine(control.getAluSrc());
        aluResult = alu->setOp(control.getAluOp())
           ->setInput(rf->getRead1(), aluSrcMux.getOutput())
           ->execute();

        /*
         * ID Stage
         */

        // rf->setRegisterValue((rf->getRd()).to_ulong(), memToRegMux.getOutput());
        rf->setRegisterValue((rf->getRd()).to_ulong(), aluResult);

        rf->set(im->getReadDataIM());
        control.update(rf->getOpCode());

        // need to convert rt and rd to 16 bit values to be
        // used with the mux
        bitset<16> rt = zero;
        bitset<16> rd = zero;

        rt[15] = rf->getRt()[3];
        rt[14] = rf->getRt()[2];
        rt[13] = rf->getRt()[1];
        rt[12] = rf->getRt()[0];

        rd[15] = rf->getRd()[3];
        rd[14] = rf->getRd()[2];
        rd[13] = rf->getRd()[1];
        rd[12] = rf->getRd()[0];

        regDstMux.setInput0(rt);
        regDstMux.setInput1(rd);
        regDstMux.setControlLine(control.getRegDst());

        // need to convert mux output to 4 bit value
        // for RegisterFile's setRd()
        bitset<4> regdst;

        regdst[3] = regDstMux.getOutput()[15];
        regdst[2] = regDstMux.getOutput()[14];
        regdst[1] = regDstMux.getOutput()[13];
        regdst[0] = regDstMux.getOutput()[12];

        rf->setRd(regdst);

        /*
         * IF Stage
         */

        Pc.set(++i);
        im->setIMAddress(Pc.get()); 

        /***** WHATS HAPPENING EACH TIME **********/

        cout << endl;
        cout << "\033[1;33m*********************\033[0m" << endl;
        cout << "\033[1;35m >>> IF\033[0m" << endl;
        cout << "Program Counter: " << Pc.get() << endl;
        cout << "Instruction Memory: " << im->getReadDataIM() << endl;
        cout << "\033[1;35m >>> ID\033[0m" << endl;
        cout << "Register File OpCode: " << rf->getOpCode() << endl;
        cout << "Register File RS: " << rf->getRs() << endl;
        cout << "Register File RT: " << rf->getRt() << endl;
        cout << "Register File RD: " << rf->getRd() << endl;
        cout << "Register File sign extend: " << rf->getSignExtend() << endl;
        cout << "\033[1;35m >>> EX\033[0m" << endl;
        cout << "ALU Result: " << aluResult << endl;
        cout << "ALU Zero Bit: " << alu->getZeroBit() << endl;
        cout << "\033[1;34m === Register Values ===\033[0m" << endl;

        cout << "$v0: " << rf->getRegisterValue(RegisterFile::$v0) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$v0)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$v1: " << rf->getRegisterValue(RegisterFile::$v1) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$v1)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$v2: " << rf->getRegisterValue(RegisterFile::$v2) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$v2)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$v3: " << rf->getRegisterValue(RegisterFile::$v3) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$v3)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$a0: " << rf->getRegisterValue(RegisterFile::$a0) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$a0)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$a1: " << rf->getRegisterValue(RegisterFile::$a1) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$a1)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t0: " << rf->getRegisterValue(RegisterFile::$t0) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t0)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t1: " << rf->getRegisterValue(RegisterFile::$t1) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t1)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t2: " << rf->getRegisterValue(RegisterFile::$t2) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t2)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t3: " << rf->getRegisterValue(RegisterFile::$t3) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t3)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t4: " << rf->getRegisterValue(RegisterFile::$t4) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t4)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t5: " << rf->getRegisterValue(RegisterFile::$t5) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t5)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t6: " << rf->getRegisterValue(RegisterFile::$t6) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t6)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t7: " << rf->getRegisterValue(RegisterFile::$t7) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t7)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t8: " << rf->getRegisterValue(RegisterFile::$t8) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t8)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "\033[1;34m === Memory Values ===\033[0m" << endl;

        cout << "Mem[$a0]:   " << dm.get(RegisterFile::$a0)
            << " \033[1;32m" << (long)(dm.get(RegisterFile::$a0).to_ulong())
            << "\033[0m"
            << endl;

        cout << "Mem[$a0+2]: " << dm.get(RegisterFile::$a0 + 1)
            << " \033[1;32m" << (long)(dm.get(RegisterFile::$a0 + 1).to_ulong())
            << "\033[0m"
            << endl;


        cout << "Mem[$a0+4]: " << dm.get(RegisterFile::$a0 + 2)
            << " \033[1;32m" << (long)(dm.get(RegisterFile::$a0 + 2).to_ulong())
            << "\033[0m"
            << endl;


        cout << "Mem[$a0+6]: " << dm.get(RegisterFile::$a0 + 3)
            << " \033[1;32m" << (long)(dm.get(RegisterFile::$a0 + 3).to_ulong())
            << "\033[0m"
            << endl;


        cout << "Mem[$a0+8]: " << dm.get(RegisterFile::$a0 + 4)
            << " \033[1;32m" << (long)(dm.get(RegisterFile::$a0 + 4).to_ulong())
            << "\033[0m"
            << endl;

    }

    
    cout << endl << endl;

    return 0;
}

