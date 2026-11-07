/* NOTE: 
 * 2 Stages of the code: 
 * - Preprocessor: takes all the stuff with #  
 * - Compiler: Does code lexing, creates an IR, uses a backend to generate final code (machine code, assembly etvcccc)
 * */




//NOTE: stdio refers to a HEADER file that contains some methods, constants, macros definitions that we are going to use
//NOTE: stdio -> Standard IO: so it will be IO operations like printing, opening a file, writing to a file, reading, etc
#include <stdio.h>
#include <string.h>



void duplicar(int *start, int *end);
void reemplazar(int **p, int valor);

void imprmirArr(int* arr, int size);



void morestuff(){

	char stringArr[] = "hola";
	int size_of_char = 1;
	
	char *stringNormal = "123456";
	int size_of_pointer= 8;
	
	
	//Aca impimiria en el stingArr, seria igual a: 
	printf("sizeOf array: %zu , charPointer: %zu \n", sizeof(stringArr), sizeof(stringNormal));

	//Because of null terminatorrr	
	if (sizeof(stringArr) == 4*size_of_char+1){
		printf("estoy en lo correcto en sizeOf del string  \n");
	}else{
		printf("failed check del size del string arr \n");
	}
	

	if (sizeof(stringNormal) == 8){
		printf("estoy en lo correcto en sizeOf del char star es 8 porque un puntero tiene 8 bytes\n");
	}else{
		printf("failed check string de *char\n");
	}



	printf("string length func: %zu \n", strlen(stringNormal));

	if (strlen(stringNormal) == 6){
		printf("el size es 6 e ignoramos el null terimnator\n");
	}else{
		printf("FAILED check the strln\n");
	}
}



void changeStringPosibility();
void pointersStuff();

void swap(int *a, int *b);
void actualizar(int *p, int incremento);
void ejercicio5();

int main(void){

	// int arr[]= {1,2,3,4};

	// int *start = arr;

	// printf("ptr start %p: ", start);
	// start++;
	// printf("ptr start ahora %p: ", start);
	ejercicio5();


	return 0;
}




void changeStringPosibility(){

int i= 3;
printf("pointer to normal i: %p", &i);

i=343;
printf("pointer to updated i: %p", &i);
}






void pointersStuff(){

	int numerito=10;
	//contiene la direcion de memoria de numerito
	int *ptr= &numerito;
	

	//contiene la direccion de memoria del Pointer, que apunta a numerito. 
	int **pptr= &ptr;


	//Como impimo numerito? 
	//Desreferencio DOS veces el pptr. 
	//1. Desreferenciar al pptr nos daria que? el valor del pointer, pero el pointer no tiene ningun valor no? 
	//
	//imprime la direccion de numerito
	printf("valor de ptr: %p \n",ptr);

	//imprime la direccion del pointer a numerito
	printf("Valor normal de doble %p \n", pptr);



	//esto imprimiria la direccion de numerito, porque es el valor del pointer
	printf("desrefernciamos el doble: %p \n", *pptr);


	char *string= ptr==*pptr ? "iguales": "no iguales";


	printf("%s ", string);



}



/* Crea un puntero pa que apunte a a y otro pb que apunte a b.
Modifica a para que valga 100, utilizando pa y sin escribir a = 100.
Modifica b para que valga a + b, utilizando los punteros para acceder a ambos valores.
Intercambia los valores de a y b utilizando los punteros y una variable temporal.*/

void ejercicio1(){


int a = 10;
int b = 25;

    // Tu código aquí
int *ptra = &a;
int *ptrb = &b;


*ptra=100;
*ptrb= *ptrb+*ptra;


int tmp = *ptra;

*ptra= *ptrb;
*ptrb= tmp;



    printf("a = %d\n", a);
    printf("b = %d\n", b);
}

// a = 125
// b = 100




