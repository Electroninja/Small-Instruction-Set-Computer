#ifndef ARITHMETICUNIT_H
#define ARITHMETICUNIT_H

#include <FlagRegister.h>


class ArithmeticUnit
{
    public:
        ArithmeticUnit();
        virtual ~ArithmeticUnit();
        int Add(int a,int b,FlagRegister &Flag);
        int AddWithCarry(int a,int b,FlagRegister &Flag);
        int Sub(int a,int b,FlagRegister &Flag);
        int Increment(int a,FlagRegister &Flag);

    protected:

    private:
        void UpdateFlags(int a,int b,FlagRegister &Flag);
        void UpdateFlags(int a,FlagRegister &Flag);
        int result;
};

#endif // ARITHMETICUNIT_H
