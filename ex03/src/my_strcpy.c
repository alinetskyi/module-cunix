#include <stdio.h>

char *my_strcpy(char *dest, const char *src){
  char *pdest = dest;
  while(*src != '\0'){
    *dest = *src;
    dest++;
    src++;
  }
 *dest++ = '\0';
  return pdest;
}



/*int main(){

char buf[32];
const char  *ptr;
ptr = "";
printf("%s",my_strcpy(buf,ptr));


}
*/

