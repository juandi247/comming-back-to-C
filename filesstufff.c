
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int countAletter(char *arr, size_t arrSize);
void printBuf(char *arr, size_t arrSize);

int main(){
	//file seria un io buffer 

	FILE *f = fopen("coso.txt","r");

	if (f==NULL){
		printf("error opening file \n");
		return -1;
	}
	

	char buf[8];


	int bytesRead = 0;
	int charCount = 0;
	int aCount= 0;


	do {
		bytesRead = fread(buf, sizeof(char), sizeof(buf), f);
		printf("bytes read: %d \n", bytesRead);
		charCount += bytesRead;
	
		// if (bytesRead<sizeof(buf)) {
		// 	memset(&buf[bytesRead], EOF, sizeof(buf) - bytesRead -1);
		// }

		aCount += countAletter(buf, bytesRead);
		printBuf(buf, bytesRead);

		//asi leemos, hasta que encontremos la ultima lectura, que podria ser 5 bytes Y paramos porque sabmos que apartir de hai no hay mas.  y ya habriamos llenado el buffer con [a,a,a,a,a, 0,0,0,0,0,0 .....] con el memset
	}while (bytesRead== sizeof(buf));


	printf("size del file: %d \n", charCount);
	printf("numero de 'a': %d \n", aCount);
	fclose(f);
	return 0;
}

int countAletter(char arr[], size_t arrSize){
	int aCount = 0;

	int i=0;
	while(i<arrSize){
		if (*arr=='a'){
			aCount++;
		}
		i++;
		arr = 1+arr;
	}


	return aCount;
}

void printBuf(char *arr, size_t arrSize){

	int i=0;

	while(i<arrSize){
		i++;
		printf("%c", *arr);
		arr = 1+arr;
	}

	fflush(stdout);

}

/* 

5. Un pequeño reto para consolidarlo
Te propongo un ejercicio bastante bueno para practicar lo que acabamos de ver:

Tienes un archivo de texto de tamaño desconocido. Quieres:
1. Abrirlo.
2. Leerlo utilizando un buffer de 128 bytes.
3. Contar cuántos caracteres contiene.
4. Contar cuántas veces aparece la letra 'a'.
5. Imprimir ambos resultados.
*/
