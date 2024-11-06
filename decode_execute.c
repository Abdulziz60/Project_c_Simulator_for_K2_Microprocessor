#include <stdio.h>
#include "alu.h"
#include "decode_execute.h"

void decode_execute(char command[], int PC){
    static int J, C, D1, D0, Sreg, RA = 0, RB = 0, RO = 0;

    J = (command[0] == '0') ? 0 : 1;
    C = (command[1] == '0') ? 0 : 1;
    D1 = (command[2] == '0') ? 0 : 1;
    D0 = (command[3] == '0') ? 0 : 1;
    Sreg = (command[4] == '0') ? 0 : 1;

    printf("Decoded values: J=%d, C=%d, D1=%d, D0=%d, Sreg=%d\n", J, C, D1, D0, Sreg);

    int tempVlaue;

    if(Sreg == 0){
        tempVlaue = alu(RA, RB, command[5]);
    } else {
        if(command[5] == '0' && command[6] == '0' && command[7] == '0'){
            tempVlaue = 0;
        } else if(command[5] == '0' && command[6] == '0' && command[7] == '1'){
            tempVlaue = 1;
        } else if(command[5] == '0' && command[6] == '1' && command[7] == '0'){
            tempVlaue = 2;
        } else if(command[5] == '0' && command[6] == '1' && command[7] == '1'){
            tempVlaue = 3;
        } else if(command[5] == '1' && command[6] == '0' && command[7] == '0'){
            tempVlaue = 4;
        } else if(command[5] == '1' && command[6] == '0' && command[7] == '1'){
            tempVlaue = 5;
        } else if(command[5] == '1' && command[6] == '1' && command[7] == '0'){
            tempVlaue = 6;
        } else if(command[5] == '1' && command[6] == '1' && command[7] == '1'){
            tempVlaue = 7;
        } 
    }

    if(D0 == 0 && D1 == 0){
        RA = tempVlaue & 0xf;
        printf("Updated RA: %d\n", RA);
    } else if(D0 == 1 && D1 == 0){
        RB = tempVlaue & 0xf;
        printf("Updated RB: %d\n", RB);
    } else if(D0 == 0 && D1 == 1){
        printf("Comparing RO: %d with RA: %d\n", RO, RA);
        if (RO == RA) {
            RO = RA;
            printf("Updated RO: %d\n", RO);
        }
    } else {
        printf("No register used !!! \n");
    }

    tempVlaue = alu(RA, RB, command[5]);
    char binaryNumber[32];
    int n = tempVlaue; int i = 0;
    while(n != 0){
        binaryNumber[i++] = (n % 2 == 0) ? '0' : '1';
        n /= 2;
    }
    binaryNumber[i] = '\0';

    if(i > 0 && ((binaryNumber[i-1] == '1' && C == 1) || J == 1)){
        printf("Condition met: binaryNumber[%d] = 1, C = %d, J = %d\n", i - 1, C, J);
        PC = (J == 1) ? (PC + tempVlaue) : (PC + 1);
    } else {
        PC += 1;
    }
    printf("RA=%d, RB=%d, RO=%d\n", RA, RB, RO);
}