//pointer to an integer, which will be the array first element
void ejercicio2(){
	int arr[] = {5, 10, 15, 20, 25, 30};
	int *p = &arr[1];

	printf("p: %d \n", *p);
	
	int secondElement = *(arr+1);
	printf("p: %d \n", secondElement);

	//un puntero, y avanzamos 4 bytes del tamaño del int no? 
	int secondElementUsingP= *p;
	printf("segundo lelmento usando P: %d \n", secondElementUsingP);


	// 3
	p+=2;
	*p = 99;


	//4
	p--;
	*p = *p * 2;

	
	//5
	int *index5ptr= &arr[5];
	//para caclular pued hacer una resta de punteos, sabiedno eu estan en el mismo array no?
	printf("separan %lld elementos \n", index5ptr - p);

	//6
	int lenght= sizeof(arr) / sizeof(int);


	printf("{ ");
	int *firstValPtr = arr;

	for (int i=0; i<lenght; i++){
		//acceder al primer elemento del array usando solo pointers?
		printf("%d, ", *(firstValPtr+i));
	}

	printf("} ");
	



}
/* 
Objetivos:
1. Imprime el valor al que apunta p.
2. Imprime el segundo elemento del array accediendo únicamente mediante p y aritmética de punteros.
3. Avanza el puntero dos posiciones y modifica el valor al que apunta para que sea 99.
4. Retrocede una posición y multiplica el valor apuntado por 2.
5. Calcula cuántos elementos separan p de &arr[5], sin restar los valores almacenados.
6. Imprime todos los elementos del array utilizando aritmética de punteros, sin usar arr[i]. */









void ejercicio3(){
	int x = 7;
	int y = 12;
	
	swap(&x, &y);
	actualizar(&x, 5);
	actualizar(&y, -2);

	
	printf("x: %d", x);
	printf("y: %d", y);


}

void swap(int *a, int*b){
	int tmpVal = *a;
	*a = *b;
	*b = tmpVal;
}

void actualizar(int *p, int incremento){
	*p += incremento;
}
// void swap(int *a, int *b);
// void actualizar(int *p, int incremento);
/* 
 * Objetivos:
1. Implementa swap para intercambiar los valores de dos variables.
2. Implementa actualizar para sumar incremento al entero apuntado por p.
3. Desde main, utiliza las funciones con estas variables:*/


//Pregunta conceptual: ¿por qué la función necesita recibir &x en lugar de simplemente x si queremos modificar la variable original?
////las funciones reicben &x porque X es una variable de tipo Int. Para poder hacer un swap del valor de x y y en la funcoin, neceistamos pasar la direccion de memoria, y apra acceder a esa direccion debemos pasar el operador &x, que es un puntero a la direccion de memoria y NO el valor de x. 
///Luego en actualizar, debemos pasar un puntero, porque si no pasamos un puntero sino el mismo int, si imprmirmos el valor de por ejmeplo x, o y despues de ejecutar la funcion. Si imprimimos en main, el valor interno no se actualizaria. Pues habriamos pasado una copia que se guarda en el stack. LA copia si valdira x+incremeno, pero la varibale X definida afuera, sigue siendo X, mientras que si imprimoms esa varibale dentro de la funcion si seria X + incremneto. 
///Si pasamos el puntero, modificamos el valor de X. y no el de una variable distinta.
///









void ejercicio4(){
int a = 10;
int b = 20;

int *p = &a;
int **pp = &p;


printf("a: %d \n", *p);
printf("a: %d \n", **pp);

**pp = 50;
*pp = &b;
**pp = 99;

printf("a: %d \n", a);
printf("b: %d \n", b);
printf("b por p: %d \n", *p);
printf("b por pp: %d \n", **pp);
}


/*Objetivos:
1. Imprime a, usando p.
2. Imprime a, usando pp y dos desreferenciaciones.
3. Cambia el valor de a a 50, utilizando pp.
4. Haz que p apunte a b, modificando p a través de pp.
5. Cambia el valor de b a 99, utilizando únicamente pp en la expresión de asignación.
6. Imprime a, b, p y *pp para comprobar qué ha cambiado.
Resultado final esperado:
a = 50
b = 99
*p = 99


Pregunta conceptual: después de hacer que p apunte a b, ¿qué valor tiene *pp? ¿Y qué valor tiene **pp? 
//RTA: el valor de *pp es igual a la direccion ed memoria de B, y el valor de **pp es el valor integer de B
 */





