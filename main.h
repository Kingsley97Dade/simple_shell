#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>


/* Interactive Header prototypes*/
int create_process(char **args);
char *get_stream(void);
char **divide_line(char *line);
char *scan_line(void);
void myshell_isnot(void);
void myshell_works(void);
int interactive_func(void);

/*string headers*/
char *strcpy(char *dest, const char *src);
char *strdup(const char *str);


#endif /* MAIN_H */
