#include <stdio.h>
#include <stdlib.h>

//calculate number of digits

//fill creates the char sequence of an int num
char  *fill(int num, char *result, int sign, int k) {
  result[k] = '\0';
  if (num == 0) {
    result[0] = '0';
  }
  if (sign == 1) {
    sign = 0;
    result[0] = '-';
    result[--k] = (char)((num % 10) + '0');
    num /= 10;
  }
  while (num > 0) {
    result[--k] = (char)((num % 10) + '0');
    num /= 10;
  }
  return (result);
}


char  *my_itoa(int num) {
  int   sign = 0;
  char  *result;
  int    i = 0; 
  int    k = 0; //number of chars 

  if (num < 0) {
    sign = 1;
    num *= -1;
    k++;
  }
  i = num;
  if (i == 0) {
    k++;
  }
  while (i > 0) {
    i /= 10;
    k++;
  }
  if (!(result = (char*)malloc(sizeof(char) * (k + 1))))
    return (NULL);
  return (fill(num, result, sign, k));
}

/*int main() {
  printf("%s\n", my_itoa(-2147483648));
  printf("%s\n", my_itoa(-2147483647));
  printf("%s\n", my_itoa(-22));
  printf("%s\n", my_itoa(-1));
  printf("%s\n", my_itoa(1));
  printf("%s\n", my_itoa(2131231));
  printf("%s\n", my_itoa(12));
  printf("%s\n", my_itoa(0));
}*/
