#include <stdio.h>
#include <stdlib.h>

//calculate number of digits 
int numOfDigits(int nmb){
	int count = 0;
	while (nmb/10 >= 1){
		count++;
		nmb = nmb/10;
	}
	 return ++count;
}


char* my_itoa(int nmb){

	
	int digit_count = numOfDigits(nmb);
	int count = digit_count - 1;
	char* result;
	result = malloc(digit_count);
	
	//Handle case with nmb = 0
	if (nmb == 0){
		result[0] = '0';
		return result;
	}
		
	for(int i= digit_count; i>0;i--){
		int rem = nmb % 10;
		result[count] = (char)(rem+48);
		//printf("rescount: %c\n", result[count]);
		//printf("rem: %d\n",rem);
		nmb = (nmb - rem)/10;
		count--;
	}
	//printf("res: %s\n",result);
	return result;
}




/*

int main(){

printf("res: %s\n",my_itoa(0));
my_itoa(11);
my_itoa(3);


}
*/
