#include "LogicUnit.h"

LogicUnit::LogicUnit()
{
    //ctor
}

LogicUnit::~LogicUnit()
{
    //dtor
}
int LogicUnit::And(int a, int b,FlagRegister &Flag)
{
    result = a&b;
    UpdateFlags(Flag);
    return result;
}
int LogicUnit::Or(int a, int b,FlagRegister &Flag)
{
    result = a|b;
    UpdateFlags(Flag);
    return result;
}
int LogicUnit::Xor(int a, int b,FlagRegister &Flag)
{
    result = a^b;
    UpdateFlags(Flag);
    return result;
}
int LogicUnit::Compliment(int a,FlagRegister &Flag)
{
    result = a^255;
    UpdateFlags(Flag);
    return result;
}

void LogicUnit::UpdateFlags(FlagRegister &Flag)
{
    Flag.clearc();
    Flag.clearv();

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
