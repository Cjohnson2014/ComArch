#ifndef PC_H
#define PC_H

#include <bitset>

class Pc
{
public:
	Pc();
	~Pc();

	
	void set(std::bitset<16> input);
	int get();
	

private:
	int input;
	int output;
	int current;
	
};




#endif // !Pc.h

