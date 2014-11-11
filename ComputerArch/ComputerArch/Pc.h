#ifndef Pc.h
#include <bitset>
class Pc
{
public:
	Pc();
	~Pc();
	
	void set(std::bitset<16>input);
	std::bitset<16>get();

private:
	std::bitset<16>input;
	std::bitset<16>output;
	std::bitset<16> current;
	
};

Pc::Pc()
{
		current=std::bitset<16>(0);
}

Pc::~Pc()
{
}

#endif // !Pc.h