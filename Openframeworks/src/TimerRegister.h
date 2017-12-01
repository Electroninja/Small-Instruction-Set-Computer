#ifndef TIMERREGISTER_H
#define TIMERREGISTER_H

#include <Register.h>


class TimerRegister : public Register
{
    public:
        TimerRegister();
        virtual ~TimerRegister();
        void Increment();
        void Reset();
    protected:

    private:
};

#endif // TIMERREGISTER_H
