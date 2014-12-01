// ComputerArch.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <bitset>


// our headers

//#include "Pc.h"
//#include "Clock.h"
//#include "IdExBuff.h"

// size of the machine code array
//#define ARRAY_SIZE 2

#include "Pc.h"
#include "RegisterFile.h"
#include "IM.h"
#include "ALU.h"
#include "Control.h"
#include "Mux.h"
#include "DataMemory.h"
#include "Buffer.h"

// using standard namespace
using namespace std;

/**
 * Begin main execution
 */
int main(int argc, char* argv[])
{
    // printing out values just so I don't get a
    // unused variable warning (bugging me)

    std::cout << "arg count: " << argc << endl;
    std::cout << "arg vals: " << argv << endl;

    /*
         bool done=false;
		//Pc Pc;
		//Clock Clock;
		//IdExBuff IdExBuff;
	//	while(!done)
	//		IdExBuff.setReadWrite(Clock.getEdge);
		//	Clock.toggleEdge();
			done = true;
		//}
		std::cout << "Program Complete press enter to finish:/n";
        */

    int i = -1;

    Pc Pc;
    Control control;
    DataMemory dm;

    IM *im = new IM(bitset<16>(string("0000000000000000")));
    RegisterFile *rf = new RegisterFile();
    ALU *alu = new ALU();

    Mux regDstMux;
    Mux aluSrcMux;
    Mux memToRegMux;
    Mux pcSrcMux;
    Mux jumpMux;

    Buffer IFIDBuffer;
    Buffer IDEXBuffer;
    Buffer EXMEMBuffer;
    Buffer MEMWBBuffer;

    bitset<16> aluResult;
    bitset<16> zero = bitset<16>(0x0000);

    rf->setRegisterValue(RegisterFile::$v0, bitset<16>(0x0040));
    rf->setRegisterValue(RegisterFile::$v1, bitset<16>(0x1010));
    rf->setRegisterValue(RegisterFile::$v2, bitset<16>(0x000f));
    rf->setRegisterValue(RegisterFile::$v3, bitset<16>(0x00f0));
    rf->setRegisterValue(RegisterFile::$a0, bitset<16>(0x0010));
    rf->setRegisterValue(RegisterFile::$a1, bitset<16>(0x0005));
    
    dm.set(rf->getRegisterValue(RegisterFile::$a0).to_ulong(), bitset<16>(0x0101));
    dm.set(rf->getRegisterValue(RegisterFile::$a0).to_ulong() + 1, bitset<16>(0x0110));
    dm.set(rf->getRegisterValue(RegisterFile::$a0).to_ulong() + 2, bitset<16>(0x0011));
    dm.set(rf->getRegisterValue(RegisterFile::$a0).to_ulong() + 3, bitset<16>(0x00f0));
    dm.set(rf->getRegisterValue(RegisterFile::$a0).to_ulong() + 4, bitset<16>(0x00ff));

    Pc.set(i);


    for (int j = 0; j < 25; j++)
    {

        /*
         * Forwarding
         */
		cout<<"Regwrite:"<<MEMWBBuffer.getRegwrite()<<endl;
		cout<<"MemtoReg:"<<MEMWBBuffer.getMemtoReg()<<endl;
		//cout<<Da
        if (MEMWBBuffer.getRegwrite()
                && MEMWBBuffer.getRegDst() != 0
                && MEMWBBuffer.getRegDst() == IDEXBuffer.getrs())
        {
			
            cout<<"mem flush rs: "<<endl;
            if (MEMWBBuffer.getMemtoReg())
            {
                cout<<"rs 1"<<endl;
<<<<<<< HEAD
				IDEXBuffer.setRead1(MEMWBBuffer.getMemoryReadData().to_ulong());
				cout<<"RS1 value "<<MEMWBBuffer.getMemoryReadData().to_ulong()<<endl;
=======
                IDEXBuffer.setRead1(dm.get(MEMWBBuffer.getMem.to_ulong()));
>>>>>>> origin/master
            }
            else
            {
                cout<<"rs 2: "<< MEMWBBuffer.getAluresult() <<endl;
                IDEXBuffer.setRead1(MEMWBBuffer.getAluresult());
            }
        }

        if (MEMWBBuffer.getRegwrite()
                && MEMWBBuffer.getRegDst() != 0
                && MEMWBBuffer.getRegDst() == IDEXBuffer.getrt())
        {

            cout<<"mem flush rt: "<<endl;
            if (MEMWBBuffer.getMemtoReg())
            {
                cout<<"rt 1"<<endl;
				IDEXBuffer.setRead2(dm.get(MEMWBBuffer.getMemoryReadData().to_ulong()));
			//	cout<<"RT Value :"<<dm.get(MEMWBBuffer.getMemoryReadData().to_ulong())<<endl;
;
            }
            else
            {
                cout<<"rt 2: "<< MEMWBBuffer.getAluresult() <<endl;

                IDEXBuffer.setRead2(MEMWBBuffer.getAluresult());
            }
        }

        if (EXMEMBuffer.getRegwrite()
                && EXMEMBuffer.getRegDst() != 0
                && EXMEMBuffer.getRegDst() == IDEXBuffer.getrs())
        {

            cout <<"ex flush rs"<<endl;
            IDEXBuffer.setRead1(EXMEMBuffer.getAluresult());
        }

        if (EXMEMBuffer.getRegwrite()
                && EXMEMBuffer.getRegDst() != 0
                && EXMEMBuffer.getRegDst() == IDEXBuffer.getrt())
        {

            cout <<"ex flush rt"<<endl;
            IDEXBuffer.setRead2(EXMEMBuffer.getAluresult());
        }


        /*
         * WB Stage
         */

        int memReadLocation = 0;

        if (MEMWBBuffer.getMemtoReg())
        {
            memReadLocation = MEMWBBuffer.getAluresult().to_ulong();
        }

        memToRegMux.setInput0(MEMWBBuffer.getAluresult());
<<<<<<< HEAD
        memToRegMux.setInput1(MEMWBBuffer.getMemoryReadData().to_ulong());
=======
        memToRegMux.setInput1();
>>>>>>> origin/master
        memToRegMux.setControlLine(MEMWBBuffer.getMemtoReg());

        if (MEMWBBuffer.getRegwrite())
        {
            rf->setRegisterValue(MEMWBBuffer.getRegDst().to_ulong(), memToRegMux.getOutput());
			cout <<"writeback memory read data"<< memToRegMux.getOutput() <<endl;
		}
        /*
         * MEM Stage
         */

        int memReadLocation2 = 0;

        if (MEMWBBuffer.getMemtoReg())
        {
            memReadLocation2 = EXMEMBuffer.getAluresult().to_ulong();
        }

        if (MEMWBBuffer.getMemRead())
        {
            MEMWBBuffer.setMemoryRead(dm.get(memReadLocation2));
        }

        dm.setControlLines(EXMEMBuffer.getMemWrite(), control.getMemRead());
        dm.set((EXMEMBuffer.getAluresult()).to_ulong(), EXMEMBuffer.getRead2());
		cout<<"DataMemory: "<<dm.get(EXMEMBuffer.getAluresult().to_ulong())<<endl;
        MEMWBBuffer.setMemtoReg(EXMEMBuffer.getMemtoReg());
        MEMWBBuffer.setAluResult(EXMEMBuffer.getAluresult());
        MEMWBBuffer.setMemoryRead(dm.get(EXMEMBuffer.getAluresult().to_ulong()));
        MEMWBBuffer.setRegDst(EXMEMBuffer.getRegDst());
        MEMWBBuffer.setrs(EXMEMBuffer.getrs());
        MEMWBBuffer.setrt(EXMEMBuffer.getrt());
        MEMWBBuffer.setRegwrite(EXMEMBuffer.getRegwrite());
		cout<<"DateMemoryBuffer"<<MEMWBBuffer.getMemoryReadData()<<endl;

        /*
         * EX Stage
         */

        aluSrcMux.setInput0(IDEXBuffer.getRead2());
        aluSrcMux.setInput1(IDEXBuffer.getSignEx());
        aluSrcMux.setControlLine(IDEXBuffer.getAluSrc());
		cout<<"AluSrcMux"<<IDEXBuffer.getAluSrc()<<endl;
        aluResult = 0;
        aluResult = alu->setOp(IDEXBuffer.getAluOp())
           ->setInput(IDEXBuffer.getRead1(), aluSrcMux.getOutput())
           ->execute();


        int aluZeroBit = 0;
        aluZeroBit = (alu->getZeroBit()).to_ulong();

        int shiftLeft = 0;
        int addResult = IDEXBuffer.getpc();
		cout<<"IDEXbuffer getpc; "<<addResult<<endl;
        int branch = 0;

        /*
        if (IFIDBuffer.getBranch()) 
        {
            im->setIMData(i, bitset<16>(0x0000));
            i++;
        }
        */


        shiftLeft = (IDEXBuffer.getSignEx()).to_ulong() << 0;
        addResult = IDEXBuffer.getpc() + shiftLeft;
        branch = IDEXBuffer.getBranch() & aluZeroBit;
		if (branch)
		{
			cout<<"getBranch:"<<IDEXBuffer.getBranch()<<endl;
			cout<<"ALUZero:"<<aluZeroBit<<endl;
		}
        EXMEMBuffer.setAluResult(aluResult);
        EXMEMBuffer.setRead2(IDEXBuffer.getRead2());
        EXMEMBuffer.setMemWrite(IDEXBuffer.getMemWrite());
        EXMEMBuffer.setMemtoReg(IDEXBuffer.getMemtoReg());
        EXMEMBuffer.setpc(addResult);
        EXMEMBuffer.setRegDst(IDEXBuffer.getRegDst());
        EXMEMBuffer.setrt(IDEXBuffer.getrt());
        EXMEMBuffer.setrs(IDEXBuffer.getrs());
        EXMEMBuffer.setRegwrite(IDEXBuffer.getRegwrite());
        EXMEMBuffer.setJump(IDEXBuffer.getJump());
        EXMEMBuffer.setBranch(branch);
        EXMEMBuffer.setAluOp(IDEXBuffer.getAluOp());
		EXMEMBuffer.setMemRead(IDEXBuffer.getMemRead());



		if ((branch && EXMEMBuffer.getAluZero()== 1) || IDEXBuffer.getJump() )
        {
            IFIDBuffer.setInstruction(bitset<16>(0x0000));
			cout << "Branch taken";
        }

        /*
         * ID Stage
         */


        rf->set(IFIDBuffer.getInstruction());
        control.update(rf->getOpCode());

        // need to convert rt and rd to 16 bit values to be
        // used with the mux
        bitset<16> rt = zero;
        bitset<16> rd = zero;

        rt[15] = rf->getRt()[3];
        rt[14] = rf->getRt()[2];
        rt[13] = rf->getRt()[1];
        rt[12] = rf->getRt()[0];

        rd[15] = rf->getRd()[3];
        rd[14] = rf->getRd()[2];
        rd[13] = rf->getRd()[1];
        rd[12] = rf->getRd()[0];

        regDstMux.setInput0(rt);
        regDstMux.setInput1(rd);
        regDstMux.setControlLine(control.getRegDst());

        // need to convert mux output to 4 bit value
        // for RegisterFile's setRd()
        bitset<4> regdst;

        regdst[3] = regDstMux.getOutput()[15];
        regdst[2] = regDstMux.getOutput()[14];
        regdst[1] = regDstMux.getOutput()[13];
        regdst[0] = regDstMux.getOutput()[12];

        rf->setRd(regdst);

        IDEXBuffer.setSignEx(rf->getSignExtend());
        IDEXBuffer.setRead1(rf->getRead1());
        IDEXBuffer.setRead2(rf->getRead2());
        IDEXBuffer.setRegDst(rf->getRd());
        IDEXBuffer.setJump(control.getJump());
        IDEXBuffer.setBranch(control.getBranch());
        IDEXBuffer.setRegwrite(control.getRegWrite());
        IDEXBuffer.setAluOp(control.getAluOp());
        IDEXBuffer.setAluSrc(control.getAluSrc());
        IDEXBuffer.setMemtoReg(control.getMemToReg());
        IDEXBuffer.setMemWrite(control.getMemWrite());
        IDEXBuffer.setpc(IFIDBuffer.getpc());

        IDEXBuffer.setrs(rf->getRs());
        IDEXBuffer.setrt(rf->getRt());
        // IDEXBuffer.setMemoryRead(control.getMemRead());

        if (rf->getOpCode() == 13)
        {
            im->setIMData(i, bitset<16>(0x0000));
            i--;
        }

        /*
        if (rf->getOpCode() == 10 
                || rf->getOpCode() == 11 
                || rf->getOpCode() == 14
                || rf->getOpCode() == 15)
        {
            im->setIMData(i, bitset<16>(0x0000));
            i++;
        }
        */

        /*
         * IF Stage
         */
        cout<<"control check: "<<EXMEMBuffer.getBranch()<<endl;
        cout<<"c check: "<<EXMEMBuffer.getpc()<<endl;

        pcSrcMux.setInput0(++i);
		pcSrcMux.setInput1(addResult);
		cout<< "i:"<<i<<endl;
		cout<<"addResult"<<addResult<<endl;
        pcSrcMux.setControlLine(EXMEMBuffer.getBranch());
		cout<<"PcSrcMux "<<EXMEMBuffer.getBranch()<<endl;

        if (EXMEMBuffer.getBranch() && EXMEMBuffer.getAluOp() != ALU::BNE){
            cout<<"if"<<endl;
            i = EXMEMBuffer.getBranch()+1;
        }

        jumpMux.setInput0(pcSrcMux.getOutput());
		cout<<shiftLeft<<endl;
        jumpMux.setInput1(shiftLeft);
        jumpMux.setControlLine(EXMEMBuffer.getJump());
		cout<<EXMEMBuffer.getJump()<<endl;
        Pc.set((jumpMux.getOutput().to_ulong()));
		cout<<jumpMux.getOutput().to_ulong()<<endl;
		i=Pc.get();
        im->setIMAddress(Pc.get()); 

        IFIDBuffer.setInstruction(im->getReadDataIM());
        IFIDBuffer.setpc(jumpMux.getOutput().to_ulong());

        /***** WHATS HAPPENING EACH TIME **********/
		
        cout << endl;
        cout << "\033[1;33m*********************\033[0m" << endl;

        cout << "\033[1;35m >>> IF\033[0m" << endl;

        cout << "Program Counter: " << Pc.get() << endl;
        cout << "Instruction Memory: " << im->getReadDataIM() << endl;

        cout << "\033[1;35m >>> ID\033[0m" << endl;

        cout << "Register File OpCode: " << rf->getOpCode() << endl;
        cout << "Register File RS: " << rf->getRs() << endl;
        cout << "Register File RT: " << rf->getRt() << endl;
        cout << "Register File RD: " << rf->getRd() << endl;
        cout << "Register File sign extend: " << rf->getSignExtend() << endl;

        cout << "\033[1;35m >>> EX\033[0m" << endl;

        cout << "ALU Result: " << aluResult << endl;
        cout << "ALU Zero Bit: " << alu->getZeroBit() << endl;

        cout << "\033[1;35m >>> MEM\033[0m" << endl;


        cout << "\033[1;34m === Register Values ===\033[0m" << endl;

        cout << "$v0: " << rf->getRegisterValue(RegisterFile::$v0) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$v0)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$v1: " << rf->getRegisterValue(RegisterFile::$v1) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$v1)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$v2: " << rf->getRegisterValue(RegisterFile::$v2) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$v2)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$v3: " << rf->getRegisterValue(RegisterFile::$v3) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$v3)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$a0: " << rf->getRegisterValue(RegisterFile::$a0) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$a0)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$a1: " << rf->getRegisterValue(RegisterFile::$a1) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$a1)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t0: " << rf->getRegisterValue(RegisterFile::$t0) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t0)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t1: " << rf->getRegisterValue(RegisterFile::$t1) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t1)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t2: " << rf->getRegisterValue(RegisterFile::$t2) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t2)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t3: " << rf->getRegisterValue(RegisterFile::$t3) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t3)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t4: " << rf->getRegisterValue(RegisterFile::$t4) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t4)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t5: " << rf->getRegisterValue(RegisterFile::$t5) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t5)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t6: " << rf->getRegisterValue(RegisterFile::$t6) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t6)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t7: " << rf->getRegisterValue(RegisterFile::$t7) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t7)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "$t8: " << rf->getRegisterValue(RegisterFile::$t8) 
            << " \033[1;32m" << (long)(rf->getRegisterValue(RegisterFile::$t8)).to_ulong()
            << "\033[0m"
            << endl;

        cout << "\033[1;34m === Memory Values ===\033[0m" << endl;

        cout << "Mem[$a0]:     " << dm.get((rf->getRegisterValue(RegisterFile::$a0)).to_ulong())
            << " \033[1;32m" 
            << (long)(dm.get((rf->getRegisterValue(RegisterFile::$a0)).to_ulong()).to_ulong())
            << "\033[0m"
            << endl;

        cout << "Mem[$a0 + 2]: " << dm.get((rf->getRegisterValue(RegisterFile::$a0)).to_ulong() + 1)
            << " \033[1;32m" 
            << (long)(dm.get((rf->getRegisterValue(RegisterFile::$a0)).to_ulong() + 1).to_ulong())
            << "\033[0m"
            << endl;

        cout << "Mem[$a0 + 4]: " << dm.get((rf->getRegisterValue(RegisterFile::$a0)).to_ulong() + 2)
            << " \033[1;32m" 
            << (long)(dm.get((rf->getRegisterValue(RegisterFile::$a0)).to_ulong() + 2).to_ulong())
            << "\033[0m"
            << endl;

        cout << "Mem[$a0 + 6]: " << dm.get((rf->getRegisterValue(RegisterFile::$a0)).to_ulong() + 3)
            << " \033[1;32m" 
            << (long)(dm.get((rf->getRegisterValue(RegisterFile::$a0)).to_ulong() + 3).to_ulong())
            << "\033[0m"
            << endl;

        cout << "Mem[$a0 + 8]: " << dm.get((rf->getRegisterValue(RegisterFile::$a0)).to_ulong() + 4)
            << " \033[1;32m" 
            << (long)(dm.get((rf->getRegisterValue(RegisterFile::$a0)).to_ulong() + 4).to_ulong())
            << "\033[0m"
            << endl;
		char a='a';
		cin>> a;
    }

    
    cout << endl << endl;
system("pause");
    return 0;
}

