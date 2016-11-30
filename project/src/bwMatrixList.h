#include "includes.h"
#include "bwMatrix.h"

#ifndef BWMATRIXLIST
#define BWMATRIXLIST

typedef struct bwMatrixList
{
	ulong size;
	bwMatrix *data;		//Array containing multiple bwMatrix
	struct bwMatrixList *next;	//Next element of the list
} bwMatrixList;

/* Prototypes */

void bwMatrixListInit(bwMatrixList *bwML);
void bwMatrixListFree(bwMatrixList *bwML);
void bwMatrixListPush(bwMatrixList *bwML, bwMatrixList *elm);
bwMatrixList *bwMatrixListPop(bwMatrixList *bwML);
bwMatrixList *bwMatrixListGet(bwMatrixList *bwML, int i);

/*
void bwMatrixListInit(bwMatrixList *bwML);
void bwMatrixListFree(bwMatrixList *bwML);
void bwMatrixListAdd(bwMatrixList *bwML, const bwMatrix bwM_in);
void bwMatrixListDebugPrint(bwMatrixList *bwML);
*/

#endif