// ComputerArch.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <bitset>

// our headers
#include "Pc.h"

// size of the machine code array
#define ARRAY_SIZE 2

// using standard namespace
using namespace std;

/**
 * Define all machine code
 */
bitset<16> machinecode[ARRAY_SIZE] = {
    bitset<16>(string("0101000001110001")),
    bitset<16>(string("0111011010000111"))
    /**
     *
     * The rest of the machine code will go here.
     *
     */
};

/**
 * Begin main execution
 */
int main(int argc, char* argv[])
{
    // printing out values just so I don't get a
    // unused variable warning (bugging me)
    cout << "arg count: " << argc << endl;
    cout << "arg vals: " << argv << endl;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
		Pc Pc;
		Pc.set(machinecode[i]);
		cout << "Current Instruction"<< Pc.get() << "/n";

        // read these files into memory.
        // probably wont need a loop
    }

    return 0;
}

