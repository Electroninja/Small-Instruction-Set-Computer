#ifndef FLAGREGISTER_H
#define FLAGREGISTER_H

class FlagRegister
{
    public:
        FlagRegister();
        virtual ~FlagRegister();
        void setn();
        void setz();
        void setv();
        void setc();
        void clearn();
        void clearz();
        void clearv();
        void clearc();
        int getn();
        int getz();
        int getv();
        int getc();
    protected:

    private:
        int n;
        int z;
        int v;
        int c;
};

#endif // FLAGREGISTER_H
