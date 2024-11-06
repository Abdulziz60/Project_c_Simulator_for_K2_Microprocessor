#include "alu.h"

int alu(int ra, int rb, char s) {
    if(s == '0'){
        return ra + rb;
    } else {
        return ra - rb;
    }
}

