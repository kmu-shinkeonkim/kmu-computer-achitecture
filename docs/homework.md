1) 프로그램이 하는 일을 C 언어로 표현하라

#include <stdio.h>

int main() {
    int a[5] = {30, 50, -10, 45, 100};
    
    int* s0 = a;
    int s1 = 5;
    int s2 = 0;

    for(int t0 = 0; t0 < s1; t0++) {
        int t2 = *s0;
        s2 += t2;
        s0+=1;
    }
}


2) nop를 제외한 명령어 12개를 모두 2진수로 표현하고 R, I, J format 중 어느 format인지 설명하고
field 별로 나누어 그 의미를 설명하라(MIPS opcode map 참조)


1. lui $s0, 0x1001 (0x3c101001)
- i format
- `0011 1100 0001 0000 0001 0000 0000 0001`
- field
    - op(6bits): `001111` 이며, lui의 op코드이다.
    - rs(5bits): `00000` 이며, lui instruction에서는 비워둔다.  
    - rt(5bits): `10000` 이며, $s0을 의미한다. 
    - constant or address(16bits) : `0001 0000 0000 0001`이며, 0x1001이다.
- 따라서, 해당 instruction의 의미는 `0001 0000 0000 0001`의 16 bit 상수를  rt($s0)레지스터의 왼쪽(upper) 16 bits에 쓴다는 것이다.

2. addi $s1, $0, 5 (0x20110005)
- i format
- ``
- field
    - op(6bits): 
    - rs(5bits): 
    - rt(5bits):  
    - constant or address(16bits) :
- 따라서, 

3. add $t0, $0, $0  (0x00004020)
- r format
- ``
- field
    - op(6bits): 
    - rs(5bits):
    - rd(5bits):
    - shamt(5bits):
    - funct(6bits):
- 따라서, 

4. add $s2, $0, $0 (0x00009020)
- r format
- ``
- field
    - op(6bits): 
    - rs(5bits):
    - rd(5bits):
    - shamt(5bits):
    - funct(6bits):
- 따라서, 

5. slt $t1, $t0, $s1 (0x0111482a)
6. beq $t1, $0, end (0x11200006)
7. lw $t2, 0($s0) (0x8e0a0000)
8. add $s2, $s2, $t2 (0x024a9020)
- r format
- ``
- field
    - op(6bits): 
    - rs(5bits):
    - rd(5bits):
    - shamt(5bits):
    - funct(6bits):
- 따라서, 

9. addi $t0, $t0, 1 (0x21080001)
- i format
- ``
- field
    - op(6bits): 
    - rs(5bits): 
    - rt(5bits):  
    - constant or address(16bits) :
- 따라서, 

10. addi $s0, $s0, 4 (0x22100004)
- i format
- ``
- field
    - op(6bits): 
    - rs(5bits): 
    - rt(5bits):  
    - constant or address(16bits) :
- 따라서, 

11. j for (0x0810000d)
- j format

12. jr $ra (0x03e00008)
- j format
