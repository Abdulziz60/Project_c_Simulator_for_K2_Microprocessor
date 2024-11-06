#include <stdio.h>
#include "run_simulator.h"

int main(int argc, char* argv[]){
    if (argc < 2) {
        printf("Usage: %s <binary file>\n", argv[0]);
        return 1;
    }
    run_simulator(argv[1]);
    return 0;
}
