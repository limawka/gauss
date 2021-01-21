#include <stdlib.h>
#include <math.h>

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
	double max=0, t;
	int max_r;

	expandMatrix(mat, b);	// rozszerzamy macierz A o b

	//printToScreen(mat);

	int n = mat->r;

	for(i = 0; i < n; i++){
		// szukanie elementu glownego
		j = i;
		while(j < n){
			if(fabs(mat->data[j][i]) > max){
				max = fabs(mat->data[j][i]);
				max_r = j;
			}
			j++;
		}
		
		// jezeli nie ma elementu innego niz 0, bedzie on na przekatnej - macierz osobliwa
		if(max==0) return 1;

		// zamiana wierszy
		for(j = i; j < n+1; j++)
		{
			t = mat->data[i][j];
			mat->data[i][j] = mat->data[max_r][j];
			mat->data[max_r][j] = t;
		}

		// eliminacja gaussa
		for( j = i+1; j < n; j++ )
		{
			m = mat->data [ j ][ i ] / mat->data [ i ][ i ];
			for( k = i ; k <= n; k++ )
				mat->data [ j ][ k ] -= m * mat->data [ i ][ k ];
		}
		max = 0;
	}

	if( mat->data[n-1][n-1] == 0 ) 
		return 1;

	//printToScreen(mat);

	return 0;
}

