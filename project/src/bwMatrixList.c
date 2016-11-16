/*
TODO : Insert fancy header
*/

#include "bwMatrixList.h"

void bwMatrixListInit(bwMatrixList *bwML) {
	bwML->size = 0;
	bwML->list = malloc(0);
}

void bwMatrixListFree(bwMatrixList *bwML) {
	bwML->size = 0;
	free(bwML->list);
}

void bwMatrixListAdd(bwMatrixList *bwML, const bwMatrix bwM_in) {
	++bwML->size;
	bwMatrix* reallocated = 
	realloc(bwML->list, bwML->size * (sizeof(bwMatrix)));
	if (reallocated) {
		bwML->list = reallocated;
		bwML->list[bwML->size - 1] = bwM_in;
	}
	else {
		printf("***ERROR*** : Realloc failed.");
	}
}

void bwMatrixListDebugPrint(bwMatrixList *bwML) {
	for (ulong i = 0; i < bwML->size; ++i) {
		bwMatrixPrintCompact(&bwML->list[i], Advanced);
	}
}