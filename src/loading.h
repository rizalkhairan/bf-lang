#ifndef LOADING_H
#define LOADING_H

#include <stdio.h>
#include <stdlib.h>


/* Size of each input chunk to be
   read and allocate for. */
#ifndef  READALL_CHUNK
#define  READALL_CHUNK  262144
#endif

#define  READALL_OK          0  /* Success */
#define  READALL_INVALID    -1  /* Invalid parameters */
#define  READALL_ERROR      -2  /* Stream error */
#define  READALL_TOOMUCH    -3  /* Too much input */
#define  READALL_NOMEM      -4  /* Out of memory */

/* This function returns one of the READALL_ constants above.
   If the return value is zero == READALL_OK, then:
     (*dataptr) points to a dynamically allocated buffer, with
     (*sizeptr) chars read from the file.
     The buffer is allocated for one extra char, which is NUL,
     and automatically appended after the data.
   Initial values of (*dataptr) and (*sizeptr) are ignored.
*/
int readall(FILE *in, char **dataptr, size_t *sizeptr);

// Read the whole file and load into memory allocated in this function
// Upon success, *program points to the allocated buffer with *length the size of the buffer
// Must be freed by calling
void load_program(FILE* fileptr, char **program, size_t *length);

// Free the memory allocated by load_program
void free_program(char *program);

#endif