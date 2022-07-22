#ifndef MAIN_H
#define MAIN_H
/* standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <sys/stat.h>

/* function prototypes */
int command(char *cmd);
int count_args(char *str);
void tokenize_string(char *buff);
char *prep_string(char *cmd);


#endif
