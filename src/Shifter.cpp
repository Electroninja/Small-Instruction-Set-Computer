#include "Shifter.h"

Shifter::Shifter()
{
    //ctor
}

Shifter::~Shifter()
{
    //dtor
}

int Shifter::noShift(int a,FlagRegister &Flag)
{
    result = a;
    UpdateFlags(a,Flag);
    return result;
}

int Shifter::leftShift(int a,FlagRegister &Flag)
{
    result = a << 1;
    if(result > 127) Flag.setc();
    else Flag.clearc();
    UpdateFlags(a,Flag);
    return result;
}

int Shifter::rightShift(int a,FlagRegister &Flag)
{
    result = a >> 1;
    if(a%2 == 1) Flag.setc();
    else Flag.clearc();
    UpdateFlags(a,Flag);
    return result;
}

int Shifter::zeroClear(int a,FlagRegister &Flag)
{
    result = 0;
    Flag.clearc();
    UpdateFlags(a,Flag);
    return result;
}

void Shifter::UpdateFlags(int a, FlagRegister &Flag)
{
    if((a > 127 && result < 128) || (a < 128 && result > 127)) Flag.setv();
    else Flag.clearv();
    if (result>127)
    {
        Flag.setn();
    }
    else Flag.clearn();

    if (result == 0)
    {
        Flag.setz();
    }
    else Flag.clearz();
}
