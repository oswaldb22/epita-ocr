/*
	TODO : Insert fancy header

	setVal need to be a void !
	put some assert !
	it will return an error if the case you tryna to reach is not avaliable


	IN GETVAL ? Bool does return -1 ??


*/

#include "bwMatrix.h"

bwMatrix bwMatrix_New(ulong witdh, ulong height) {
	bwMatrix res;
	res.width = witdh;
	res.height = height;

	res.matrix = malloc(witdh * sizeof(uint*));
	for (ulong i = 0; i < witdh; i++)
		res.matrix[i] = malloc(height * sizeof(uint));

	for (ulong i = 0; i < res.width; i++)
		for (ulong j = 0; j < res.height; j++)
			res.matrix[i][j] = 0;

	return res;
}

uint bwMatrix_GetVal(const bwMatrix mat, ulong w, ulong h) {
	assert(mat.width <= w || mat.height <= h);
	return mat.matrix[w][h];
}


void bwMatrix_SetVal(bwMatrix mat, ulong w, ulong h, uint value) {
	assert(mat.width <= w || mat.height <= h);
	mat.matrix[w][h] = value;
}
