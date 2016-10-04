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
	unsigned long width;	//width of the matrix
	unsigned long height;	//height of the matrix
	int **matrix;			//matrix
} bwMatrix;

#endif