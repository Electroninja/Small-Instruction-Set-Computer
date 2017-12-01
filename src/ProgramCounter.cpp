#include "ProgramCounter.h"

ProgramCounter::ProgramCounter()
{
    value = 0;
}

ProgramCounter::~ProgramCounter()
{
    //dtor
}

void ProgramCounter::Increment()
{
    value++;
    if(value > 255) value = 0;
    return;
}
