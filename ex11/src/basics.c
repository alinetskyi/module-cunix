   #define _DEFAULT_SOURCE
   #define LSH_BUFSIZE 1024
   #define _GNU_SOURCE
   #define LSH_TOK_BUFSIZE 64
   #define LSH_TOK_DELIM " \t\r\n\a" 
   #include "../include/basics.h"
   #include <dirent.h> 
   #include "../include/lsh.h"
   /*
     Builtin function implementations.
   */
   int lsh_ls(__attribute__((unused)) char **args,
__attribute__((unused)) hashtable_t *ht)
   {
       struct dirent **namelist;
          int n;
   
          n = scandir(".", &namelist, NULL, alphasort);
          if (n < 0)
              perror("scandir");
          else {
              while (n--) {
                  printf("%s\n", namelist[n]->d_name);
                  free(namelist[n]);
              }
              free(namelist);
          }
          return 1;
   }
int lsh_echo(char **args,hashtable_t *ht) {
       char *tmp;
       int i = 1;
       while(args[i] != NULL) {
           if(args[i][0] == '$'){
           tmp = strtok (args[i],"$");
            printf("%s ",(char *)(hash_get(ht,tmp)));
              i++;
           }
           else{
               printf("%s ",(args[i]));
               i++;
           }
       }
       printf("\n");
   
       return 1;
   }
   
   int lsh_env(__attribute__((unused)) char **args,hashtable_t *ht) {
       hash_print(ht);
       return 1;
   }
   int lsh_export(char **args,hashtable_t *ht) {
    
       if(*++args != NULL){
               char *str, *variable, *value, *tmp;
               str = *args;
               tmp = strtok(str,"=");
               variable = malloc(sizeof(char)*(strlen(tmp)+1));
               strcpy(variable, tmp);
               tmp = strtok (NULL,"=");
               while (tmp != NULL){
                   value = malloc(sizeof(char)*(strlen(tmp)+1));
                   strcpy(value, tmp);
                   tmp = strtok (NULL,"=");
               }
               if(value != NULL){
                   hash_set(ht,(void*)variable,(void*)value);
                   return 1;
               }
              }
               printf("There is nothing to export\n");
	       return 1;
   }
   
   int lsh_exit(__attribute__((unused)) char **args,__attribute__((unused)) hashtable_t *ht) {
     return 0;
   }

