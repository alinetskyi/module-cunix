#include <stdio.h>


int my_strcmp(char *str1, char *str2){
  while(*str1 != '\0'){
      if(*str1 > *str2){
//        printf("first bigger");
        return 1;
      }
      else if (*str2 > *str1){
//          printf("second bigger");
          return -1;
      }
      str1++;
      str2++;
  }
//  printf("same");
  return 0;


}

/*int main (){

  my_strcmp("AB","AB");
}
*/

