#ifndef INDEXREGISTER_H
#define INDEXREGISTER_H

#include <Register.h>


class IndexRegister : public Register
{
    public:
        IndexRegister();
        virtual ~IndexRegister();
        void decrement();
        void increment();
    protected:

    private:
};

#endif // INDEXREGISTER_H
