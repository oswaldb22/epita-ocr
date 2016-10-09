# ifndef RGBMATRIX_H_
# define RGBMATRIX_H_

/**
@file rgbMatrix.h

*/
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


void setColor(color *color,const uint *r, const unint *g, const unit *b);

color getColor(const color *color);

 

#endif
