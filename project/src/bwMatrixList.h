#include "includes.h"
#include "bwMatrix.h"

#ifndef BWMATRIXLIST
#define BWMATRIXLIST

typedef struct
{
	ulong size;		//Size of the array
	bwMatrix *list;	//Array containing multiple bwMatrix
} bwMatrixList;

/* Prototypes */

void bwMatrixListInit(bwMatrixList *bwMList);
void bwMatrixListFree(bwMatrixList *bwMList);
void bwMatrixListAdd(bwMatrixList *bwMList, const bwMatrix bwM_in);
void bwMatrixListDebugPrint(bwMatrixList *bwMList);

#endif