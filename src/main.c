#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "loading.h"
#include "interpreter.h"

int main(int argc, char *argv[]){
    if (argc==0 || argc==1){
        printf("[ERROR]: No input files\n");
        return -1;
    }

    FILE *fptr = fopen(argv[1], "r");
    if (fptr==NULL){
        printf("[ERROR]: Failed to open file\n");
        return -2;
    }

    char *program;
    size_t program_length;
    load_program(fptr, &program, &program_length);
    if (program==NULL){
        printf("[ERROR]: Failed to read file\n");
        return -2;
    }
    fclose(fptr);
    
    char *error;
    int status = interpret(program, program_length, &error);
    free_program(program);

    if (status==1){
        printf("[ERROR]: Syntax error\n");
        printf("%s", error);
        return 1;
    }
    if (status==2){
        printf("[ERROR]: Memory error\n");
        printf("%s", error);
        return 2;
    }

    return 0;
}