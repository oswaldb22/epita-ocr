/*
	TODO : Insert fancy header
*/

#include "bwMatrix.h"

bwMatrix* bwMatrixNew(ULONG w, ULONG h) {
	bwMatrix* bwM = malloc(sizeof(bwMatrix));
	bwM->width = w;
	bwM->height = h;

	bwM->matrix = malloc(w * h * sizeof(uint));
	if (bwM->matrix == NULL)
	{
		printf("Memory allocation failed");
		return NULL;
	}

	for (ulong i = 0; i < w * h; ++i)
		bwM->matrix[i] = 0;

	return bwM;
}

void bwMatrixInit(bwMatrix *bwM, ULONG w, ULONG h) {

	bwM->width = w;
	bwM->height = h;

	bwM->matrix = (uint*)malloc(w * h * sizeof(uint));
	if (bwM->matrix == NULL)
	{
		printf("Memory allocation failed");
		return;
	}

	for (ulong i = 0; i < w * h; ++i)
		bwM->matrix[i] = 0;
}

void bwMatrixFree(bwMatrix *bwM) {
	bwM->width = 0;
	bwM->height = 0;
	free(bwM->matrix);
}

uint bwMatrixGetValue(const bwMatrix *bwM, ULONG w, ULONG h) {
	assert(w < bwM->width || h < bwM->height);
	return bwM->matrix[(h * bwM->width) + w];
}

void bwMatrixSetValue(bwMatrix *bwM, ULONG w, ULONG h, UINT val) {
	assert(w < bwM->width || h < bwM->height);
	bwM->matrix[(h * bwM->width) + w] = val;
}

void bwMatrixPrintCompact(const bwMatrix *bwM, PrintMode mode) {
	printf("\n");
	for (ulong h = 0; h < bwM->height; ++h)
	{
		for (ulong w = 0; w < bwM->width; ++w)
		{
			uint val = bwMatrixGetValue(bwM, w, h);
			if (mode == Simple)
				printf("%d", val);
			if (mode == Advanced) {
				switch (val) {
				case 0:
					printf("░");
					break;
				case 1:
					printf("█");
					break;
				default:
					printf("X");
					break;
				}
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
				res = 1;
			else
				res = 0;

			bwMatrixSetValue(bwM, i, j, (uint)res);

		}
	}

}

/*Resize the matrix with size*/

bwMatrix* bwMatrixResize(bwMatrix *bwM,ulong size) {
	/*BETTER IMPLEMENTATION*/
	assert(size>0);
	ulong Xratio=bwM->width/size;
	ulong Yratio=bwM->height/size;

	bwMatrix *new=bwMatrixNew(size,size);

	ulong px,py;

	for(ulong i=0;i<size;i++){
		for (ulong j = 0;j<size; j++) {
			px=j*Xratio;
			py=i*Yratio;
			bwMatrixSetValue(new,j,i,bwMatrixGetValue(bwM,(int)px,(int)py));
		}
	}

return new;
}
