#ifndef ArithmeticLogicUnit_H
#define ArithmeticLogicUnit_H

#include <ArithmeticUnit.h>
#include <LogicUnit.h>
#include <Shifter.h>

class ArithmeticLogicUnit:public ArithmeticUnit, public LogicUnit, public Shifter
{
    public:
        ArithmeticLogicUnit();
        virtual ~ArithmeticLogicUnit();
    protected:

    private:

};

#endif // ALU_H
