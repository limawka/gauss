#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;
	int * q;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);
	printToScreen(b);
	q = malloc(A->c*sizeof(int));
	
	res = eliminate(A,b,q);

	if(res == 1){
		printf("Macierz osobliwa\n");
		return 1;
	}else if(res == 2){
		printf("Zly rozmiar macierzy A - nie jest kwadratowa!\n");
		return 2;
	}
	x = createMatrix(b->r, 1);

	if (x != NULL) {
		res = backsubst(x,A,q);

		printToScreen(x);
	  freeMatrix(x);
	} else {
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
