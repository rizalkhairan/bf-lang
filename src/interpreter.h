#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdlib.h>

#ifndef MEMSIZE
#define MEMSIZE 30000
#endif

// Interpret a BF program
// Return 
//      0: Program executed with no error
//      1: Syntax error, specified by err   
//      2: Memory out of bound
int interpret(char *program, size_t program_length, char **err);

#endif