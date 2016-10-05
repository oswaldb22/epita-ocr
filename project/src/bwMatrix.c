/*
	TODO : Insert fancy header
*/

#include "bwMatrix.h"

bwMatrix bwMatrix_new(ulong witdh, ulong height) {
	bwMatrix res;
	res.width = witdh;
	res.height = height;

	res.matrix = malloc(witdh * sizeof(bool*));
	for (int i = 0; i < witdh; i++)
		res.matrix[i] = malloc(height * sizeof(bool));

	for (size_t i = 0; i < test.width; i++)
		for (size_t j = 0; j < test.height; j++)
			res.matrix[i][j] = 0;

	return res;
}

bool bwMatrix_GetVal(bwMatrix mat, ulong w, ulong h) {
	if (mat.width <= w || mat.height <= h)
		return -1;
	return mat.matrix[w][h];
}

void bwMatrix_SetVal(bwMatrix mat, ulong w, ulong h, bool value) {
	if (mat.width <= w || mat.height <= h)
		return -1;
	mat.matrix[w][h] = value;
}
