#include <stdio.h>
#include <stdlib.h>
#include "../include/binary_tree.h"
#include <assert.h>
#include <string.h>

//Allocate some memory for the node
node_t *allocnode(){
    malloc(sizeof(node_t));
}

node_t *insert(node_t *root, char *key, void *data){
    node_t *newNode;
    newNode = allocnode();
    newNode->data = data;
    newNode->key = key;
    newNode->right = NULL;
    newNode->left = NULL;
    if(root == NULL){
        return newNode;
    }

    if(*key%2 == 0){
        root->left = newNode;
        return newNode;
    }
    else{
        root->right = newNode;
        return newNode;
    }

}

void print_node(node_t *node){
     if(node != NULL){
        printf(node->data);
     }
}

void visit_tree(node_t *node, void(*fp)(node_t *root)){
    if(node->left != NULL){
        (*fp)(node);
        visit_tree(node->left,fp);
    }
    else if(node->right != NULL){
        (*fp)(node);
        visit_tree(node->right,fp);
    }
    else {
        (fp)(node);
    }

}


void destroy_node(node_t *node){
    free(node->key);
    free(node->data);
}

void destroy_tree(node_t *node, void (*fdestroy)(node_t *root)){
    node_t *lptr = node->left;
    node_t *rptr = node->right;
    if(lptr != NULL){
        destroy_tree(lptr,fdestroy);
    }
    else if(rptr != NULL){
        destroy_tree(rptr,fdestroy);
    }
    else{
        (*fdestroy)(node);
    }

}




