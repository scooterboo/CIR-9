#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 

#define DEBUG false

using namespace std;


int memory[2048]={0};
bool running = true;



void loadmemory(string filename);

int main()
{
  loadmemory("instructions.txt");
  int curr_ptr=0;
  int curr=0;
  int Reg[4]={0};
  int A=0;  
  int B=0;
  int tmp=0;
  
  while(running){
    curr = memory[curr_ptr];
    A = (curr>>2)&3;
    B = curr&3;
    
    switch(curr>>4){
      case 0: //LD : Load Mem->RegA
        
        break; 
      case 1: //STR: Store RegA->Mem
        
        break;
      case 2: //ADD: 
        Reg[B] = (Reg[A] + Reg[B])&1023;
        break;
      case 3: //SUB:
        Reg[B] = (Reg[A] - Reg[B])&1023;
        break;
      case 4: //CP :
        Reg[B] = Reg[A];
        break;
      case 5: //SWP:
        tmp = Reg[B];
        Reg[B] = Reg[A];
        Reg[A] = tmp;
        break;
      case 6: //LDN:
        Reg[B] = memory[curr_ptr++];
        break;
      case 7: //NEG:
        Reg[B] = (0 - Reg[A])&1023;
        break;
      case 8: //AND:
        Reg[B] = Reg[A] & Reg[B];
        break;
      case 9: //NND:
        Reg[B] = (~(Reg[A] & Reg[B]))&1023;
        break;
      case 10://OR :
        Reg[B] = Reg[A] | Reg[B];
        break;
      case 11://NOR:
        Reg[B] = (~(Reg[A] | Reg[B]))&1023;
        break;
      case 12://XOR:
        Reg[B] = Reg[A] ^ Reg[B];
        break;
      case 13://SHR:
        Reg[B] = Reg[B]>>1;
        break;
      case 14://SHL:
        Reg[B] = (Reg[A]<<1)&1023;
        break;
      case 15://NOT:
        Reg[B] = (~Reg[A])&1023;
        break;
      case 16://JEQ:
        
        break;
      case 17://NEQ:
        
        break;
      case 18://JMT:
        
        break;
      case 19://NMT:
        
        break;
      case 20://JLT:
        
        break;
      case 21://NLT:
        
        break;
      case 22://JMP:
        
        break;
      case 23://NOP:
        // -\o.o/-
        break;
      case 24://VID:
        
        break;
      case 25://BEP:
        
        break;
      case 26://MUL:
        Reg[B] = (Reg[A] * Reg[B])&1023;
        break;
      case 27://SER:
        
        break;
      case 28://SAV:
        
        break;
      case 29://LDS:
        
        break;
      case 30://CD :
        
        break;
      case 31://HLT:
        
        break;
      default:
        cout<<"WTF! TOO HIGH VALUE FOR OP CODE ON MEMORY ADDR: "<<curr_ptr<<"\n";
        running= false;
    }
    curr_ptr++;
  }
}

void loadmemory(string filename){
  string line;
  ifstream ops (filename.c_str());
  if (ops.is_open())
  {
    int i=0;
    while ( getline(ops,line) )
    {
      memory[i]= atoi(line.c_str());
      i++;
    }
    ops.close();
  }
}