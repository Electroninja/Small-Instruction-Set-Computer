#include "MemBufReg.h"

MemBufReg::MemBufReg()
{
    //ctor
}

MemBufReg::~MemBufReg()
{
    //dtor
}
void MemBufReg::write(int input)
{
    op = 0;
    value = input;
    return;
}
void MemBufReg::write(int opcode, int input)
{
    op = opcode;
    value = input;
    return;
}
int MemBufReg::readOpCode()
{
    return op;
}
