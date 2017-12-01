#include <Compiler.h>

int main()
{
    Compiler compiler;
    Computer computer;

    compiler.compile("Code.txt",computer);
    computer.start();
    computer.M.print();
    return 0;
}
