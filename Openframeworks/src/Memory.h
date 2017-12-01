#ifndef MEMORY_H
#define MEMORY_H

#define MAX_ADDRESS 256
#define MAX_DEPTH 2

#include <iostream>

using namespace std;

class Memory
{
    public:
        Memory();
        virtual ~Memory();
        int read(int address,int index);
        void write(int input, int address,int index);
        void writeCode(int opcode, int input, int address);
        void print();
    protected:

    private:
        int memory[MAX_ADDRESS][MAX_DEPTH] = {{0}};
};

#endif // MEMORY_H
