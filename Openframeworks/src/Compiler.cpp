#include "Compiler.h"

Compiler::Compiler()
{

}

Compiler::~Compiler()
{
    //dtor
}

void Compiler::compile(char * FileName,Computer & computer)
{
    Opcode = 0;
    CodeAddress = 0;

    int operand1 = 0;
    string TEMP,OPCODE;
    fstream code;
    code.open(FileName);

    while (getline(code,TEMP))
    {
        if(TEMP == "" || TEMP[0] == '/') continue;
        TEMP += '\n';
        parse(TEMP,OPCODE,operand1);
        MakeLabels(TEMP,OPCODE);
    }
    code.close();

    CodeAddress = 0;

    code.open(FileName);
    while (getline(code,TEMP))
    {
        if(TEMP == "" || TEMP[0] == '/') continue;
        TEMP += '\n';
        parse(TEMP,OPCODE,operand1);
        CodeToMem(computer.M,OPCODE,operand1,TEMP);
    }
    return;
}

void Compiler::CodeToMem(Memory &mem, string op, int value, string LABELS)
{
    if(op == "ADDA") Opcode =1;
    else if(op == "ADDB") Opcode =2;
    else if(op == "ADAB") Opcode =3;
    else if(op == "ADBA") Opcode =4;
    else if(op == "SUBA") Opcode =5;
    else if(op == "SUBB") Opcode =6;
    else if(op == "SUB") Opcode =7;
    else if(op == "ANDA") Opcode =8;
    else if(op == "ANDB") Opcode =9;
    else if(op == "AND") Opcode =10;
    else if(op == "ORA") Opcode =11;
    else if(op == "ORB") Opcode =12;
    else if(op == "OR") Opcode =13;
    else if(op == "XORA") Opcode =14;
    else if(op == "XORB") Opcode =15;
    else if(op == "XOR") Opcode =16;
    else if(op == "INCA") Opcode =17;
    else if(op == "INVA") Opcode =18;
    else if(op == "TFRAB") Opcode =19;
    else if(op == "TFRBA") Opcode =20;
    else if(op == "STOREA") Opcode =21;
    else if(op == "STOREB") Opcode =22;
    else if(op == "SWAP") Opcode =23;
    else if(op == "SHFTL") Opcode =24;
    else if(op == "SHFTR") Opcode =25;
    else if(op == "CLRA") Opcode =26;
    else if(op == "CLRB") Opcode =27;
    else if(op == "BRA") Opcode =28;
    else if(op == "BNE") Opcode =29;
    else if(op == "BEQ") Opcode =30;
    else if(op == "BPO") Opcode =31;
    else if(op == "BMI") Opcode =32;
    else if(op == "LOADA") Opcode =33;
    else if(op == "LOADB") Opcode =34;
    else if(op == "MTOA") Opcode =35;
    else if(op == "MTOB") Opcode =36;
    else if(op == "LOADX") Opcode =37;
    else if(op == "LOADY") Opcode =38;
    else if(op == "LOADC") Opcode =39;
    else if(op == "LOADAMX") Opcode =40;
    else if(op == "LOADAMY") Opcode =41;
    else if(op == "LOADBMX") Opcode =42;
    else if(op == "LOADBMY") Opcode =43;
    else if(op == "COMPXY") Opcode =44;
    else if(op == "COMPXC") Opcode =45;
    else if(op == "COMPYC") Opcode =46;
    else if(op == "STOREAMX") Opcode =47;
    else if(op == "STOREAMY") Opcode =48;
    else if(op == "STOREBMX") Opcode =49;
    else if(op == "STOREBMY") Opcode =50;
    else if(op == "INCX") Opcode =51;
    else if(op == "INCY") Opcode =52;
    else if(op == "DECX") Opcode =53;
    else if(op == "DECY") Opcode =54;
    else if(op == "INCC") Opcode =55;
    else if(op == "DECC") Opcode =56;
    else if(op == "COMPX") Opcode =57;
    else if(op == "COMPY") Opcode =58;
    else if(op == "COMPC") Opcode =59;
    else if(op == "LABEL") Opcode =60;
    else if(op == "JUMP") Opcode =61;
    else if(op == "RETURN") Opcode =62;
    else if(op == "BTOC") Opcode =63;
    else if(op == "END") {Opcode =0;value = 252;}
    else
        {
            cout << "Error mneumatic: " << op << endl;
            return;
        }
    if (Opcode == 60)
    {
        mem.writeCode(Opcode,SearchLabel(LABELS),CodeAddress);
    }
    else if (Opcode == 61 || (Opcode<33 && Opcode>27))
    {
        mem.writeCode(Opcode,SearchLabel(LABELS),CodeAddress);
    }
    else
    {
        mem.writeCode(Opcode,value,CodeAddress);
    }
    CodeAddress++;
    return;
}

int Compiler::SearchLabel(string label)
{
    for(int i=0;i<labelnumber+1;i++)
    {
        if(LabelName[i]==label) return LabelAddress[i];
    }
    return -1;
}

void Compiler::MakeLabels(string name, string type)
{
    if(type == "LABEL")
        {
            LabelAddress[labelnumber] = CodeAddress;
            LabelName[labelnumber] = name;
            labelnumber++;
        }
    CodeAddress++;
    return;
}

void Compiler::parse(string &input, string &opcode, int &oper1)
{
    int i=0;
    oper1 = 0;
    string op1 = "";
    opcode = "";
    while(input[i] != ' ' && input[i] != '\n')
    {
        opcode += input[i];
        i++;
    }
    if(input[i] == '\n') return;
    i++;
    while(input[i] != '\n')
    {
        op1 += input[i];
        i++;
    }
    oper1 = atoi(op1.c_str());
    input = op1;
    return;
}
