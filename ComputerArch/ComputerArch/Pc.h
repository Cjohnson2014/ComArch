#ifndef Pc.h
#include <bitset>
class Pc
{
public:
	Pc();
	~Pc();
	std::bitset<16>input;
	std::bitset<16>output;
	std::bitset<16>set();
	std::bitset<16>get();

private:
	std::bitset<16> current;
	
};

Pc::Pc()
{
}

Pc::~Pc()
{
}

#endif // !Pc.h