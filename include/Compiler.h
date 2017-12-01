#ifndef COMPILER_H
#define COMPILER_H

#include <Computer.h>
#include <fstream>
#include <stdlib.h>


using namespace std;

class Compiler
{
    public:
        Compiler();
        virtual ~Compiler();
        void compile(char * FileName,Computer & computer);
    protected:

    private:
        void parse(string &input, string &opcode, int &oper1);
        void CodeToMem(Memory &mem,string op,int value,string LABELS);
        void MakeLabels(string name,string type);
        int SearchLabel(string label);

        int Opcode, CodeAddress, labelnumber = 0;
        int LabelAddress[50]={0};
        string LabelName[50]={""};
};

#endif // COMPILER_H
