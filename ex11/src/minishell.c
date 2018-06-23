#include "../include/minishell.h"





int main(){
    hashtable_t *ht;
    ht = hash_create(100);

    //1:load config files

    //2:run an REPL loop
    lsh(ht);
    //3:perform shutdown clean up
    return 0;
}
