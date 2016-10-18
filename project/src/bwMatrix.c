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

void bwMatrixSetValue(bwMatrix *bwMat, const ulong w, const ulong h, const uint newvalue) {
	assert(w < bwMat->width || h < bwMat->height);
	bwMat->matrix[h][w] = newvalue;
}




void load_bwM(bwMatrix *bwM,SDL_Surface* img){
	

  for (ulong i = 0; i < bwM->width; i++)
  {
    for (ulong j = 0; j < bwM->height; j++)
    {
      Uint32 pixel = getpixel(img,i,j);
      Uint8 r = 0;
      Uint8 g = 0;
      Uint8 b = 0;
      SDL_GetRGB(pixel, img->format, &r, &g, &b);

      float res = (float)r * 0.3 +(float)b * 0.11 +(float)g * 0.59;
      if (res < 128)
      	res = 0;
      else 
         res = 1;
	
      bwM->matrix[j][i] = (uint)res;

     }
  }	
	
}


void bwMprint(bwMatrix *bwM){

for (ulong i = 0; i < bwM->width; i++)
  {
    for (ulong j = 0; j < bwM->height; j++)
    {
      printf("%d",bwM->matrix[j][i]);

    }
      printf("\n");
  }	

}


















/*/

	***** OLD CODE (OBJECT-ORIENTED) *****

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
	assert(w < mat.width || h < mat.height);
	return mat.matrix[w][h];
}


void bwMatrix_SetVal(bwMatrix *mat, ulong w, ulong h, uint value) {
	assert(w < mat->width || h < mat->height);
	mat->matrix[w][h] = value;
}

//*/
