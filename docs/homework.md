1) 프로그램이 하는 일을 C 언어로 표현하라
```c
#include <stdio.h>

int main() {
    int a[5] = {30, 50, -10, 45, 100};
    int sum = 0;

    for(int i = 0; i < 5; i++) {
        sum += a[i];
    }
}
```

2) nop를 제외한 명령어 12개를 모두 2진수로 표현하고 R, I, J format 중 어느 format인지 설명하고
field 별로 나누어 그 의미를 설명하라(MIPS opcode map 참조)


1. lui $s0, 0x1001 (0x3c101001)
- i format
- `0011 1100 0001 0000 0001 0000 0000 0001`
- field
    - op(6bits): `001111` 이며, lui의 op code는 0x0f이다.
    - rs(5bits): `00000` 이며, lui instruction에서는 생략되었다.
    - rt(5bits): `10000` 이며, $s0을 의미한다. 
    - constant or address(16bits) : `0001 0000 0000 0001`이며, instruction에서 0x1001이다.
- 따라서, 해당 instruction의 의미는 `0001 0000 0000 0001`의 16 bit 상수를  rt($s0)레지스터의 왼쪽(upper) 16 bits에 쓴다는 것이다.

2. addi $s1, $0, 5 (0x20110005)
- i format
- `0010 0000 0001 0001 0000 0000 0000 0101`
- field
    - op(6bits): `001000` 이며, addi의 op code는 0x08이다.
    - rs(5bits): `00000` 이며, instruction에서 $0을 의미한다.
    - rt(5bits):  `10001` 이며, $s1을 의미한다.
    - constant or address(16bits) : `0000 0000 0000 0101`이며, instruction에서 5이다.
- 따라서, 해당 insturction의 의미는 `0000 0000 0000 0101`의 16비트 상수를 sign extension한 숫자와 $0을 더한 숫자를 $s1 레지스터에 쓴다는 것이다.

3. add $t0, $0, $0  (0x00004020)
- r format
- `0000 0000 0000 0000 0100 0000 0010 0000`
- field
    - op(6bits): `000000` 이며, r format instruction의 op code는 0x00이다.
    - rs(5bits): `00000` 이며, instruction에서 $0을 의미한다.
    - rt(5bits): `00000` 이며, instruction에서 $0을 의미한다.
    - rd(5bits): `01000` 이며, $t0을 의미한다.
    - shamt(5bits): `00000` 이며, shift 연산을 하지 않음을 의미한다.
    - funct(6bits): `100000` 이며, add instruction의 function code는 32다.
- 따라서, 해당 instruction의 의미는 $0 + $0의 결과를 $t0 레지스터에 쓴다는 것이다.

4. add $s2, $0, $0 (0x00009020)
- r format
- `0000 0000 0000 0000 1001 0000 0010 0000`
- field
    - op(6bits): `000000` 이며, r format instruction의 op code는 0x00이다.
    - rs(5bits): `00000` 이며, instruction에서 $0을 의미한다.
    - rt(5bits): `00000` 이며, instruction에서 $0을 의미한다.
    - rd(5bits): `10010` 이며, $s2를 의미한다.
    - shamt(5bits): `00000` 이며, shift 연산을 하지 않음을 의미한다.
    - funct(6bits): `100000` 이며, add instruction의 function code는 32다.
- 따라서, 해당 instruction의 의미는 $0 + $0의 결과를 $s2 레지스터에 쓴다는 것이다.

5. slt $t1, $t0, $s1 (0x0111482a)
- r format
- `0000 0001 0001 0001 0100 1000 0010 1010`
- field
    - op(6bits): `000000` 이며, r format instruction의 op code는 0x00이다.
    - rs(5bits): `01000` 이며, instruction에서 $t0을 의미한다.
    - rt(5bits): `10001` 이며, instruction에서 $s1를 의미한다.
    - rd(5bits): `01001` 이며, instruction에서 $t1를 의미한다.
    - shamt(5bits): `00000` 이며, shift 연산을 하지 않음을 의미한다.
    - funct(6bits): `101010` slt instruction의 function code는 42다.
- 따라서, 해당 instruction의 의미는 $t0 레지스터에 있는 값이 $s1 레지스터에 있는 값보다 작은 경우, $t1 레지스터에 1를 쓰고 아니라면 0을 쓴다.

6. beq $t1, $0, end (0x11200006)
- i format
- `0001 0001 0010 0000 0000 0000 0000 0110`
- field
    - op(6bits): `000100` 이며, beq의 op code는 .
    - rs(5bits): `01001` 이며, $t1을 의미한다.
    - rt(5bits): `00000` 이며, $0를 의미한다.
    - constant or address(16bits) : `0000 0000 0000 0110`이며, target address는 PC + `0000 0000 0000 0110` x 4 이다. 현재 PC의 값은 `0000 0000 0100 0000 0000 0000 0001 0100` 이고, `0000 0000 0000 0110` x 4을 sign extension 한 값과 덧셈을 하면 `0x0040002c` 이므로 target address는 `0x0040002c`이다.
