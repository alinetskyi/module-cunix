#include <stdio.h>
#include <stdlib.h>
#include "../include/hash.h"
#include "../include/linked_list.h"
#include <assert.h>
#include <string.h>

//*hash_create: Creataes a hashtable
hashtable_t *hash_create(unsigned int size){
        hashtable_t* newtable;
        if(size == 0){
            newtable = NULL;
            return newtable;
        }
        newtable = malloc(sizeof(hashtable_t));
        newtable->size = size;
        newtable->table = malloc(size*sizeof(node_t));
        return newtable;
}

//hash_destroy: Deletes a hashtable
void hash_destroy(hashtable_t *ht, void(*fp)(void *data)){
        (*fp)(ht->table);
        free(ht);
}

//hash_func: Hash function 
unsigned int hash_func(char *key){
     int g = 31;
     unsigned int hash = 1;
     if(key != NULL){
        for(;*key != '\0';key++){
            hash = g*hash+(int)*key; 
         }
     }
    return hash;

}

//hash_set: sets hashes to the table
void hash_set(hashtable_t *ht, char *key, void *ptr){
    
    int i = hash_func(key) % ht->size;

  if (ht->table[i] == NULL) {
    ht->table[i] = list_create(ptr, key);
  }
  else {
    list_push(ht->table[i], ptr, key);
  }

}


void *hash_get(hashtable_t *ht, char *key){
    int index = hash_func(key)%(ht->size);
    if(ht->table[index] == NULL){
        return NULL;
    }
    return find_key(ht->table[index], key);
}






void hash_print(hashtable_t *ht){
    for (unsigned int i = 0; i < ht->size; i++)
        list_print((node_t*)ht->table[i]);
}
/*

int main(){
    test_large();
}
*/
