# Bare-metal-firmware-build
A guide on how to compile IDE independent firmware that runs directly on the MCU (without an OS)

Pictures below show the compilation process(build process) of firmware.
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
![Screen Shot 2022-01-09 at 12 51 24 PM (2)](https://user-images.githubusercontent.com/36559536/148696370-48d138fc-8f2c-4570-9ac0-874acd55fd00.png)
