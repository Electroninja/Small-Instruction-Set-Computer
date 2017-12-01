#ifndef REGISTER_H
#define REGISTER_H


class Register
{
    public:
        Register();
        virtual ~Register();
        int read();
        void write(int input);
        void zero();
    protected:
        int value;
    private:


};

#endif // REGISTER_H
