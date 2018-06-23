#ifndef BASICS_H_   
 #define BASICS_H_
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
 
 int lsh_export(char **args,hashtable_t *ht);
 int lsh_env(char **args, hashtable_t *ht);
 int lsh_exit(char **args, hashtable_t *ht);
 int lsh_echo(char **args, hashtable_t *ht);
 int lsh_ls(char **args,hashtable_t *ht);
 
 
 #endif // BASICS_H_

