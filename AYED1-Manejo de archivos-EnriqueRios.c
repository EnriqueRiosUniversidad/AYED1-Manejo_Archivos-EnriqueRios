#include <stdio.h>
#include <stdlib.h> //Manejo de memoria dinamica
/*
	Este es un algoritmo que reserva espacio en heap para 2 arrays de tamaño (2)*(int)
	Les asigna valores y 
	crea una variable local Numero_1 para asignarle un valor y guardarlo en array_1
	luego agrande el array_1 
	para unir tando array_1 con los valores del array_2
	libera el array_2 y por ultimo el array_1

	Todos los pasos son guardados en un archivo: proceso.txt
*/

FILE* fptr; //

void main() {
	
	errno_t err = fopen_s(&fptr, "Procesos.txt", "w");
	
	if (err != 0)
	{
		printf("Algun error molesto.\n");
	}
	fprintf_s(fptr, "\n--Crea la variable global fptr que es un puntero de tipo FILE");
	fprintf_s(fptr, "\n--Crea una variable en stack <err> tipo <errno_t>, asigna el archivo Provesos.txt en modo <w>");
	fprintf_s(fptr, "\n--Comprueba si ha ocurrido un error en <err>");


	fprintf_s(fptr, "\n--Guardando en stack una variable integer y dos punteros integer. (numero_1, array_1, array_2)");
	int numero_1, * array_1, * array_2; 

	fprintf_s(fptr, "\n--Se carga en el stack el valor 4 y este se asigna a la varibale numero_1");
	numero_1 = 4; 

	fprintf_s(fptr, "\n--Se reserva espacio en el heap, del tamaño de 2 numeros enteros (array_1)");
	array_1 = (int*)malloc(2 * sizeof(int));

	fprintf_s(fptr, "\n--Se carga el valor de numero_1 en el heap  (array + 0)");
	array_1[0] = numero_1;

	fprintf_s(fptr, "\n--Se carga el valor 5 en el heap (array_1 + 1)");
	array_1[1] = 5; 

	fprintf_s(fptr, "\n--Se reserva espacio en el heap, del tamaño de 2 numeros enteros (array_2)");
	array_2 = (int*)calloc(2, sizeof(int));
	fprintf_s(fptr, "\n--Se carga el valor 6 en el heap  (array + 0)");
	array_2[0] = 6;
	fprintf_s(fptr, "\n--Se carga el valor 7 en el heap  (array + 1)");
	array_2[1] = 7;

	fprintf_s(fptr, "\n--Se redimenciona el espacio reservado para array_1, ahora abarca 4 enteros");
	array_1 = (int*)realloc(array_1, 4 * sizeof(int)); 
	fprintf_s(fptr, "\n--copiamos valores en (array_2 + 0) y (array_2 + 1) en posiciones (array_1 + 2) y (array_1 + 3)");
	array_1[2] = array_2[0];
	array_1[3] = array_2[1];

	fprintf_s(fptr, "\n--Liberamos espacio reservado en heap (array_2)");
	free(array_2); // liberamos el espacio reservado para array_2

	for (int n = 0; n < 4; ++n) {
		printf("%d", array_1[n]);
		printf("\n");
	
	}
	fprintf_s(fptr, "\n--Liberamos espacio reservado en heap (array_1)");
	free(array_1); //Liberamos el espacio reservado para array_1

	

	


	err = fclose(fptr);


}