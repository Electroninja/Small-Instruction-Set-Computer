#ifndef SHIFTER_H
#define SHIFTER_H

#include <FlagRegister.h>


class Shifter
{
    public:
        Shifter();
        virtual ~Shifter();
        int noShift(int a,FlagRegister &Flag);
        int leftShift(int a,FlagRegister &Flag);
        int rightShift(int a,FlagRegister &Flag);
        int zeroClear(int a,FlagRegister &Flag);
    protected:

    private:
        void UpdateFlags(int a,FlagRegister &Flag);
        int result;
};

#endif // SHIFTER_H
