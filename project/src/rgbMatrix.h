# ifndef RGBMATRIX_H_
# define RGBMATRIX_H_

/**
@file rgbMatrix.h

*/
#include "pixel_operations.h"
#include "includes.h"

typedef struct{
	int r;
	int g;
	int b;
}color;


typedef struct{ 	

	ulong width;	//width of the matrix
	ulong height;	//height of the matrix
	color **matrix; 

}rgbMatrix;

/*Color Primitive*/

void setColor(color *color,const uint r, const uint g, const uint b);



/*rgbMatrix Primitive*/

void rgbInit(rgbMatrix *rgbM,const ulong w, const ulong h);

void rgbFree(rgbMatrix *rgbM);


color rgbGetColor(const rgbMatrix *rgbM);

void rgbSetWidth(rgbMatrix *rgbM, const ulong w);
ulong rgbGetWidth(const rgbMatrix *rgbM);

void rgbSetHeight(rgbMatrix *rgbM,const ulong h);
ulong rgbGetHeight(const rgbMatrix *rgbM);

color rgbGetXY(const rgbMatrix *rgbM); 
void rgbSetColorXY(const rgbMatrix *rgbM,const ulong w,const ulong h,const color c); 

void load_rgbM(rgbMatrix *rgbM,SDL_Surface* img);
void rgbMprint(rgbMatrix *rgbM);

#endif
