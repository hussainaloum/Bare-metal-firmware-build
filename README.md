# Bare-metal build for ARM cortex-M using C
A guide/reference on how to build bare-metal firmware (runs directly on the MCU without an OS).  
This build was made on ***Ubuntu 20.04 LTS*** using the ***GNU ARM toolchain 10.3***.

## Steps :  
1- Understand the build process  
2- Download Ubuntu(Linux), GNU ARM toolchain 10.3 and an IDE (I will be using VS Code)  
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

## 2- Download Ubuntu(Linux), GNU ARM toolchain 10.3 and VS Code
### Ubuntu on Windows using WSL
The host machine used here is Windows 10, and Ubuntu 20.04 LTS was downloaded using WSL as follows:  
Open Microsoft sotre --> search Ubuntu 20.04 --> and click Get  
Open Ubuntu 20.04 and in the teminal follow instructions  
![Step2-1](https://user-images.githubusercontent.com/36559536/149999595-084d8e9d-183d-4983-bd9c-00dd8c06d018.JPG)

### GNU ARM toolchain 10.3
Download the toolchain called "gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2" for Linux from
https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads  
Open Ubuntu and go to the Downloads folder in windows using the command  
`cd /mnt/c/Users/username/Downloads`  
Extract the contents of the tar file and copy them to /doc folder using the command  
`sudo tar -xvf gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2 --directory /doc`  
Now the toolchain is ready

### VS Code
Download VS Code from the link https://code.visualstudio.com/download  
Open VS Code and install the following extensions: "C/C++" and "Cortex-Debug"  

## 3- Code 
All the required files are in the src folder.  

## 4- Debug and flash  
This section will show how to build, flash and debug the code.  
Notes:  
1-  To see how the MCU gets flashed and how debugging starts look at launch.json in the .vscode folder  

Open VS Code and go the TERMINAL section, press drop the down button and add Ubuntu.  
![step4-1](https://user-images.githubusercontent.com/36559536/150233244-64b1b86a-5735-4340-b8fa-59d27d424ae6.JPG)  

To build navigate to the src folder in the nRF52833 folder and type the following command  
`make semihosting`

![step4-2](https://user-images.githubusercontent.com/36559536/150233635-a1a661e5-bbfc-4906-b696-8762e2e76b13.JPG)

To flash and debug, all you have to do is select main.c, go to the "run and debug" tab and hit the play button  
![step4-3](https://user-images.githubusercontent.com/36559536/150233936-ace4eff4-eb31-4289-87b7-3a320d2c1ddb.JPG)  

Now you can step through the code and you should see the output of printf() in the "DEBUG CONSOLE"  
![step4-4](https://user-images.githubusercontent.com/36559536/150234340-8840aa6e-852e-46c7-917c-bcf3ebaeb1ee.JPG)
