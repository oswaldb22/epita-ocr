# ifndef RGBMATRIX_H_
# define RGBMATRIX_H_

/**
@file rgbMatrix.h

*/
#include "pixel_operations.h"
#include "includes.h"

typedef struct {
	int r;
	int g;
	int b;
}color;


typedef struct {

	ulong width;	//width of the matrix
	ulong height;	//height of the matrix
	color **matrix;

}rgbMatrix;

/*Color Primitive*/

void colorSetRGB(color *color, UINT r, UINT g, UINT b);
void colorGetRGB(const color *color, uint *r, uint *g, uint *b);


/*rgbMatrix Primitive*/

void rgbInit(rgbMatrix *rgbM, ULONG w, ULONG h);

void rgbFree(rgbMatrix *rgbM);


void rgbSetWidth(rgbMatrix *rgbM, ULONG w);
ulong rgbGetWidth(const rgbMatrix *rgbM);

void rgbSetHeight(rgbMatrix *rgbM, ULONG h);
ulong rgbGetHeight(const rgbMatrix *rgbM);



void rgbSetColorXY(const rgbMatrix *rgbM, ULONG w, ULONG h, const color c);
color rgbGetColorXY(const rgbMatrix *rgbM, ULONG w, ULONG h);


void load_rgbM(rgbMatrix *rgbM, SDL_Surface* img);
void rgbMprint(rgbMatrix *rgbM);

#endif
