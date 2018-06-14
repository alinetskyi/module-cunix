#include <stdio.h>
#include <math.h>
#include <string.h>
#include "test.h"
#define EOS  '\0'

int num_length(const char *nptr){
   const char *snptr = nptr;
   int num_size = 0;
   for(;*snptr != EOS;snptr++){
      if(*snptr > 47 && *snptr < 58){
      num_size++;
      }                                                                                                }
   printf("%d\n", num_size);
   return num_size; 
}

int is_negative(const char *nptr){
   const char *snptr = nptr;
   if(*snptr == '-')
     return 1;
   else  
     return 0;
   printf("first element:%d\n ",*snptr);

}

int my_atoi(const char *nptr){
   int counter;
   int isNegative = is_negative(nptr);
   int ten = 1;
   int num_size = num_length(nptr);
   int num = 0;
  for(;*nptr != EOS;nptr++){
   if(*nptr > 47 && *nptr < 58){
      counter = num_size-1;
      while (counter > 0){
          ten *= 10;
          counter--;
      }
   printf("ten: %d\n",ten);
   num += ten*(*nptr - 48);
   printf("number: %d\n",num);
   ten = 1;
   num_size--; 
  }
 }
   if (isNegative == 1){
      num = num - 2*num;
   } 

   return num;


}



//int my_atoi(const char *nptr){
  //Define variables 
  /*int ten = 1;
  int num;
  int counter;
  int num_size = num_length(nptr);
  //Find the length of the number

  for(;*nptr != EOS;nptr++){
    if(nptr[0] == '-'){
if(*nptr > 47 && *nptr < 58){
         counter = num_size-1;
         while (counter > 0){
        ten *= 10;
        counter--;
      }   
     num += ten*(*nptr - 48);
     ten = 1;
     num_size--; 
    }

    }
    if(*nptr > 47 && *nptr < 58){
    counter = num_size-1;
    while (counter > 0){
      ten *= 10;
      counter--;
    }
    num += ten*(*nptr - 48);
    ten = 1;
    num_size--; 
    }
  }
  printf("%d\n",num);
  return num;
  */
  //printf("%d\n",get_number(nptr));


//}








/*int main(){
  //my_atoi("sw543534");
  //my_atoi("-321213");
  my_atoi("03215");
  my_atoi("ABC");
 my_atoi("0");
my_atoi("1k");
my_atoi("-42"); 
}*/

