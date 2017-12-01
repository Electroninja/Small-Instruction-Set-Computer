#include "TimerRegister.h"

TimerRegister::TimerRegister()
{
    value = 0;
}

TimerRegister::~TimerRegister()
{
    //dtor
}
void TimerRegister::Increment()
{
    value += 1;
    if(value > 255) value = 0;
    return;
}
void TimerRegister::Reset()
{
    value = 0;
    return;
}
