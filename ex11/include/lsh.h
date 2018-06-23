#ifndef LSH_H_   
#define LSH_H_
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "hash.h"
#include "linked_list.h"
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include "basics.h"

void lsh(hashtable_t *ht);
char *lsh_read_line(void);
char **lsh_split_line(char *line);
int lsh_err(char **args);
int lsh_execute(char **args,hashtable_t *ht);


#endif // LSH_H_
