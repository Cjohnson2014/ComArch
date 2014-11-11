#ifndef PC_H
#define PC_H

#include <bitset>

class Pc
{
public:
	Pc();
	~Pc();
<<<<<<< HEAD
	
	void set(std::bitset<16>input);
	std::bitset<16>get();
=======
	std::bitset<16> input;
	std::bitset<16> output;
	std::bitset<16> set();
	std::bitset<16> get();
>>>>>>> cdeeb4ae1f5fdde31191fb42794b619b9842c413

private:
	std::bitset<16>input;
	std::bitset<16>output;
	std::bitset<16> current;
	
};
<<<<<<< HEAD

Pc::Pc()
{
		current=std::bitset<16>(0);
}

Pc::~Pc()
{
}

#endif // !Pc.h
=======
#endif // !Pc.h
>>>>>>> cdeeb4ae1f5fdde31191fb42794b619b9842c413
