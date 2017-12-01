#include "ControlUnit.h"

ControlUnit::ControlUnit()
{

}

ControlUnit::~ControlUnit()
{
    //dtor
}

int ControlUnit::getSignal(int time, int Opcode, FlagRegister flag)
{
    ///USE THIS TO DECODE THE OPCODE AND TIME
    ///Fetch
    if(time==0) return 1;
    else if (time == 1) return 2;
    else if (time == 2) return 3;
    ///Other Operations
    else return getcontrolSignal(time,Opcode,flag);
}

int ControlUnit::getcontrolSignal(int time,int Opcode, FlagRegister flag)
{
    if (Opcode == 29 && flag.getz() == 1) return 52;//Branch Not Equal Failed
    if (Opcode == 30 && flag.getz() == 0) return 52;//Branch Equal Failed
    if (Opcode == 31 && flag.getn() == 1) return 52;//Branch Positive Failed
    if (Opcode == 32 && flag.getn() == 0) return 52;//Branch Negative Failed

    return ControlSignal[Opcode-1][time-3];
}