- 따라서, 해당 instructions의 의미는 $t1에 있는 값이 0이라면 위에서 구한 target address인 `0x0040002c`로 이동한다.

7. lw $t2, 0($s0) (0x8e0a0000)
- i format
- `1000 1110 0000 1010 0000 0000 0000 0000`
- field
    - op(6bits): `100011` 이며, lw의 op code는 0x23이다.
    - rs(5bits): `10000` 이며, $s0를 의미한다.
    - rt(5bits): `01010` 이며, $t2를 의미한다.
    - constant or address(16bits) : `0000 0000 0000 0000`
- 따라서, data segment에서 $s0에 적혀있는 주소에 있는 값을 $t2 레지스터에 불러와 쓴다는 것이다.

8. add $s2, $s2, $t2 (0x024a9020)
- r format
- `0000 0010 0100 1010 1001 0000 0010 0000`
- field
    - op(6bits): `000000` 이며, r format instruction의 op code는 0x00이다.
    - rs(5bits): `10010` 이며, $s2를 의미한다.
    - rt(5bits): `01010` 이며, $t2를 의미한다.
    - rd(5bits): `10010` 이며, $s2를 의미한다.
    - shamt(5bits): `00000` 이며, shift 연산을 하지 않음을 의미한다.
    - funct(6bits): `100000` 이며, add instruction의 function code는 32다.
- 따라서, 해당 instruction의 의미는 $s2 + $t2의 결과를 $s2 레지스터에 쓴다는 것이고, $s2 레지스터에 $t2의 값을 더하라는 것이 된다.

9. addi $t0, $t0, 1 (0x21080001)
- i format
- `0010 0001 0000 1000 0000 0000 0000 0001`
- field
    - op(6bits): `001000` 이며, addi의 op code는 0x08이다.
    - rs(5bits): `01000` 이며, $t0를 의미한다.
    - rt(5bits): `01000` 이며, $t0를 의미한다.
    - constant or address(16bits) : `0000 0000 0000 0001` 이며 instruction에서 1이다.
- 따라서, 해당 insturction의 의미는 `0000 0000 0000 0001`의 16비트 상수를 sign extension한 숫자와 $t0 레지스터의 값과 더한 숫자를 $t0 레지스터에 쓴다는 것이고, 결론적으로는 $t0 레지스터의 값을 1증가하는 것이다.

10. addi $s0, $s0, 4 (0x22100004)
- i format
- `0010 0010 0001 0000 0000 0000 0000 0100`
- field
    - op(6bits): `001000` 이며, addi의 op code는 0x08이다.
    - rs(5bits): `10000` 이며, $s0를 의미한다.
    - rt(5bits): `10000` 이며, $s0를 의미한다.
    - constant or address(16bits) : `0000 0000 0000 0100` 이며 instruction에서 4이다.
- 따라서, 해당 insturction의 의미는 `0000 0000 0000 0100`의 16비트 상수를 sign extension한 숫자와 $s0 레지스터의 값과 더한 숫자를 $s0 레지스터에 쓴다는 것이고, 결론적으로는 $s0 레지스터의 값을 4증가하는 것이며, 7번 instruction에서 lw를 하는 주소로 사용되는 $s0의 값을 4증가함으로써, data segment에서 다음 word를 불러올 수 있도록 한다.

11. j for (0x08100004)
- j format
- `0000 1000 0001 0000 0000 0000 0000 0100`
- field
    - op(6bits): `000010`이며, j의 op code는 0x02이다.
    - address(26bits): `00 0001 0000 0000 0000 0000 0100` 이며, jump할 instruction address를 나타내는데 해당 값에 4를 곱한 뒤, PC의 상위 4bits를 상위 비트로 가져온다. 그래서 `0000 0000 0100 0000 0000 0000 0001 0000`의 값을 가지게 되며 16진수로 나타내었을 때 `0x00400010`이다. 따라서, `0x00400010` 주소의 instruction으로 이동한다.
따라서, `0x00400010`주소의 instruction으로 점프(이동)하라는 instruction이다.

12. jr $ra (0x03e00008)
- r format
- `0000 0011 1110 0000 0000 0000 0000 1000`
- field
    - op(6bits): `000000` 이며, r format instruction의 op code는 0x00이다.
    - rs(5bits): `11111` 이며, $ra를 의미한다.
    - rt(5bits): `00000` 이며, 비워둔다.
    - rd(5bits): `00000` 이며, 비워둔다.
    - shamt(5bits): `00000` 이며, 비워둔다.
    - funct(6bits): `001000` 이며,  jr instruction의 function code는 8이다.
따라서, $ra에 저장되어있는 주소의 instruction으로 점프(이동)하라는 instruction이다.