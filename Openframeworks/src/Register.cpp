#include "register.h"

Register::Register()
{
    value =0;
    //ctor
}

Register::~Register()
{
    //dtor
}

int Register::read()
{
    return value;
}

void Register::write(int input)
{
    value = input;
    return;
}

void Register::zero()
{
    value = 0;
    return;
}
