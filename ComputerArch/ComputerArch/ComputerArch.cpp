// ComputerArch.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <bitset>

#define ARRAY_SIZE 2

using namespace std;

bitset<16> machinecode[ARRAY_SIZE] = {
    bitset<16>(string("0101000001110001")),
    bitset<16>(string("0111011010000111"))
};

int main(int argc, char* argv[])
{
    // printing out values just so I don't get a
    // unused variable warning (bugging me)
    cout << "arg count: " << argc << endl;
    cout << "arg vals: " << argv << endl;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << machinecode[i] << endl;
        // read these files into memory.
        // probably wont need a loop
    }

    return 0;
}

