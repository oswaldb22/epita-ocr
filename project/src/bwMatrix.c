/*
	TODO : Insert fancy header
*/

#include "bwMatrix.h"

void bwMatrixInit(bwMatrix *bwMat, const ulong w, const ulong h) {
	
	ulong i = 0, j = 0;

	bwMat->width = w;
	bwMat->height = h;

	bwMat->matrix = malloc(w * sizeof(uint*));
	for (ulong i = 0; i < w; i++)
		bwMat->matrix[i] = malloc(h * sizeof(uint));

	for (i = 0; i < w; i++)
		for (j = 0; j < h; j++)
			bwMat->matrix[i][j] = 0;
}

void bwMatrixFree(bwMatrix *bwMat) {
	bwMat->width = 0;
	bwMat->height = 0;
	free(bwMat->matrix);
}

uint bwMatrixGetValue(const bwMatrix *bwMat, const ulong w, const ulong h) {
	assert(w < bwMat->width || h < bwMat->height);
	return bwMat->matrix[h][w];
}

void bwMatrixSetValue(const bwMatrix *bwMat, const ulong w, const ulong h, const uint newvalue) {
	assert(w < bwMat->width || h < bwMat->height);
	bwMat->matrix[h][w] = newvalue;
}
