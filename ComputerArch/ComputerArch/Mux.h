#include <bitset>
class Mux
{
public:
	Mux();
	~Mux();
	void setControlLine(bool control);
	std::bitset<16> getOutput();
	void setInput1(std::bitset<16> input1);
	void setInput0(std::bitset<16> input0);
private:
	
	std::bitset<16> output;
	std::bitset<16> input1;
	std::bitset<16> input0;
	bool contol;

};

Mux::Mux()
{
	output=0;
	input1=0;
	input0=0;
}

Mux::~Mux()
{
	delete this
}