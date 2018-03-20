#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<map>
#include<bits/stdc++.h>
// #include<cstdlib>
using namespace std;

/*----------Global variable declarations---------*/
string opcode, filename;
ifstream file;
vector <string> instruction_store;
long rgstr[16], memory[100];
int program_counter=1000, instruction_show=0;


/*------------Defining enumerator here-----------*/
enum opcode_value
{
    zero, one, two, three, four, five, six, seven,
    eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen,
    tri_operand_instruction, di_operand_instruction, uni_operand_instruction,
    add, sub, mul, cmp, ldr, str, mov, bne, bge, bl, b           
};

/*----------Defining mapping rules here----------*/
static std::map<std::string, opcode_value> map_opcode_values;

/*----Mapping according to number of operands----*/
static void Initialize()
{
    /*-- Operations with three operands--*/
    map_opcode_values["ADD"]= add;
    map_opcode_values["add"]= add;
    map_opcode_values["SUB"]= sub;
    map_opcode_values["sub"]= sub;
    map_opcode_values["MUL"]= mul;
    map_opcode_values["mul"]= mul;

    /*-- Operations with two operands--*/
    map_opcode_values["LDR"]= ldr;
    map_opcode_values["ldr"]= ldr;
    map_opcode_values["STR"]= str;
    map_opcode_values["str"]= str;
    map_opcode_values["CMP"]= cmp;
    map_opcode_values["cmp"]= cmp;
    map_opcode_values["MOV"]= mov;
    map_opcode_values["mov"]= mov;

    /*-- Operations with one operand---*/
    map_opcode_values["BNE"]= bne;
    map_opcode_values["bne"]= bne;
    map_opcode_values["BGE"]= bge;
    map_opcode_values["bge"]= bge;
    map_opcode_values["BL"]= bl;
    map_opcode_values["bl"]= bl;
    map_opcode_values["B"]= b;
    map_opcode_values["b"]= b;

    /*-----Mapping Register values-----*/
    map_opcode_values["R0"]= zero;
    map_opcode_values["R1"]= one;
    map_opcode_values["R2"]= two;
    map_opcode_values["R3"]= three;
    map_opcode_values["R4"]= four;
    map_opcode_values["R5"]= five;
    map_opcode_values["R6"]= six;
    map_opcode_values["R7"]= seven;
    map_opcode_values["R8"]= eight;
    map_opcode_values["R9"]= nine;
    map_opcode_values["R10"]= ten;
    map_opcode_values["R11"]= eleven;
    map_opcode_values["R12"]= twelve;
    map_opcode_values["R13"]= thirteen;
    map_opcode_values["R14"]= fourteen;
    map_opcode_values["R15"]= fifteen;
    map_opcode_values["r0"]= zero;
    map_opcode_values["r1"]= one;
    map_opcode_values["r2"]= two;
    map_opcode_values["r3"]= three;
    map_opcode_values["r4"]= four;
    map_opcode_values["r5"]= five;
    map_opcode_values["r6"]= six;
    map_opcode_values["r7"]= seven;
    map_opcode_values["r8"]= eight;
    map_opcode_values["r9"]= nine;
    map_opcode_values["r10"]= ten;
    map_opcode_values["r11"]= eleven;
    map_opcode_values["r12"]= twelve;
    map_opcode_values["r13"]= thirteen;
    map_opcode_values["r14"]= fourteen;
    map_opcode_values["r15"]= fifteen;

    map_opcode_values["R0,"]= zero;
    map_opcode_values["R1,"]= one;
    map_opcode_values["R2,"]= two;
    map_opcode_values["R3,"]= three;
    map_opcode_values["R4,"]= four;
    map_opcode_values["R5,"]= five;
    map_opcode_values["R6,"]= six;
    map_opcode_values["R7,"]= seven;
    map_opcode_values["R8,"]= eight;
    map_opcode_values["R9,"]= nine;
    map_opcode_values["R10,"]= ten;
    map_opcode_values["R11,"]= eleven;
    map_opcode_values["R12,"]= twelve;
    map_opcode_values["R13,"]= thirteen;
    map_opcode_values["R14,"]= fourteen;
    map_opcode_values["R15,"]= fifteen;
    map_opcode_values["r0,"]= zero;
    map_opcode_values["r1,"]= one;
    map_opcode_values["r2,"]= two;
    map_opcode_values["r3,"]= three;
    map_opcode_values["r4,"]= four;
    map_opcode_values["r5,"]= five;
    map_opcode_values["r6,"]= six;
    map_opcode_values["r7,"]= seven;
    map_opcode_values["r8,"]= eight;
    map_opcode_values["r9,"]= nine;
    map_opcode_values["r10,"]= ten;
    map_opcode_values["r11,"]= eleven;
    map_opcode_values["r12,"]= twelve;
    map_opcode_values["r13,"]= thirteen;
    map_opcode_values["r14,"]= fourteen;
    map_opcode_values["r15,"]= fifteen;
}

