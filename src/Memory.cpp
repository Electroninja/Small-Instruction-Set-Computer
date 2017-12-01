#include "Memory.h"

Memory::Memory()
{

}

Memory::~Memory()
{
    //dtor
}

int Memory::read(int address,int index)
{
    return memory[address][index];
}

void Memory::write(int input, int address,int index)
{
    memory[address][index] = input;
    return;
}

void Memory::writeCode(int opcode, int input, int address)
{
    memory[address][0] = opcode;
    memory[address][1] = input;
    return;
}

void Memory::print()
{
cout << endl;
for (int i=0;i<MAX_ADDRESS;i++)
    {
        cout << endl;
        cout << "Address:" << i  << " OP:"<< memory[i][0] << " DATA:" << memory[i][1];
    }
}
