/*
TODO : Insert fancy header
*/

#include "bwMatrixList.h"

void bwMatrixListInit(bwMatrixList *bwMList) {
	bwMList->size = 0;
	bwMList->list = malloc(0);
}

void bwMatrixListFree(bwMatrixList *bwMList) {
	bwMList->size = 0;
	free(bwMList->list);
}

void bwMatrixListAdd(bwMatrixList *bwMList, const bwMatrix bwM_in) {
	++bwMList->size;
	ulong previousSize = 0;
	for (ulong i = 0; i < bwMList->size; ++i) {
		previousSize += sizeof(bwMList->list[i]) + sizeof(bwMList->list[i].matrix);
	}

	bwMatrix* reallocated = realloc(bwMList->list, previousSize + (sizeof(bwMatrix) + sizeof(bwM_in.matrix)));
	if (reallocated) {
		bwMList->list = reallocated;
		bwMList->list[bwMList->size - 1] = bwM_in;
	}
	else {
		printf("***ERROR*** : Realloc failing because memory could not be allocated.");
	}
}

void bwMatrixListDebugPrint(bwMatrixList *bwMList) {
	for (ulong i = 0; i < bwMList->size; ++i) {
		bwMatrixPrintCompact(&bwMList->list[i], Advanced);
	}
}