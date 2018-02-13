# Small-Instruction-Set-Computer  
Created By Lutulu Mbiye

C++ code for a small instruction set computer and a compiler for it.  
HTML Version https://cdn.rawgit.com/Electroninja/Small-Instruction-Set-Computer/058464f7/SISC%20Simulation.html

"code.txt" is used for programming the computer  
"Command List.txt" has a list of all the valid commands for programming the computer.  
Currently It will print out the contents of main memory to console when execution is done.  
For a visual look, download the openframeworks folder. It includes a compiled version of the project and the source code.  
For a HTML version download or open SISC Simulation.html. It is an HTML version of this project. Should Hopefully work on an browser.

The program that comes with this project demonstrates 4 different operations currently  
1)Multiplication of 2 numbers  
2)Batch loading of Memory with data  
3)Adding 2 Blocks of data  
4)And Bubble sorting data in Memory  

#Built in Saftey Mechanism:  
Compiled code is stored in begining addresses in memory. If you write over your instructions and try to execute a line of code that was written over, the program will terminate.  
Console will tell you when a incorrect nmeumonic is used,however code will still compile and run.  

#Known Bug:  
Jumping or Branching to an undeclared Label will cause the program to get stuck in a loop.