void ejercicio5(){

  int arr[] = {8, 3, 12, 5, 20, 7};
    int *start = arr;
    int *end = arr + 6;


       int length = sizeof(arr) / sizeof(int);
      
      
      int maxVal=0;
      int acummulate= 0;
      
      printf("inicio: {");
      for (int i=0; i<length; i++){
      
          int currVal = *(start + i);
      
          printf("%d, ", currVal);
          
          if (currVal > maxVal){
          	maxVal= currVal;
          }
          
          acummulate+=currVal;
      }
      
      printf("}\n");

      printf("maxVal %d \n", maxVal);
      printf("sum of all:  %d \n", acummulate);

	duplicar(start, end);
	printf("\n----duplicaDO----- \n");
	imprmirArr(arr, length);

	printf("\n----remplazaDO----- \n");
	int *ptr = arr + 3;
	reemplazar(&ptr, 100);
	imprmirArr(arr, length);
}

void duplicar(int *start, int *end){

   	int *current = start;
	while (current!= end) {
		*current*=2;
		current++;
	}

}


//porque en reemplazar no pasamos simplemnete arr +3 ? 
void reemplazar(int **p, int valor){
	**p = valor;
}


void imprimirArrLimits(int* start, int* end){
   printf("{");

   int i=0;
   int *current = start;
   while (current!=end) {
         printf("%d, ", *(current+i));
	 i++;
   }
   printf("}\n");

}


void imprmirArr(int* start, int size){
   printf("{");
   int *current = start;
   for (int i=0; i<size; i++){
         printf("%d, ", *(current+i));
   }
   printf("}\n");

}
/*
 *
 *Recorre el array desde start hasta end, utilizando únicamente aritmética de punteros. Imprime todos sus valores.
Calcula la suma de todos los elementos sin utilizar índices.
Encuentra el valor máximo recorriendo el array con punteros.
Escribe una función void duplicar(int *start, int *end) que multiplique cada elemento por 2. Usa end como límite exclusivo.
Escribe una función void reemplazar(int **p, int valor) que modifique el entero al que apunta el puntero recibido, asignándole valor.
Desde main, crea un puntero que apunte al cuarto elemento del array y utiliza la función reemplazar para cambiarlo a 100, pasando la dirección de ese puntero.
Imprime el array final.
 * */

/* PREGUNTAS 
 * ¿Por qué end es arr + 6 y no arr + 5? RTA: seria para poder comparar el pointer actual, cno el siguiente para recorrer el loop, si usamos pointers y no usamos ningun sizeof calculation, entonces no sabemos cuando deternos, y si el arr + 5 es el end, entonces la unica forma de detener un loop recorriendo el array seria comparando si el pointer actual es igual a arr5, y quedaria mas complicado, nuestro exit point sabriamos mas facilmente que es arr + size  (no estoy seguro de la respuesta)
¿Por qué end - start da 6 y no el número de bytes? Rta porque al restar dos pointers, nos da la separacion o la cuenta entre estos dos en forma de indices, y no restando el tipo de dato*posicion.  esto ocuriria si ambos pointers pertenecen al mismo array
¿Qué diferencia hay entre *p = valor y p = &arr[3]? RTA: no estoy seguro a que equivale valor, pero *p = valor, seria desrefernciar el pointer p y asignarle un valor especifico, si valor fuera 100, etnonces la variable a la que apunta p, se convierte en 100, mientras que p= &arr[3], lo que haria es actualizar la direccion de memoria de p, pues p es un puntero, y ahora apuntaria al indice 3 del array. Asuminedo que ese valor es por ejemplo 50, entonces si intentamos hacer iun print del *p despues de haberle hehco ese p = &arr[3] entonces el valor seria 50 
En reemplazar(&p, 100), ¿por qué necesitamos int **p como parámetro? RTA: aca no estoy seguro, pues aca podriamos facilmente usar como parametro simelpmente un int* ptr, valor), y pasamos p, en vez de pasar un pointer a p. pero no estoy seguro. Pero por el caso actual, necesitamos int **p, porqeu stamos pasando la direcicon de memoria de p como &p, entonces eso es pointer que apunta a un pointer p. 
* */

