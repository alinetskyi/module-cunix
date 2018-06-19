#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"
#include <string.h>
#include <assert.h>

node_t *list_create(void *data){
	node_t* head;
	head = malloc(sizeof(node_t));
	head->data = data;
	head->next = NULL;
	//printf("List was created");
	return head;
}

void list_destroy(node_t **head, void (*fp)(void *data)){
    node_t *e = (*head);
    while(e != NULL){
	    (*fp)(e->data);
        node_t* next = e->next;
        free(e);
        e = next;
	}	
	//printf("List was destroyed");					
}

void destroy_noop(void *data)
{
  data;
}
void destroy_push(void *data){
    free(data);
}

//Push an element to the end of the list 
void list_push(node_t *head, void *data){
	node_t *tmp = head;
    while (tmp->next != NULL){
        tmp = tmp->next;
    } 
    node_t* newNode;
    newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    tmp->next = newNode;
    //printf("element was pushed %s\n", newNode->data);
}
//Put an element at the beginning
void list_unshift(node_t **head, void *data){
    node_t* newNode;
    newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = (*head);
    *head = newNode; 
}
//Remove element from the end 
void *list_pop(node_t **head){
    node_t *tmp = *head;
    node_t *nptr;
    while(tmp->next != NULL){
        nptr = tmp;
        tmp = tmp->next;
    }
    nptr->next = NULL;
    free(tmp);
    
}
//Remove element from the begining
void *list_shift(node_t **head){
    node_t *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

//Removes element by its position in the list
void *list_remove(node_t **head, int pos){
    node_t *tmp;
    node_t *np = *head;
    if( pos == 0){
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
        return;
    }
    for(int i = 0;i<pos-1;i++){
        np = np->next;
        //printf("pos is: %d",pos);
        //printf("i is: %d",i);
    }
    node_t *nxtptr = np->next->next;
    free(np->next);
    np->next = nxtptr;
}

//Prints data of each element in the list
void list_print(node_t *head){
    while(head->next != NULL){
        printf(head->data);
        head = head->next;
    }
    printf(head->data);
}

//Visits every element and applies a fucntion to it
void list_visitor(node_t *head, void (*fp)(void *data)){
     while(head->next != NULL){
           (*fp)(head->data);
           head = head->next;
       }
       (*fp)(head->data);
}
void debug_print(void *data)
{
  printf("DEBUG: %s\n", (char *) data);
}


/*
int main(){



    
	node_t *head;
    char *str;
	head = list_create("test");
	//printf("listname: %s", head->data);
    //list_destroy(&head,&destroy_noop);
	//printf("listname: %s", head->data);
    list_push(head, "dsa");
	list_unshift(&head,"sad");
    //list_pop(&head);
    //list_shift(&head);
    list_remove(&head,3);
    list_destroy(&head,&destroy_noop);
	//list_unshift(&head,"s","32");
    

}

*/
