#include "Computer.h"

Computer::Computer()
{
    isrunning = 0;
    stepper = 1;
    Istepper = 1;
    clock = 0;
    lines=0;
}

Computer::~Computer()
{
    //dtor
}

void Computer::start()
{
    isrunning = 1;
    mainloop();
    return;
}

void Computer::step()
{
    stepper = 0;
}

void Computer::Istep()
{
    Istepper = 0;
}

void Computer::mainloop()
{   ///THIS HOUSES ALL OF THE MICRO OPERATIONS
    //cout << "Register A: " << A.read() << endl;
    //cout << "Register B: " << B.read() << endl;
    while(isrunning)
    {
        controlsignal = CU.getSignal(TR.read(),IR.read(),FLAG);
        stepper = 1;
        while(stepper && Istepper){cout <<"";}
        clock++;
        switch(controlsignal)
        {
        case 1: MAR.write(PC.read());break;
        case 2: MBR.write(M.read(MAR.read(),0),M.read(MAR.read(),1));
                PC.Increment();break;
        case 3: IR.write(MBR.readOpCode());break;
        case 4: Temp.write(ALU.Add(MBR.read(),A.read(),FLAG));break;
        case 5: MBR.write(Temp.read());break;
        case 6: A.write(MBR.read());break;
        case 7: Temp.write(ALU.Add(MBR.read(),B.read(),FLAG));break;
        case 8: B.write(MBR.read());break;
        case 9: Temp.write(ALU.Add(A.read(),B.read(),FLAG));break;
        case 10:Temp.write(ALU.Sub(A.read(),MBR.read(),FLAG));break;
        case 11:Temp.write(ALU.Sub(B.read(),MBR.read(),FLAG));break;
        case 12:Temp.write(ALU.Sub(A.read(),B.read(),FLAG));break;
        case 13:Temp.write(ALU.And(A.read(),MBR.read(),FLAG));break;
        case 14:Temp.write(ALU.And(B.read(),MBR.read(),FLAG));break;
        case 15:Temp.write(ALU.And(A.read(),B.read(),FLAG));break;
        case 16:Temp.write(ALU.Or(A.read(),MBR.read(),FLAG));break;
        case 17:Temp.write(ALU.Or(B.read(),MBR.read(),FLAG));break;
        case 18:Temp.write(ALU.Or(A.read(),B.read(),FLAG));break;
        case 19:Temp.write(ALU.Xor(A.read(),MBR.read(),FLAG));break;
        case 20:Temp.write(ALU.Xor(B.read(),MBR.read(),FLAG));break;
        case 21:Temp.write(ALU.Xor(A.read(),B.read(),FLAG));break;
        case 22:Temp.write(ALU.Increment(A.read(),FLAG));break;
        case 23:Temp.write(ALU.Compliment(A.read(),FLAG));break;
        case 24:B.write(A.read());break;
        case 25:A.write(B.read());break;
        case 26:MAR.write(MBR.read());break;
        case 27:MBR.write(A.read());break;
        case 28:M.write(MBR.read(),MAR.read(),1);break;
        case 29:MBR.write(B.read());break;
        case 30:Temp.write(ALU.leftShift(A.read(),FLAG));break;
        case 31:Temp.write(ALU.rightShift(A.read(),FLAG));break;
        case 32:A.zero();break;
        case 33:B.zero();break;
        case 34:PC.write(MBR.read());break;
        case 35:X.write(MBR.read());break;
        case 36:Y.write(MBR.read());break;
        case 37:C.write(MBR.read());break;
        case 38:MBR.write(X.read());break;
        case 39:MBR.write(Y.read());break;
        case 40:Temp.write(ALU.Sub(X.read(),Y.read(),FLAG));break;
        case 41:X.increment();break;
        case 42:Y.increment();break;
        case 43:X.decrement();break;
        case 44:Y.decrement();break;
        case 45:C.increment();break;
        case 46:C.decrement();break;
        case 47:Temp.write(ALU.Sub(X.read(),C.read(),FLAG));break;
        case 48:Temp.write(ALU.Sub(Y.read(),C.read(),FLAG));break;
        case 49:Temp.write(ALU.Sub(X.read(),MBR.read(),FLAG));break;
        case 50:Temp.write(ALU.Sub(Y.read(),MBR.read(),FLAG));break;
        case 51:Temp.write(ALU.Sub(C.read(),MBR.read(),FLAG));break;
        case 52:TR.write(-1);Istepper=1;lines++;break;
        case 53:MBR.write(M.read(MAR.read(),0),M.read(MAR.read(),1));break;
        case 54:SubPC.write(PC.read());break;
        case 55:PC.write(SubPC.read());break;
        case 56:M.write(MBR.read(),MAR.read(),1);M.write(MBR.readOpCode(),MAR.read(),0);break;
        case 57:
        case 58:
        case 59:
        case 60:
        default:isrunning = 0;break;
        }

        TR.Increment();
    }
    //cout << "\nRegister A: " << A.read() << endl;
    //cout << "Register B: " << B.read();
    return;
}
