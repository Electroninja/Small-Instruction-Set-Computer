#include "ArithmeticUnit.h"

ArithmeticUnit::ArithmeticUnit()
{
    //ctor
}

ArithmeticUnit::~ArithmeticUnit()
{
    //dtor
}
int ArithmeticUnit::Add(int a, int b,FlagRegister &Flag)
{
    result = (a+b);
    UpdateFlags(a,b,Flag);
    return result;
}
int ArithmeticUnit::AddWithCarry(int a,int b,FlagRegister &Flag)
{
    result = (a+b+1);
    UpdateFlags(a,b,Flag);
    return result;
}
int ArithmeticUnit::Sub(int a,int b,FlagRegister &Flag)
{
    result = (a+(255-b)+1);
    UpdateFlags(a,b,Flag);
    return result;
}
int ArithmeticUnit::Increment(int a,FlagRegister &Flag)
{

    result = (a+1);
    UpdateFlags(a,Flag);
    return result;
}

void ArithmeticUnit::UpdateFlags(int a,int b,FlagRegister &Flag)
{
    if (result>255)
    {
        result -= 256;
        Flag.setc();
    }
    else Flag.clearc();

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


    if(a> 127 && b > 127)
    {
        if(result < 128) Flag.setv();
        else Flag.clearv();
    }
    else if (a < 128 && b < 128)
    {
        if(result < 128) Flag.clearv();
        else Flag.setv();
    }
    else Flag.clearv();
}

void ArithmeticUnit::UpdateFlags(int a,FlagRegister &Flag)
{
    if (result>255)
    {
        result -= 256;
        Flag.setc();
    }
    else Flag.clearc();

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


    if(a > 127)
    {
        if(result < 128) Flag.setv();
        else Flag.clearv();
    }
    else if (a < 128)
    {
        if(result < 128) Flag.clearv();
        else Flag.setv();
    }
    else Flag.clearv();
}
