#include <stdio.h>
#include <ctype.h>
#include "decode_execute.h"

void fetch(char memory[], char mode ){
    int CompleteByte = 0;
    char Byte[9];
    
    for(int PC = 0 ; PC < 256; PC++){
        if(isalpha(memory[PC]) || isdigit(memory[PC])){
            Byte[CompleteByte++] = memory[PC];
        }
        if(CompleteByte == 8){
            Byte[CompleteByte] = '\0';
            CompleteByte = 0;
            printf("%s\n", Byte);
            decode_execute(Byte, PC);
            
            if (mode == 'S') {
                printf("[Press Enter to continue]\n");
		while (getchar() != '\n');
            }
        }
    }
}
