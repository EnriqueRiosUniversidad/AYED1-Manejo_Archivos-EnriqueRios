#include <stdio.h>
#include <stdlib.h> //Manejo de memoria dinamica

void main() {
	int numero_1, * array_1, * array_2;

	numero_1 = 4;
	array_1 = (int*)malloc(2 * sizeof(int));

	array_1[0] = numero_1;
	array_1[1] = 5;

	array_2 = (int*)calloc(2, sizeof(int));
	array_2[0] = 6;
	array_2[1] = 7;

	array_1 = (int*)realloc(array_1, 4 * sizeof(int));

	array_1[2] = array_2[0];
	array_1[3] = array_2[1];

	free(array_2);

	for (int n = 0; n < 4; ++n) {
		printf("%d", array_1[n]);
		printf("\n");
	
	}
	free(array_1); 
}