#include "backsubst.h"
/**
 *  * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 *   * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 *    * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 *     */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
		
	double s;
	int n = mat->r;
	x->data[n-1][0] = mat->data[n-1][n]/mat->data[n-1][n-1];
	

	for (int i = n-2; i >= 0; i--) { 
		s = 0;
		for (int j = i+1; j < n; j++)          
		s += mat->data[i][j] * x->data[j][0];   
		if(mat->data[i][i] == 0) return 1;
		x->data[i][0] = (mat->data[i][n] - s) / mat->data[i][i]; 
	}

	return 0;
}
