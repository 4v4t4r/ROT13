#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

#ifdef __linux__

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

#endif

int convert(char* input, int key);
int check_extension(char* input);