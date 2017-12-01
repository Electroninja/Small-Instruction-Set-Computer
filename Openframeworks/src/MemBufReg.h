#ifndef MEMBUFREG_H
#define MEMBUFREG_H

#include <Register.h>


class MemBufReg : public Register
{
    public:
        MemBufReg();
        virtual ~MemBufReg();
        int readOpCode();
        void write(int input);
        void write(int opcode,int input);
    protected:
        int op;
    private:
};

#endif // MEMBUFREG_H
