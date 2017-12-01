# Small-Instruction-Set-Computer

C++ code for a small instruction set computer and a compiler for it.

"code.txt" is used for programming the computer
"Command List.txt" has a list of all the valid commands for programming the computer.
Currently It will print out the contents of main memory to console when execution is done.
For a visual look, download the openframeworks folder. It includes a compiled version of the project and the source code.

The program that comes with this project demonstrates 4 different operations currently
1)Multiplication of 2 numbers
2)Batch loading of Memory with data
3)Adding 2 Blocks of data
4)And Bubble sorting data in Memory

#Built in Saftey Mechanism: 
If you write over your instructions, and you try and read them the code will terminate. 
Console will tell you when a bad nmeumonic is used,however code will still compile and run.

#Known Bug:
Jumping or Branching to an undeclared Label will cause the program to get stuck in a loop.
