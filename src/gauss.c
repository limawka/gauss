#include <stdlib.h>
#include <math.h>

#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 * Zwraca 2 - zly rozmiar macierzy
 */
void expandMatrix(Matrix *mat, Matrix *b){
	int i;
	(mat->c)++;
	for(i = 0; i < mat->r; i++){
		mat->data[i] = (double*) realloc(mat->data[i], sizeof(double) * mat->c);
		mat->data[i][mat->c-1] = b->data[i][0];
	}
}

int eliminate(Matrix *mat, Matrix *b, int* q){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
	*/
	double m;
	int i, j, k;
	double max=0, t;
	int max_r, max_c;
	double* tp;
	if(mat->r != mat->c) return 2;
	
	expandMatrix(mat, b);	// rozszerzamy macierz A o b
	
	for(i = 0; i < mat->c; i++)	// uzupelnianie macierzy Q=[1,2,3...n]
		q[i] = i;

	//printToScreen(mat);

	int n = mat->r;
	
	for(i = 0; i < n; i++){
		// szukanie elementu glownego
		for(j = i; j < n; j++){
			for(k = i; k < n; k++){
				if(fabs(mat->data[j][k]) > max){
					max = fabs(mat->data[j][k]);
					max_r = j;
					max_c = k;
				}
			}
		}

		// jezeli nie ma elementu innego niz 0, bedzie on na przekatnej - macierz osobliwa
		if(max==0) return 1;

		// zamiana wierszy
		if(i != max_r){
			tp = mat->data[i];
			mat->data[i] = mat->data[max_r];
			mat->data[max_r] = tp;
		}

		// zamiana kolumn
		if(i != max_c){
			t = q[i];
			q[i] = q[max_c];
			q[max_c] = t;

			for(j = i; j < n; j++){
				t = mat->data[j][i];
				mat->data[j][i] = mat->data[j][max_c];
				mat->data[j][max_c] = t; 
			}
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