/*---------------Opening file here---------------*/
int file_open(string filename)
{
    file.open(filename);
    if (!file.is_open())
    {
        return false;
    }
    else 
    {
        return true;
    }
}

/*--------Parsing and storing instructions-------*/
char store_instructions()
{
    char show;
    string instruction;
    if (file_open(filename))
    {
        cout<<"File open successfull"<<endl<<endl;
        while (file.good())
        {
            getline(file, instruction);
            instruction_store.push_back(instruction);
        }
        file.close();
        cout<<"Storing of instructions in Array done successfull."<<endl;
        do
        {
            cout<<"Do you want to see the instructions array??? [y/n]:"<<endl;
            cin>>show;
        }while(((show != ('y' | 'Y')) & (show != ('n' | 'N')) ));
        return show;
    }
    else
    cout<<"Some error occured during opening the file. Can't store the instructions.";
    cout<<" Terminating execution now."<<endl;

}

/*--------Printing the stored instructions-------*/
void print_instructions()
{
    for (int i=0; i<instruction_store.size(); i++)
    cout<<instruction_store[i]<<endl;
}

/*----Function for handling addition operation---*/
void addition(string dst, string src1, string src2)
{
    cout<<instruction_store[instruction_show]<<endl;
    instruction_show++;
    if ((src2[0] != 'R') && (src2[0] != 'r') )
    {
        rgstr[map_opcode_values[dst]] = rgstr[map_opcode_values[src1]] + stoi(src2);
    }
    else
    {
        rgstr[map_opcode_values[dst]] = rgstr[map_opcode_values[src1]] + rgstr[map_opcode_values[src2]];
    }
    program_counter += 4;
    rgstr[15]= program_counter;
    cout<<"Sum is "<<rgstr[map_opcode_values[dst]]<<endl;
    cout<<"Modified values in register: "<<endl;
    cout<<"------------"<<endl;
    for (int i=0; i<16; i++)
    {
        cout<<"|  R"<<i<<" = "<<rgstr[i]<<"  |"<<endl;
        cout<<"------------"<<endl;
    }
}

/*--Function for handling subtraction operation--*/
void subtraction(string dst, string src1, string src2)
{
    cout<<instruction_store[instruction_show]<<endl;
    instruction_show++;
    if ((src2[0] != 'R') && (src2[0] != 'r') )
    {
        rgstr[map_opcode_values[dst]] = rgstr[map_opcode_values[src1]] - stoi(src2);
    }
    else
    {
        rgstr[map_opcode_values[dst]] = rgstr[map_opcode_values[src1]] - rgstr[map_opcode_values[src2]];
    }
    program_counter += 4;
    rgstr[15]= program_counter;
    cout<<"Diff is "<<rgstr[map_opcode_values[dst]]<<endl;
    cout<<"Modified values in register: "<<endl;
    cout<<"------------"<<endl;
    for (int i=0; i<16; i++)
    {
        cout<<"|  R"<<i<<" = "<<rgstr[i]<<"  |"<<endl;
        cout<<"------------"<<endl;
    }
}

