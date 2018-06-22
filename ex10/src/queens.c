#include <stdio.h>
#include <stdlib.h>
#include "../include/queens.h"




void board_init(Cell **table,int size){
    for(int i =0;i < size;i++){
        for(int j=0; j<size;j++){
            if(table[i][j].figure == NULL){
                table[i][j].figure = 'E';
            }
        }
    }

}


void printSolution(Cell **table,int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%c", table[i][j].figure);
        printf("\n");
    }
    printf("\n");
}

int isSafe(Cell **table, int row, int col,int size)
{
    int i, j;  
    /* Check this row on left side and on the right side  */  
    for (i = 0; i < size; i++)  {
        if (table[row][i].figure == 'Q'){
            return 0;  
        }
    }
    
    for (i = 0; i < size; i++)  { 
           if (table[i][col].figure == 'Q'){
               return 0;
           }
    }
    /* Check upper diagonal on left side */  
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if (table[i][j].figure == 'Q'){
            return 0;
        }
    }
    /* Check lower diagonal on left side */  
    for (i = row, j = col; j >= 0 && i < size; i++, j--){
        if (table[i][j].figure == 'Q'){
            return 0;
        }
    }
    return 1;  
}  

void under_attack(Cell **table, int size,int row,int col){
      for(int i = 0; i < size;i++){
            table[i][col].figure = 'A';
            table[row][i].figure = 'A';
          }
   }  
   


int place_aqueen(int row,int size,Cell **table){
    if(row == size){
        return 1;
    }
    for(int col = 0; col<size;col++){
        if(isSafe(table,row,col,size) == 1){
        table[row][col].figure = 'Q';
            if(place_aqueen(row+1,size,table) == 1){
                   return 1;
            }
            table[row][col].figure = 'E'; 
        
        }
    }
    return 0;

}



void place_queens(Cell **table, int size){
    board_init(table,size);
    if(place_aqueen(1,size,table) == 0){
       // printf("No solution here...");
    }
    printSolution(table,size);
}


/*
int main(){
    
     Cell **table;
       table = malloc(8 * sizeof(Cell*));
        for (int i = 0; i < 8; i++){
          table[i] = malloc(8 * sizeof(Cell));
        }
        place_queens(table,8);
      return 0;
    
    Cell **table;

     printf("Testing %dx%d table\n", 8, 8);

     table = malloc(8 * sizeof(Cell*));
     for (int i = 0; i < 8; i++)
       table[i] = malloc(8 * sizeof(Cell));

     table[0][3].figure = 'Q';

     place_queens(table, 8);

     printf("%dx%d table is OK\n", 8 ,8);

     for (int i = 0; i < 8; i++)
       free(table[i]);
     free(table);

}
*/
