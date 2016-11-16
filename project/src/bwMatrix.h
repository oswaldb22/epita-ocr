/*
	bwMatrix.h

	Black&White matrix
	Structure of a matrix containing 0 and 1 only
	This is used to represent black&white images as data

	Disposition :

		w i d t h
	h
	e   0 1 0 0 1
	i   0 1 0 0 0
	g   1 1 1 1 0
	h   0 1 1 0 1
	t   1 0 0 1 1

*/

#include "includes.h"
#include "pixel_operations.h"


#ifndef BWMATRIX
#define BWMATRIX

typedef enum { Simple, Advanced } PrintMode;

/* Structure defining an array supposed to contain 0 and 1 only */
typedef struct bwMatrix
{
	ulong width;	//width of the matrix
	ulong height;	//height of the matrix
	uint *matrix;	//matrix
} bwMatrix;

/* Prototypes */
bwMatrix* bwMatrixNew(const ulong w, const ulong h);
void bwMatrixInit(bwMatrix *bwM, const ulong w, const ulong h);
void bwMatrixFree(bwMatrix *bwM);
uint bwMatrixGetValue(const bwMatrix *bwM, const ulong w, const ulong h);
void bwMatrixSetValue(	bwMatrix *bwM,
						const ulong w,
						const ulong h,
						const uint val);
void bwMatrixPrintCompact(const bwMatrix *bwM, PrintMode mode);

void load_bwM(bwMatrix *bwM, SDL_Surface* img);

#endif