/*--Function for handling multiplication operation--*/
void multiplication(string dst, string src1, string src2)
{
    cout<<instruction_store[instruction_show]<<endl;
    instruction_show++;
    if ((src2[0] != 'R') && (src2[0] != 'r') )
    {
        rgstr[map_opcode_values[dst]] = rgstr[map_opcode_values[src1]] * stoi(src2);
    }
    else
    {
        rgstr[map_opcode_values[dst]] = rgstr[map_opcode_values[src1]] * rgstr[map_opcode_values[src2]];
    }
    program_counter += 4;
    rgstr[15]= program_counter;
    cout<<"Mul is "<<rgstr[map_opcode_values[dst]]<<endl;
    cout<<"Modified values in register: "<<endl;
    cout<<"------------"<<endl;
    for (int i=0; i<16; i++)
    {
        cout<<"|  R"<<i<<" = "<<rgstr[i]<<"  |"<<endl;
        cout<<"------------"<<endl;
    }
}


/*--------Handlig move instruction here----------*/
void move(string dst, int src_val)
{
    cout<<instruction_store[instruction_show]<<endl;
    instruction_show++;
    rgstr[map_opcode_values[dst]] = src_val;
    program_counter += 4;
    rgstr[15]= program_counter;
    cout<<"Value of register "<<dst<< " after mov instruction is: "<<rgstr[map_opcode_values[dst]]<<endl;
    cout<<"Modified values in register: "<<endl;
    cout<<"------------"<<endl;
    for (int i=0; i<16; i++)
    {
        cout<<"|  R"<<i<<" = "<<rgstr[i]<<"  |"<<endl;
        cout<<"------------"<<endl;
    }
}
/*-------Handling comparision instruction here---*/
int cmpr(string src1, string src2)
{
    cout<<instruction_store[instruction_show]<<endl;
    instruction_show++;
    if (src1 >= src2)
    return 1;
    if (src1 != src2)
    return 2;
    program_counter += 4;
    rgstr[15]= program_counter;
}

/*-------Handling load instruction here----------*/
void load(string dst, int imm)
{
    cout<<instruction_store[instruction_show]<<endl;
    instruction_show++;
    rgstr[map_opcode_values[dst]] = imm;
    program_counter += 4;
    rgstr[15]= program_counter;
     cout<<"Value of register "<<dst<< " after load instruction is: "<<rgstr[map_opcode_values[dst]]<<endl;
    cout<<"Modified values in register: "<<endl;
    cout<<"------------"<<endl;
    for (int i=0; i<16; i++)
    {
        cout<<"|  R"<<i<<" = "<<rgstr[i]<<"  |"<<endl;
        cout<<"------------"<<endl;
    }
}

/*-------Handling store instruction here---------*/
void store(int dst, int data)
{
    cout<<instruction_store[instruction_show]<<endl;
    instruction_show++;
    memory[dst]= data;
    program_counter += 4;
    rgstr[15]= program_counter;
    cout<<"Program counter register have value :"<<rgstr[15]<<" and odified value in memory at address "<<dst<< " is: "<<memory[dst] <<endl;    
}

void follow();
void condition();

/*------------------Main Function here-----------*/
int main()
{
    memory[14]=12, memory[28]=300;
    cout<<"Enter the name of file containing instrctions: ";
    cin>>filename;
    cout<<endl;
    Initialize();
    char show = store_instructions();
    if (show == ('y' | 'Y'))
    {
        print_instructions();
    }
    if (file_open(filename))
    {
        cout<<endl;
        while(file.good())
        {
            condition();
        }
    }
}

