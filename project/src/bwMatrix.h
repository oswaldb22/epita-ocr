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

#ifndef BWMATRIX
#define BWMATRIX

/* Structure defining an array supposed to contain 0 and 1 only */
typedef struct
{
	ulong width;	//width of the matrix
	ulong height;	//height of the matrix
	uint **matrix;  //matrix
} bwMatrix;

/* Prototypes */

void bwMatrixInit(bwMatrix *bwMat, const ulong w, const ulong h);
void bwMatrixFree(bwMatrix *bwMat);
uint bwMatrixGetValue(const bwMatrix *bwMat, const ulong w, const ulong h);
void bwMatrixSetValue(const bwMatrix *bwMat, const ulong w, const ulong h, const uint newvalue);

#endif
