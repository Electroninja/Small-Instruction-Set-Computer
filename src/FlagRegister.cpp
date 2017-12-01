#include "FlagRegister.h"

FlagRegister::FlagRegister()
{
    n=0;
    z=0;
    v=0;
    c=0;
}

FlagRegister::~FlagRegister()
{
    //dtor
}

void FlagRegister::setn()
{
    n=1;
    return;
}
void FlagRegister::setz()
{
    z=1;
    return;
}
void FlagRegister::setv()
{
    v=1;
    return;
}
void FlagRegister::setc()
{
    c=1;
    return;
}
void FlagRegister::clearn()
{
    n=0;
    return;
}
void FlagRegister::clearz()
{
    z=0;
    return;
}
void FlagRegister::clearv()
{
    v=0;
    return;
}
void FlagRegister::clearc()
{
    c=0;
    return;
}
int FlagRegister::getn()
{
    return n;
}
int FlagRegister::getz()
{
    return z;
}
int FlagRegister::getv()
{
    return v;
}
int FlagRegister::getc()
{
    return c;
}
