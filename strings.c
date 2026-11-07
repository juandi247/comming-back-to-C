
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyAString();

char* strcpy_unsafe(char* dst, const char* src);

int main(void){
	copyAString();
	return 0;
}

void copyAString(){
	char hello[] = "Hello world";
	
	char *t;
	
	
	t = hello;
	
	
	//this modififes the exisitng HELLO
	t[0] = 'M';
	t[1] = 'S';
	
	printf("%s \n", t);



	//NOTE: THIS IS REAAALLY WRONG. It is undefined behavoir, because strcpy takes bufferdest, which has a size of 1, so the memory would becopied on th ebuffer and overflow there or do some weirddd stuff. Better use strncopy or something that takes the LENGTH
	char newString[]= "hallooo";

	char bufferDest[8];
	printf("copied: %s \n", strcpy_unsafe(bufferDest, newString));
	printf("dest: %s \n", bufferDest);




}



char* strcpy_unsafe(char* dst, const char* src){
char *start = dst;
//what does this do? Copy each value from src, to dst, until i find a src = "\0"
	while (*src!='\0') {
		*dst=*src;
		src++;
		dst++;
	}

	*dst= *src;
return start;
}
//hello\0 
// _h  _e  _l _l _  
char* strcpy_safe(char* dst, const char* src, size_t dstSize){
char *start = dst;
//recorremos todo el size, si encontramos que src se acaba, terminamos todo. 
//si sigue vamos llenando y listo. 
	for(int i=0; i<dstSize-1; i++) {
		*dst=*src;
		src++;
		dst++;
		if (*src=='\0'){
			break;
		}
	}

	*dst='\0';
return start;
}



