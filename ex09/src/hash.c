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
void hash_set(hashtable_t *ht, char *key, void *ptr, void (*fp)(void *data)){
    //void *table[ht->size];
    int index = hash_func(key)%(ht->size);
  //  printf("%d\n",index);
    //ht->table = table;
    fp(ptr);
    if(ht->table[index] == NULL){
        ht->table[index] = list_create(ptr);
    }
    else{
        list_push(ht->table[index],ptr);
    }
    
}


void *hash_get(hashtable_t *ht, char *key){
    int index = hash_func(key)%(ht->size);
    if(ht->table[index] == NULL){
        return NULL;
    }
    node_t *nptr = ht->table[index];
    return nptr->data;
}




/*
 void test_func_noop(void *data)
      {
     data;
      }


int main(){
    test_large();
}
*/
