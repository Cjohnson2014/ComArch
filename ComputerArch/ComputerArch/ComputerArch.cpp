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
    Pc.set(i);
    IM *im = new IM(bitset<16>(string("0000000000000000")));
    RegisterFile *rf = new RegisterFile();
    ALU *alu = new ALU();

    for (int j = 0; j < 3; j++)
    {
        /***** EX stage *****/
        bitset<4> aluResult = alu->setOp(ALU::ADD)
           ->setInput(bitset<4>(string("0001")), bitset<4>(string("0001")))
           ->execute();

        /***** ID stage *****/
        rf->set(im->getReadDataIM());

        /***** IF stage *****/
        Pc.set(++i);
        im->setIMAddress(Pc.get()); 

        /***** WHATS HAPPENING EACH TIME **********/

        cout << endl;
        cout << "\033[1;32m*********************\033[0m" << endl;
        cout << "\033[1;35m >>> IF\033[0m" << endl;
        cout << "Program Counter: " << Pc.get() << endl;
        cout << "Instruction Memory: " << im->getReadDataIM() << endl;
        cout << "\033[1;35m >>> ID\033[0m" << endl;
        cout << "Register File OpCode: " << rf->getOpCode() << endl;
        cout << "Register File RS: " << rf->getRs() << endl;
        cout << "Register File RD: " << rf->getRd() << endl;
        cout << "Register File RT: " << rf->getRt() << endl;
        cout << "Register File sign extend: " << rf->getSignExtend() << endl;
        cout << "ALU Result: " << aluResult << endl;
        cout << "ALU Zero Bit: " << alu->getZeroBit() << endl;
    }

    
    cout << endl << endl;

    return 0;
}

