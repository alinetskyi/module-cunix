#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_puts(const char *s){
   for(;*s != 0; s++){
     write(1,s,1);
   }
   write(1,"\n",1);
}



/*int main(){
  my_puts("sawe");
  my_puts("Nine people can't make a baby in a month.\n");
  my_puts("There are only two hard things in Computer Science: cache invalidation and naming things.");
  puts("");
  my_puts("Measuring programming progress by lines of code is like measuring aircraft building progress by weight.");
  my_puts("*********************************************************************************");




}*/
