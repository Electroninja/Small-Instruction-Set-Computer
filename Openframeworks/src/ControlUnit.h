#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <FlagRegister.h>


class ControlUnit
{
    public:
        ControlUnit();
        virtual ~ControlUnit();
        int getSignal(int time, int Opcode, FlagRegister flag);
    protected:

    private:
        int getcontrolSignal(int time, int Opcode, FlagRegister flag);
        int ControlSignal[64][8] = {{4,5,6,52},
                                    {7,5,8,52},
                                    {9,5,6,52},
                                    {9,5,8,52},
                                    {10,5,6,52},
                                    {11,5,8,52},
                                    {12,5,6,52},
                                    {13,5,6,52},
                                    {14,5,8,52},
                                    {15,5,6,52},
                                    {16,5,6,52},
                                    {17,5,8,52},
                                    {18,5,6,52},
                                    {19,5,6,52},
                                    {20,5,8,52},
                                    {21,5,6,52},
                                    {22,5,6,52},
                                    {23,5,6,52},
                                    {24,52},
                                    {25,52},
                                    {26,27,28,52},
                                    {26,29,28,52},
                                    {27,25,8,52},
                                    {30,5,6,52},
                                    {31,5,6,52},
                                    {32,52},
                                    {33,52},
                                    {34,52},///branching Operations
                                    {34,52},
                                    {34,52},
                                    {34,52},
                                    {34,52},///--------------------
                                    {6,52},
                                    {8,52},
                                    {26,53,6,52},///Memory to A,B
                                    {26,53,8,52},
                                    {35,52},///LOAD X,Y,C
                                    {36,52},
                                    {37,52},
                                    {38,26,53,6,52},///LOAD A,B from M[X|Y]
                                    {39,26,53,6,52},
                                    {38,26,53,8,52},
                                    {39,26,53,8,52},
                                    {40,52},///Compare X,Y,C
                                    {47,52},
                                    {48,52},
                                    {38,26,27,56,52},///STORE A,B from M[X|Y]
                                    {39,26,27,56,52},
                                    {38,26,29,56,52},
                                    {39,26,29,56,52},
                                    {41,52},///INC X,Y
                                    {42,52},
                                    {43,52},///DEC X,Y
                                    {44,52},
                                    {45,52},///INC/DEC C
                                    {46,52},
                                    {49,52},///Compare X,Y,C to MBR
                                    {50,52},
                                    {51,52},
                                    {52},///Label
                                    {54,34,52},///Jump
                                    {55,52},///Return
                                    {29,37,52}///B to Counter
                                   };
};

#endif // CONTROLUNIT_H
