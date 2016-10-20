/*
	TODO : Insert fancy header
*/

#include "bwMatrix.h"

void bwMatrixInit(bwMatrix *bwMat, const ulong w, const ulong h) {

	bwMat->width = w;
	bwMat->height = h;

	bwMat->matrix = (uint*)malloc(w * h * sizeof(uint));
	if (bwMat->matrix == NULL)
	{
		printf("Memory allocation failed");
		return;
	}
	ulong i = 0;
	for (i = 0; i < w * h; ++i)
		bwMat->matrix[i] = 0;
}

void bwMatrixFree(bwMatrix *bwMat) {
	bwMat->width = 0;
	bwMat->height = 0;
	free(bwMat->matrix);
}

uint bwMatrixGetValue(const bwMatrix *bwMat, const ulong w, const ulong h) {
	assert(w < bwMat->width || h < bwMat->height);
	return bwMat->matrix[w * bwMat->width + h];
}

void bwMatrixSetValue(bwMatrix *bwMat, const ulong w, const ulong h, const uint newvalue) {
	assert(w < bwMat->width || h < bwMat->height);
	bwMat->matrix[w * bwMat->width + h] = newvalue;
}

void bwMatrixPrintCompact(const bwMatrix *bwM, PrintMode printMode) {
	printf("\n");
	for (ulong h = 0; h < bwM->height; h++)
	{
		for (ulong w = 0; w < bwM->width; w++)
		{
			uint val = bwMatrixGetValue(bwM, w, h);
			if (printMode == Simple)
				printf("%d", val);
			if (printMode == Advanced) {
				if (val == 0)
					printf("░");
				else
					printf("█");
			}

		}
		printf("\n");
	}
	printf("\n");
}




void load_bwM(bwMatrix *bwM, SDL_Surface* img) {


	for (ulong i = 0; i < bwM->width; i++)
	{
		for (ulong j = 0; j < bwM->height; j++)
		{
			Uint32 pixel = getpixel(img, i, j);
			Uint8 r = 0;
			Uint8 g = 0;
			Uint8 b = 0;
			SDL_GetRGB(pixel, img->format, &r, &g, &b);

			float res = (float)r * 0.3 + (float)b * 0.11 + (float)g * 0.59;
			if (res < 128)
				res = 0;
			else
				res = 1;

			bwMatrixSetValue(bwM, i, j, (uint)res);

		}
	}

}


void bwMprint(bwMatrix *bwM) {

	for (ulong i = 0; i < bwM->width; i++)
	{
		for (ulong j = 0; j < bwM->height; j++)
		{
			printf("%d", bwMatrixGetValue(bwM, i, j));

		}
		printf("\n");
	}

}



















