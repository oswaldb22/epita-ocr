#include "includes.h"
#include "bwMatrix.h"

#ifndef BWMATRIXLIST
#define BWMATRIXLIST

typedef struct bwMatrixList
{
	ulong size;		//Size of the array
	bwMatrix *list;	//Array containing multiple bwMatrix
} bwMatrixList;

/* Prototypes */

void bwMatrixListInit(bwMatrixList *bwML);
void bwMatrixListFree(bwMatrixList *bwML);
void bwMatrixListAdd(bwMatrixList *bwML, const bwMatrix bwM_in);
void bwMatrixListDebugPrint(bwMatrixList *bwML);

#endif