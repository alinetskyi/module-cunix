#define _DEFAULT_SOURCE
#include <dirent.h>
#include "../include/lsh.h"
#define LSH_BUFSIZE 1024
#define _GNU_SOURCE
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"






    int lsh_exit(char **args,hashtable_t *ht);
      int lsh_export(char **args,hashtable_t *ht);
      int lsh_env(char **args,hashtable_t *ht);
      int lsh_echo(char**args,hashtable_t *ht);
      int lsh_ls(char **args,hashtable_t *ht);

 char *builtin_str[] = {
        "exit",
        "env",
        "export",
        "echo",
        "ls"
      };
   
   
      int (*builtin_func[]) (char **,hashtable_t *ht) = {
        &lsh_exit,
        &lsh_env,
        &lsh_export,
        &lsh_echo,
        &lsh_ls
      };
   int lsh_num_builtins() {
     return sizeof(builtin_str) / sizeof(char *);
 }



void lsh(hashtable_t *ht) {
    char *line;
    char **args;
    int status;
    
    do{
        printf("$_>");
        line = lsh_read_line();
        args = lsh_split_line(line);
        status = lsh_execute(args,ht);
        
        free(line);
        free(args);
    }while(status);

}

int lsh_err(char **args) {
    printf("%s :",*args);
  printf(" This command is not found...\n");
  return 1;

}


char *lsh_read_line(void) {
    int bufsize = LSH_BUFSIZE;
    int pos = 0;
    char *buff = malloc(sizeof(char)*bufsize);
    int c;

    if(!buff) {
        printf("Buffer failure\n");
        exit(EXIT_FAILURE);
    }

    while(1) {
        c = getchar();

    if (c == EOF || c == '\n') {
      buff[pos] = '\0';
      return buff;
    } else {
      buff[pos] = c;
    }
    pos++;
    if (pos >= bufsize) {
      bufsize += LSH_BUFSIZE;
      buff = realloc(buff, bufsize);
      if (!buff) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}



char **lsh_split_line(char *line) {
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}



int lsh_execute(char **args,hashtable_t *ht) {
  int i;

  if (args[0] == NULL) {
    printf("No command was entered...\n");
    return 1;
  }

  for (i = 0; i < lsh_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args, ht);
    }
  }

  return lsh_err(args);
}
