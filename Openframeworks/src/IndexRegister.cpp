#include "IndexRegister.h"

IndexRegister::IndexRegister()
{
    //ctor
}

IndexRegister::~IndexRegister()
{
    //dtor
}

void IndexRegister::increment()
{
    value++;
    if(value > 255) value = 0;
    return;
}

void IndexRegister::decrement()
{
    value--;
    if(value < 0) value = 255;
    return;
}
