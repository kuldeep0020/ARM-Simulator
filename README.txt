_____________________________________________________________________________________________
_____________________________________________________________________________________________
|||||||||||||||||||||||||||||| ARM ASSEMBLY CODE SIMULATOR ||||||||||||||||||||||||||||||||||
_____________________________________________________________________________________________
_____________________________________________________________________________________________

This Simulator is designed to simulate instructions which are written for ARM V7 machines. It uses 16 
register files each of 32-bits and a memory of 4000-bytes. In this simulator we can simulate simple ARM
instructions and see the changes in values of registers and memory. This simulator is written in C++ 
language and just a working model of how ARM assembly level instructions behaves and does not shows any 
statistical data related to performance or capacity. This simulator is made only for educational purpose.
This simulator can perform following instructions:
----------Arithmatic operations----------
1. ADD :This instruction adds two numbers.
syntax : ADD Rd, Rs, %%    (Rd = Rs + %%)
    Rd -- destination register, where result will be stored
    Rs -- Source 1 register, from where first operand will be taken
    %% -- Here we can use any immediate operand or source 2 register

2. SUB :This instruction subtracts two numbers.
syntax : SUB Rd, Rs, %%     (Rd = Rs - %%)
    Rd -- destination register, where result will be stored
    Rs -- Source 1 register, from where first operand will be taken
    %% -- Here we can use any immediate operand or source 2 register

3. MUL :This instruction multiplies two numbers.
syntax : MUL Rd, Rs, %%     (Rd = Rs * %%)
    Rd -- destination register, where result will be stored
    Rs -- Source 1 register, from where first operand will be taken
    %% -- Here we can use any immediate operand or source 2 register

----------Memory based operations--------
4. LDR :This instruction loads value in register.
syntax : LDR Rd, #Ms         (Rd = Ms)
         LDR Rd, [RS,#%%]
         LDR Rd, [Rs]
    Rd -- destination register, where value from memory will be stored
    Ms -- The address of memory, from where data will be copied in register
    [] -- this represents that treat value stored in register as an address
    %% -- This represents addition in the value stored in register

5. STR :This instruction stores value from register to memory.
syntax : STR Rs, #Md         (Rd = Ms)
         STR Rs, [Rd,#%%]
         STR Rs, [Rd]
    Rs -- source register, from where value in memory will be stored
    Ms -- The address of memory, where data will be copied from register
    [] -- this represents that treat value stored in register as an address
    %% -- This represents addition in the value stored in register

-------------Logical operation-----------
6. CMP :This instruction compares value stored in two registers
syntax : CMP R1, R2
    R1 -- register 1 
    R2 -- register 2

--------Data operatins on registers------
7. MOV :This instruction copies value of one register into other register
syntax : MOV Rd, Rs
    Rd -- destination register, in which we want to copy the value
    Rs -- source register, from where we want to copy the value

We tried but we were unable to give lables to the instruction so the branch commands 
are not suitable to simulate on this simulator.
_________________________________________________________________________________________________________
HOW TO USE: To run this simulator type "g++ ARM_Simulator.cpp" in the terminal while keeping 
the present working directory same where this file is stored. And the ARM assembly codes should 
be in a file (text or assembly format or any other) and saved in the same directory.
After typing above command one executable file will be generated. Now run that command by typing 
./a.out and enter the name of file on asking.
_________________________________________________________________________________________________________
 
Acknowledgement: I want to thanks Dr. Preeti Ranjan Panda (IIT Delhi) for teaching me about the 
    ARM V7 machine structure and the assembly level language which works on most of 
    the machines. He supported me on all stages. 

Submitted By-
Kuldeep (2016CSJ0020) IIT Jammu
