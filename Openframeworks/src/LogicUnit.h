#ifndef LOGICUNIT_H
#define LOGICUNIT_H

#include <FlagRegister.h>


class LogicUnit
{
    public:
        LogicUnit();
        virtual ~LogicUnit();
        int And(int a,int b,FlagRegister &Flag);
        int Or(int a,int b,FlagRegister &Flag);
        int Xor(int a,int b,FlagRegister &Flag);
        int Compliment(int a,FlagRegister &Flag);
    protected:

    private:
        void UpdateFlags(FlagRegister &Flag);
        int result;
};

#endif // LOGICUNIT_H
