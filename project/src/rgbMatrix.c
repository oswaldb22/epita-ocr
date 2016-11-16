/**
@file rgbMatrix.c
*/


#include "rgbMatrix.h"

/*
	Primitive de la structure de Color

*/

void colorSetRGB(color *color, UINT r, UINT g, UINT b) {
	color->r = r;
	color->g = g;
	color->b = b;
}


void colorGetRGB(const color *color, uint *r, uint *g, uint *b) {
	*r = color->r;
	*g = color->g;
	*b = color->b;
}


/*
matrix est initialisé par defaut a 0
taille w et h passé en paramètres
color par defaut NOIR (r,g,b=0)

*/

void rgbInit(rgbMatrix *rgbM, ULONG w, ULONG h) {
	ulong i = 0, j = 0;
	color Color;

	rgbM->width = w;
	rgbM->height = h;

	colorSetRGB(&Color, 0, 0, 0);

	rgbM->matrix = malloc(w * sizeof(color*));
	for (i = 0; i < w; i++) {
		rgbM->matrix[i] = malloc(h * sizeof(color));
	}


	for (i = 0; i < w; i++) {
		for (j = 0; j < h; j++) {
			rgbM->matrix[i][j] = Color;
		}
	}


}

void rgbFree(rgbMatrix *rgbM) {
	rgbM->width = 0;
	rgbM->height = 0;
	free(rgbM->matrix);
}


ulong rgbGetWidth(const rgbMatrix *rgbM) {
	return rgbM->width;
}

void rgbSetWidth(rgbMatrix *rgbM, ULONG w) {
	rgbM->width = w;
}




ulong rgbGetHeight(const rgbMatrix *rgbM) {
	return rgbM->height;
}

void rgbSetHeight(rgbMatrix *rgbM, ULONG h) {
	rgbM->height = h;
}




color rgbGetColorXY(const rgbMatrix *rgbM, ULONG w, ULONG h) {
	return rgbM->matrix[h][w];
}

void rgbSetColorXY(const rgbMatrix *rgbM, ULONG w,
	ULONG h, const color c) {
	rgbM->matrix[h][w] = c;
}

void rgbMprint(rgbMatrix *rgbM) {

	for (ulong j = 0; j < rgbM->height; j++)
	{
		for (ulong i = 0; i < rgbM->width; i++)
		{
			printf("r=%d,g=%d,b=%d", rgbM->matrix[j][i].r,
				rgbM->matrix[j][i].g, rgbM->matrix[j][i].b);
		}
		printf("\n");
	}

}

void load_rgbM(rgbMatrix *rgbM, SDL_Surface* img) {

	color c;
	for (ulong i = 0; i < rgbM->width; i++)
	{
		for (ulong j = 0; j < rgbM->height; j++)
		{
			Uint32 pixel = getpixel(img, i, j);
			Uint8 r = 0;
			Uint8 g = 0;
			Uint8 b = 0;
			SDL_GetRGB(pixel, img->format, &r, &g, &b);

			colorSetRGB(&c, (uint)r, (uint)g, (uint)b);
			rgbM->matrix[j][i] = c;

			/*float res = (float)r * 0.3 +(float)b * 0.11 +(float)g * 0.59;
			Uint32 grey = SDL_MapRGB(img->format, res, res, res);
		   putpixel (img, i, j, grey);*/

		}
	}

}






