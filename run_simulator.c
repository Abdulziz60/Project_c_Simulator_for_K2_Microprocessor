#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "fetch.h"

void run_simulator(char *filename) {
    char memory[256];
    load(memory, &filename);
    printf("Starting simulator for %s\n", filename);

    char mode;
    printf("Select mode (R for continuous, S for step-by-step): ");
    scanf(" %c", &mode);
    while (getchar() != '\n');

    if (mode == 'S') {
        printf("Starting step-by-step mode...\n");
    } else {
        printf("Starting continuous mode...\n");
    }

    fetch(memory, mode); // Call fetch function to process instructions
}
