#include <bitset>
class adder4
{
public:
	adder4();
	~adder4();
	std::bitset<16> get();
	std::bitset<16> add4();

private:
	std::bitset<16> addVal;
};

