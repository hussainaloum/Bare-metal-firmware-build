# Bare-metal build for ARM cortex-M using C
A guide/reference on how to build bare-metal firmware (runs directly on the MCU without an OS).  
This build was made on ***Ubuntu 20.04 LTS*** using the ***GNU ARM toolchain 10.3***.

## Steps :  
1- Understand the build process  
2- Download GNU ARM toolchain 10.3 and an IDE (I will be using VS Code)  
3- Code  
4- Debug and flash

## 1- Understand the build process
Pictures below show the build process of firmware. This process consists of two stages, compilation and linking.  
### Compilation stage:  
![Screen Shot 2022-01-09 at 12 50 38 PM (2)](https://user-images.githubusercontent.com/36559536/148696338-949aedcd-5f9c-4a7b-81ba-8d026b6b9d97.png)
<pre>
Steps:
1- main.c --> Compiler --> main.i   [Pre-processor stage: include and macros are added]  
2- main.i --> Compiler --> main.s   [Code generation stage: high level language to assembly]
3- main.s --> Compiler --> main.o   [Assembler stage: convert assembly into machine code]

Note: 
main.o doesn't contain any absolute addresses for data and code,
hence we need to make a linker script to tell the compiler where to put the machine code in memory
</pre>  
### Linking stage:  
![Screen Shot 2022-01-09 at 12 51 24 PM (2)](https://user-images.githubusercontent.com/36559536/148696370-48d138fc-8f2c-4570-9ac0-874acd55fd00.png)  
<pre>
Steps:
1- .o + .a  --> Linker  --> .elf    [combine .o and .a files into .elf (Executable and Linkable Format)]

Notes:
1- .o and .a files are combined and organized in memory according to the linker script and, put in .elf file

2- .a files are libraries like stdlib,
    however the stdlib (C standard library) is too big for the limited memory in an MCU.
    So newlib, a different implementation of stdlib was used in the linker script.
</pre>

## 2- Download GNU ARM toolchain 10.3 and VS Code
## 3- Code 
## 4- Debug and flash  
