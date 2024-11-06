#include <stdio.h>
#include <stdlib.h>
#include "load.h"

void load(char memory[], char* argv[]){
    printf("Loading binary file: %s\n", "fibonacci.bin");
    FILE* ptr = fopen("fibonacci.bin", "rb");
    if(!ptr){
        printf("Error: file cannot be opened\n");
        exit(0);
    }
    fread(memory, sizeof(char), 256, ptr);
    fclose(ptr);
}

