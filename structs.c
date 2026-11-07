

#include <stdio.h>
#include <stdlib.h>

struct Jugador{
 	char *nombre; 
	int vida;
};

struct Punto{
	int x;
	int y;
};

struct Libro{
	char titulo[50];
	int paginas;
	float precio;
};

typedef struct{
	char *coso;
}librito;


void aplicar_descuento_bien(struct Libro* p);
void aplicar_descuento_mal(struct Libro p);
void imprimirPunto(struct Punto p);
void recargar_vida(struct Jugador *j);
void recibir_dano(struct Jugador *j, int daño);

int main(){


	//ejercicio 1
	struct Punto p = {1,2};
	imprimirPunto(p);


	//ejercicio 2
	struct Libro libro = {"Dragon Book", 100, 500.23};
	struct Libro copiaLibro = libro;

	aplicar_descuento_mal(copiaLibro);
	printf("precio libro %f \n ", copiaLibro.precio );
	aplicar_descuento_bien(&copiaLibro);
	printf("precio libro %f \n ", copiaLibro.precio );

	printf("precio libro original deberia ser 500.23 -> valor: %f \n ", libro.precio );

	struct Jugador j = {"skipper", 80};
	printf("vida inicial:  %d \n ", j.vida );

	recibir_dano(&j, 30);
	printf("vida:  %d \n ", j.vida );
	recibir_dano(&j, 20);
	printf("vida:  %d \n ", j.vida );
	recibir_dano(&j, 50);
	printf("vida:  %d \n ", j.vida );
	recargar_vida(&j);
	printf("vida:  %d \n ", j.vida );

	return 0;
}




//considero que se deberia pasar una copia, en este caso no necesitamos modificar las coordenadas en ningun momento
//por lo que pasar un puntero seria innecesario
void imprimirPunto(struct Punto p){
	printf("Punto X: %d  Y: %d \n", p.x, p.y);
}

void aplicar_descuento_mal(struct Libro libro){
	libro.precio /=2;
}

void aplicar_descuento_bien(struct Libro* libro){
	libro->precio /=2;
}




void recibir_dano(struct Jugador *j, int daño){

	if (daño >= j->vida){
		j->vida=0;
		return;
	}
	j->vida-=daño;
}

void recargar_vida(struct Jugador *j){
	j->vida = 100;
}
/* 

Ejercicio 4: Estructuras Compuestas (Anidadas) y Punteros Internos
Crea una estructura Fecha con los campos dia, mes y anio (enteros).
Crea una estructura Persona con los campos:
nombre (arreglo de caracteres de tamaño 30)
nacimiento (una estructura Fecha anidada)
padre (un puntero a otra estructura Persona)
En main, crea dos variables de tipo Persona: un padre y su hijo.
Inicializa la fecha de nacimiento de cada uno y vincula el puntero padre del hijo a la dirección de memoria del padre. Si el padre no tiene padre registrado, su puntero padre debe apuntar a NULL.
Escribe una función imprimir_arbol_familiar que reciba un puntero a una Persona e imprima su nombre, su fecha de nacimiento y, solo si el puntero padre no es NULL, imprima el nombre del padre accediendo mediante ->padre->nombre.




Ejercicio 5: Arreglos de Estructuras y Selección de Parámetros
Crea una estructura Estudiante con los campos id (entero), nombre (arreglo de 30 caracteres) y promedio (flotante).

En main, crea un arreglo estático de 3 estructuras Estudiante e inicialízalo con datos de prueba.

Crea una función buscar_mejor_estudiante que reciba el arreglo y su tamaño.

Toma una decisión de diseño: ¿Qué debería retornar esta función? ¿Retornar una copia de la estructura encontrada, retornar un puntero a la estructura dentro del arreglo original, o recibir un puntero de salida? Implementa la solución retornado un puntero al estudiante con mayor promedio. Si el arreglo está vacío, debe retornar NULL.

En main, usa el puntero retornado para modificar el nombre o promedio de dicho estudiante y demuestra que el cambio afectó al arreglo original.

Ejercicio 6: Constructores Simulados y Memoria Dinámica Básica
Crea una estructura Vector2D que contenga dos flotantes: x e y.

Escribe una función vector_crear que actúe como "constructor": debe recibir dos flotantes x e y, reservar memoria dinámicamente en el heap usando malloc para un Vector2D, asignar los valores y retornar el puntero a la memoria reservada.

Escribe una función vector_sumar que reciba dos punteros a Vector2D (constantes/lectura) y retorne un nuevo puntero a Vector2D con el resultado de la suma de ambos vectores.

Escribe una función vector_destruir que reciba un puntero a puntero (Vector2D **v), libere la memoria ocupada por la estructura usando free y asigne NULL al puntero original para evitar punteros colgantes (dangling pointers).

En main, crea dos vectores dinámicos, súmalos, imprime el resultado y destruye los tres vectores usando tus funciones.
 * */



void allocarAlgo(){

	int i= 2;
	int* ptr = malloc(sizeof(i));

}