void condition()
{
        file>>opcode;
            if ((opcode == "add") || (opcode == "ADD") || (opcode == "SUB") || (opcode == "sub") || (opcode == "MUL") || (opcode == "mul") || (opcode == "ldr") ||(opcode == "LDR") ||(opcode == "str") ||(opcode == "STR") ||(opcode == "cmp") || (opcode == "CMP") || (opcode == "mov") || (opcode == "MOV") || (opcode == "BNE") ||(opcode == "bne") || (opcode == "BGE") ||(opcode == "bge") || (opcode == "BL") ||(opcode == "bl") || (opcode == "B") ||(opcode == "b") )
            {
                follow();
            }
            else
            {
                condition();
            }
}

void follow()
{
            switch(map_opcode_values[opcode])
            {
                case add:
                {
                    string dst, src1, src2, src2_modified;
                    file>>dst;
                    file>>src1;
                    file>>src2;
                    cout<<endl<<"Addition instruction given here"<<endl;
                    if (src2[0] =='#')      
                    {
                        for(int len=0; len<(src2.length()-1); len++)
                        {
                            src2_modified += src2[(len+1)];
                        }
                        addition(dst, src1, src2_modified);
                    }
                    else
                    {
                        addition(dst, src1, src2);
                    }
                    break;
                }

                case sub:
                {
                    string dst, src1, src2, src2_modified;
                    file>>dst;
                    file>>src1;
                    file>>src2;
                    cout<<endl<<"Subtraction instruction given here"<<endl;
                    if (src2[0] =='#')
                    {
                        for(int len=0; len<(src2.length()-1); len++)
                        {
                            src2_modified += src2[(len+1)];
                        }
                        subtraction(dst, src1, src2_modified);
                    }
                    else
                    {
                        subtraction(dst, src1, src2);
                    }
                    break;
                }

                case mul:
                {
                    string dst, src1, src2, src2_modified;
                    file>>dst;
                    file>>src1;
                    file>>src2;
                    cout<<endl<<"Multiplication instruction given here"<<endl;
                    if (src2[0] =='#')
                    {
                        for(int len=0; len<(src2.length()-1); len++)
                        {
                            src2_modified += src2[(len+1)];
                        }
                        multiplication(dst, src1, src2_modified);
                    }
                    else
                    {
                        multiplication(dst, src1, src2);
                    }
                    break;
                }

                case ldr:
                {
                    string dst, src, src_reg, sum_val;
                    int mem_address;
                    file>>dst;
                    file>>src;
                    cout<<endl<<"Load instruction given here"<<endl;
                    if(src.size()==4 && src[0] == '[' && src[3]== ']')
                    {
                        for(int len= 0; len<2; len++)
                        {
                            src_reg += src[len+1];
                        }
                        mem_address= rgstr[map_opcode_values[src_reg]];
                        load(dst, mem_address);
                    }

                    else if((src[0] == '[') && (src[(src.size()-1)]==']') && (src.size()!=4 || src.size()!=5))
                    {
                        for(int len= 0; len<3; len++)
                        {
                            src_reg += src[len+1];
                        }
                        for(int len= 4; len<(src.size()-2); len++)
                        {
                            sum_val += src[len+1];
                        }
                        mem_address = memory[rgstr[map_opcode_values[src_reg]]+ stoi(sum_val)];
                        load(dst, mem_address);
                    }

                    else if(src[0]== '=')
                    {
                        for(int len=0; len<(src.size()-1); len++)
                        {
                            src_reg += src[len+1];
                        }
                        mem_address= stoi(src_reg);
                        load(dst, mem_address);
                    }

                    else if((src[0] == '[') && (src[(src.size()-1)]= ','))
                    {
                        for(int len=0; len<(src.size()-1); len++)
                        {
                            src_reg += src[len+1];
                        }
                        string src_with_spacebar;
                        file>>src_with_spacebar;
                        for(int len=0; len<(src_with_spacebar.size()-2); len++)
                        {
                            sum_val += src_with_spacebar[len+1];
                        }
                        mem_address = memory[rgstr[map_opcode_values[src_reg]]+ stoi(sum_val)];
                        load(dst, mem_address);
                    }
                    else
                    {
                        cout<<"Invalid Instruction!!!"<<endl;
                    }
                    break;
                }

                case str:
                {
                    string src, dst, dst_address, sum_val;
                    int data, destination_address;
                    file>>src;
                    file>>dst;
                    cout<<endl<<"Store instruction given here"<<endl;
                    if(dst.size()==4 && dst[0] == '[' && dst[3]== ']')
                    {
                        for(int len= 0; len<2; len++)
                        {
                            dst_address += dst[len+1];
                        }
                        destination_address= rgstr[map_opcode_values[dst_address]];
                        data = rgstr[map_opcode_values[src]];
                        store(destination_address, data);
                    }

                    else if((dst[0] == '[') && (dst[(dst.size()-1)]==']') && (dst.size()!=4 || dst.size()!=5))
                    {
                        for(int len= 0; len<3; len++)
                        {
                            dst_address += dst[len+1];
                        }
                        for(int len= 4; len<(dst.size()-2); len++)
                        {
                            sum_val += dst[len+1];
                        }
                        destination_address = rgstr[map_opcode_values[dst_address]]+ stoi(sum_val);
                        data = rgstr[map_opcode_values[src]];
                        store(destination_address, data);
                    }

                    else if(dst[0]== '#')
                    {
                        for(int len=0; len<(dst.size()-1); len++)
                        {
                            dst_address += dst[len+1];
                        }
                        destination_address = stoi(dst_address);
                        data = rgstr[map_opcode_values[src]];
                        store(destination_address, data);
                    }
                    
                    else if((dst[0] == '[') && (dst[(dst.size()-1)]= ','))
                    {
                        for(int len=0; len<(src.size()-1); len++)
                        {
                            dst_address += dst[len+1];
                        }
                        string dst_with_spacebar;
                        file>>dst_with_spacebar;
                        for(int len=0; len<(src.size()-2); len++)
                        {
                            sum_val += dst_with_spacebar[len+1];
                        }
                        destination_address = rgstr[map_opcode_values[dst_address]]+ stoi(sum_val);
                        data = rgstr[map_opcode_values[src]];
                        store(destination_address, data);
                    }
                    else
                    {
                        cout<<"Invalid Instruction!!!"<<endl;
                    }
                    break;
                }

                case cmp:
                {
                    cout<<endl<<"Compare instruction given here"<<endl;
                    break;
                }

                case mov:
                {
                    string dst, src, src_val_string;
                    file>>dst;
                    file>>src;
                    cout<<endl<<"Move instruction given here"<<endl;
                    int src_val;
                    if (src[0] != '#')
                    {
                        src_val = stoi(src);
                        move(dst, src_val);
                    }
                    else
                    {
                        for(int len=0; len<(src.size()-1); len++)
                        {
                            src_val_string += src[len+1];
                        }
                        src_val = stoi(src_val_string);
                        move(dst, src_val);
                    }
                    break;
                }

                case bge:
                {
                    string src1, src2, lable;
                    file>>src1;
                    file>>src2;
                    file>>lable;
                    cout<<endl<<"Branch if greater than or equal instruction given here"<<endl;
                    if (cmpr(src1, src2) == 1)
                    // do branching
                    cout<<"Unable to do branchig due to lable problem"<<endl;
                    break;
                }
                
                case bne:
                {
                    string src1, src2, lable;
                    file>>src1;
                    file>>src2;
                    file>>lable;
                    cout<<endl<<"Branch if not equal instruction given here"<<endl;
                    if (cmpr(src1, src2) == 2)
                    // do branching
                    cout<<"Unable to do branchig due to lable problem"<<endl;
                    break;
                }

                case b:
                {
                    string lable;
                    file>>lable;
                    cout<<endl<<"Branch instruction given here"<<endl;
                    cout<<"Unable to do branchig due to lable problem"<<endl;
                }

                default:
                {
                    cout<<endl<<"Something which I can't understand is called here. The called operator is: ";
                    cout<<opcode<<endl;
                    break;
                }
            }
}