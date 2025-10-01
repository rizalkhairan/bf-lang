#include <stdio.h>
#include "interpreter.h"

static char MEM[MEMSIZE];
static char *dp;
static char *ip;

int interpret(char *program, size_t program_length, char **err){
    dp = MEM;
    ip = program;
    char *program_end = program+program_length;
    while (ip<program_end){
        char i = *ip;

        if (i=='>'){
            dp++;
            if (dp>=MEM+MEMSIZE){
                *err = "Memory out of bound\n";
                return 2;
            }
        }
        else if (i=='<'){
            dp--;
            if (dp<MEM){
                *err = "Memory out of bound\n";
                return 2;
            }
        }
        else if (i=='+'){
            *dp = *dp+1;
        }
        else if (i=='-'){
            *dp = *dp-1;
        }
        else if (i=='.'){
            putchar(*dp);
        }
        else if (i==','){
            scanf("%c", dp);
        }
        else if (i=='[' && *dp==0){
            int matches = 1;
            while (*ip!=']' || matches!=0){
                ip++;
                if (!(ip<program_end)){
                    *err = "Unmatched '[' in the program\n";
                    return 1;
                }

                if (*ip=='[') matches++;
                if (*ip==']') matches--;
                if (matches<0){
                    *err = "Unmatched ']' in the program\n";
                    return 1;
                }
            }
        }
        else if (i==']' && *dp!=0){
            int matches = 1;
            while (*ip!='[' || matches!=0){
                ip--;
                if (ip<program){
                    *err = "Unmatched ']' in the program\n";
                    return 1;
                }

                if (*ip==']') matches++;
                if (*ip=='[') matches--;
                if (matches<0){
                    *err = "Unmatched '[' in the program\n";
                    return 1;
                }
            }
        }

        ip++;
    }

    return 0;
}