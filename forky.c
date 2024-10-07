#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pattern_one(int num) {
    printf("Process 1 beginning\n");
    
    for (int i = 0; i < num; i++) {
        printf("Process %d creating Process %d\n", 1, i + 1);
    }
    printf("Process 1 exiting\n");
}

void pattern_two(int num) {
    printf("Process 1 beginning\n");
    
    for (int i = 1; i <= num - 1; i++) {
        printf("Process %d creating Process %d\n", i, i + 1);
    }
    printf("Process %d exiting\n", num);
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Wrong Argument: expected 2 arguments, got %d\n", argc - 1);
        exit(1);
    }

    int num = atoi(argv[1]);
    int pattern = atoi(argv[2]);

    if (num < 1 || num > 256) {
        printf("Number of things must be between 1 and 256.\n");
        return 1;
    }

    if (pattern == 1) {
        pattern_one(num);
    } else if (pattern == 2) {
        pattern_two(num);
    } else {
        printf("Error.\n");
        return 1;
   }

    return 0;
}
