#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
void expandMatrix(Matrix *mat, Matrix *b){
	int i;
	(mat->c)++;
	for(i = 0; i < mat->r; i++){
		mat->data[i] = (double*) realloc(mat->data[i], sizeof(double) * mat->c);
		mat->data[i][mat->c-1] = b->data[i][0];
	}
}

int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
	*/
	double m;
	int i, j, k;

	expandMatrix(mat, b);	//rozszerzamy macierz A o b

	printToScreen(mat);

	int n = mat->r;


	double* temp = malloc(mat->c * sizeof(double));
	double max=0, t;
	int max_r;
	for(i = 0; i < n; i++){
		for(j = i; j < n; j++){
			//printf("patrze na %f i %f\n",mat->data[j][i], max);
			if(fabs(mat->data[j][i]) > max){
				max = fabs(mat->data[j][i]);
				max_r = j;
			}
		}
		//printf("zamieniam %d z %d:\n", i, max_r);
		for(j = i; j < n+1; j++){
			t = mat->data[i][j];
			mat->data[i][j] = mat->data[max_r][j];
			mat->data[max_r][j] = t;
		}
		//printToScreen(mat);
		//m = -mat->data [ j ][ i ] / mat->data [ i ][ i ];
		for( j = i+1; j < n; j++ )
		{
			m = mat->data [ j ][ i ] / mat->data [ i ][ i ];
			for( k = i ; k <= n; k++ )
				mat->data [ j ][ k ] -= m * mat->data [ i ][ k ];
		}
		max = 0;
	}


	printToScreen(mat);

	return 0;
}

