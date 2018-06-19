#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>


char* my_itoa(int nmb);


void create_arr(int arr_size, int z_flag,char* arrptr){
	char* array =  malloc((arr_size+1) * sizeof(char*));
	int arglen = strlen(arrptr);
	int counter = 0;
	int strdiff = arr_size - arglen;
	int i = 0;

	if(z_flag != 0){
		for(i; i < arr_size;i++){
			if (counter == strdiff){
				*array = *arrptr;
				arrptr++;
			}
			else{
				*array = '0';
				counter++;
			}
			putchar(*array);
		}
	}
	else{
		for(i; i < arr_size;i++){
			if (counter == strdiff){
				*array = *arrptr;
				arrptr++;
			}
			else{
				*array = ' ';
				counter++;
			}
			putchar(*array);
		}
	}
	free(array);
}

char* check_format(char* chptr){
	for(;*chptr != '\0';chptr++){
		switch (*chptr){
			case 'd':
				return chptr;
				break;
			case 's':
				//printarr(archptr);
				return chptr;
				break;
		}
	}
}
char get_format(char* chptr){
	for(;*chptr != '\0';chptr++){
		switch (*chptr){
			case 'd':
				return 'd';
				break;
			case 's':
				//printarr(archptr);
				return 's';
				break;
		}
	}
}





int my_printf(const char *format,...){
	const char** operator;
	operator = &format;
	int zflag = 0; //Flag whether fill with zeroes or not 
	int arrsize = 0; //Size of array to create
	char pfrmt; //Argument format;

	const char* arrptr;
	va_list args;
	va_start(args, format);
	
	for(;*format != '\0';format++){
		if(*format != '%'){
			putchar(*format);
		}
		else{

			//printf("%d\n",format );
					arrptr = ++format;
				//printf("%d\n", );
				//printf("%c",*arrptr );
					if(*format == '%'){
						putchar(*format);
						//printf("%d\n",format );
					}
					else{

							format = check_format(arrptr);
							char frmt = get_format(arrptr);
							if (*arrptr == '0'){
								zflag = 1;
								arrptr++;
								arrsize = atoi(arrptr);
								//printf("%d\n", format);
								//printf("%d\n",arrsize);
								//create_arr(arrsize);
								//printf("zero flag: %d:\n",zflag);
							}
							else{
								arrsize = atoi(arrptr);		
							}
								//printf("%d\n", format);
							if(frmt == 'd'){
								//printf("%s\n",printarg);
								char* ch;
								ch = my_itoa(va_arg(args,int));
								if (arrsize == 0){
									arrsize = strlen(ch);
								}	
								create_arr(arrsize,zflag,ch);
							}
							else
							{
								char* ch = va_arg(args,char*);
								if(arrsize == 0){
									arrsize = strlen(ch);
								}
								create_arr(arrsize,zflag,ch);

							}

						zflag = 0;
							//printf("%d\n", format );
							
							
							//printf("arrsize:%d\n", arrsize);

					}
			}
			
	}

	va_end(args);

}

/*
int main(){


	//create_arr(4,0,"54");
 my_printf("%s\n", "Hello Printf");
  my_printf("We need 100%% of %s\n", "use case");
  my_printf("It's %s's %s (%s)\n", "iGor", "phone", "TEXT");
  my_printf("[%10s] [%4s] [%8s] [%12s]\n", "THIS", "IS", "PADDED", "TEXT");
  my_printf("%d\n", 42);
  my_printf("%d %s\n", 42, "is the answer");
  my_printf("%010d %s\n", 42, "was padded on 10");
  my_printf("%10d %s\n", 42, "was also padded using spaces");
 	

}
*/