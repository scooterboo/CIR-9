# CIR-9
A 9 bit architecture designed from scratch.   

#### instructions are 9 bits long: 
9 bit words are called baker's bytes (or bbytes for short)  
Typically, a 5 bit OP code and two 2-bit register designaters  
```
  OP code    From Reg   To Reg
[_ _ _ _ _] + [_ _]  +  [_ _]
```

There are four registers, each register is 9 bits long:  
```
00 Register A
01 Register B
10 Register C
11 Register D
```

#### Addresses are 11 bits long.
Each memory word is 9 bits.  
The #6 load number, #22 jump, and all memory operation are 2 bbytes long.  
We get those 11 bits by concatenating the last 2 bits of the instruction with the next bbyte.  

#### Here is the list of OP codes:  

##### basic operations:  
```
00000 [00] "LD " Take the memory location obtained from the last 2 bits of the instruction and the next bbyte, and put it in the From Register
          [00000] [_ _] <- ([_ _] & [_ _ _ _ _ _ _ _ _])
00001 [01] "STR" Take the From Register and put it into the memory location obtained from the next 11 bits.
          [00001] [_ _] -> ([_ _] & [_ _ _ _ _ _ _ _ _])
00010 [02] "ADD" Add the From Register to the To Register and store the result into the To Register.
00011 [03] "SUB" Subtract the To Register from the From Register and store the result into the To Register.
00100 [04] "CP " Copy the From Register to the To Register. The To Register gets overwritten.
00101 [05] "SWP" Swap the From Register and the To Register.
00110 [06] "LDN" Load the next 9 bits into the To Register.
00111 [07] "NEG" Take the twos complement negative of the From Register and store the result into the To Register.
```

##### Logical Operations:  
```
01000 [08] "AND" Logical AND the From Register and the To Register and store the result into the To Register.
01001 [09] "NND" Logical NAND the From Register and the To Register and store the result into the To Register.
01010 [10] "OR " Logical OR the From Register and the To Register and store the result into the To Register.
01011 [11] "NOR" Logical NOR the From Register and the To Register and store the result into the To Register.
01100 [12] "XOR" Logical XOR the From Register and the To Register and store the result into the To Register.
01101 [13] "SHR" Logical shift the From Register one bit to the right and store the result into the To Register.
01110 [14] "SHL" Logical shift the From Register one bit to the left and store the result into the To Register.
01111 [15] "NOT" Logical NOT the From Register and store the result into the To Register.
```

##### Jump Operations:  
```
10000 [16] "JEQ" jump 2 bbytes ahead if the From Register equals the To Register.
10001 [17] "NEQ" jump 2 bbytes ahead if the From Register does not equal the To Register.
10010 [18] "JMT" jump 2 bbytes ahead if the From Register is more than the To Register.
10011 [19] "NMT" jump 2 bbytes ahead if the From Register is not more than the To Register. (less than or equal to)
10100 [20] "JLT" jump 2 bbytes ahead if the From Register is less than the To Register.
10101 [21] "NLT" jump 2 bbytes ahead if the From Register is not less than the To Register. (more than or equal to)
10110 [22] "JMP" jump to the memory location obtained from the last 2 bits of the instruction and the next bbyte.
10111 [23] "NOP" jump to the next bbyte (No Operation)
```

##### Experimental Operations: (don't use these (except HLT))  
```
11000 [24] "VID" output the From register in 9 bit color (3R3G3B) to a pixel array given by the last 2 bits of the instruction and the next bbyte. (512 color!)
11001 [25] "BEP" beep a tone from 0 to 2^18 -1 given from concatenating the From Register to the To Register. (18 bit sound!)
11010 [26] "MUL" multiply the From Register to the To Register and put the first bbyte into the From Register and the second bbyte into the To register. 
11011 [27] "SER" Output the From register to a 9 pin serial connector on the back of the computer.
11100 [28] "SAV" Save the From Register to the stack. (the stack is bottomless)
11101 [29] "LDS" Load top of the stack to the To Register.
11110 [30] "CD " Open/Close the CD tray/beer holder. (this is a joke)
11111 [31] "HLT" Stop the computer. Output debug info if you have it.
```
