#ifndef COMPUTER_H
#define COMPUTER_H

#include <TimerRegister.h>
#include <MemBufReg.h>
#include <ProgramCounter.h>
#include <ArithmeticLogicUnit.h>
#include <Memory.h>
#include <ControlUnit.h>
#include <IndexRegister.h>


class Computer
{
    public:
        Computer();
        virtual ~Computer();

        void start();
        void step();
        void Istep();
        int controlsignal;
        int clock;
        int lines;

    protected:

    private:
        void mainloop();
        int isrunning;
        int stepper;
        int Istepper;
    public:
        Register A,B,Temp,MAR,IR;
        IndexRegister X,Y,C;
        MemBufReg MBR;
        ProgramCounter PC, SubPC;
        FlagRegister FLAG;
        TimerRegister TR;
        Memory M;
        ArithmeticLogicUnit ALU;
        ControlUnit CU;
};

#endif // COMPUTER_H
