// ComputerArch.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <bitset>

// our headers
#include "Pc.h"
#include "RegisterFile.h"
#include "IM.h"

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

    int i = 0;

    Pc Pc;
    Pc.set(i);
    IM *im = new IM(bitset<16>(string("0000000000000000")));
    RegisterFile *rf = new RegisterFile();
    
    while (true)
    {
        if (im->getReadDataIM() != bitset<16>(string("0000000000000000")))
        {
            break;
        }

        rf->setRF(im->getReadDataIM());
        im->setIMAddress(Pc.get()); 
        Pc.set(i++);

        /***** WHATS HAPPENING EACH TIME **********/

        cout << "Program Counter: " << Pc.get() << endl;
        cout << "Instruction Memory: " << im->getReadDataIM() << endl;
    }

    
    cout << endl << endl;

    return 0;
}

