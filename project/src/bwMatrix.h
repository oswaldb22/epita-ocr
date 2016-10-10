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

//TODO : Struct header
typedef struct
{
	ulong width;	//width of the matrix
	ulong height;	//height of the matrix
	uint **matrix;  //matrix
} bwMatrix;

/* Returns a new bwMatrix of size width x height initialized at 0 */
bwMatrix bwMatrix_New(ulong witdh, ulong height);

/* Returns the value contained in given bwMatrix at position (w,h) */
uint bwMatrix_GetVal(bwMatrix mat, ulong w, ulong h);

/* Sets the content of given bwMatrix at position (w,h) to given value */
void bwMatrix_SetVal(bwMatrix *mat, ulong w, ulong h, uint value);

#endif
