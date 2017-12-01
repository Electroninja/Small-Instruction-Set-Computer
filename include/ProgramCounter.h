#ifndef PROGRAMCOUNTER_H
#define PROGRAMCOUNTER_H

#include <Register.h>


class ProgramCounter : public Register
{
    public:
        ProgramCounter();
        virtual ~ProgramCounter();
        void Increment();
    protected:

    private:
};

#endif // PROGRAMCOUNTER_H
