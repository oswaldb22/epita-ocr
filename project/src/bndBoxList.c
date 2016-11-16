/*
TODO : Insert fancy header
*/

#include "bndBoxList.h"

void bndBoxListInit(bndBoxList *boxList) {
	boxList->size = 0;
	boxList->list = malloc(0);
}

void bndBoxListFree(bndBoxList *boxList) {
	boxList->size = 0;
	free(boxList->list);
}

void bndBoxListAdd(bndBoxList *boxList, const bndBox box) {
	++boxList->size;
	bndBox* reallocated = realloc(boxList->list,
		boxList->size * sizeof(bndBox));
	if (reallocated) {
		boxList->list = reallocated;
		boxList->list[boxList->size - 1] = box;
	}
	else {
		printf("***ERROR*** : Realloc failed.");
	}
}

void bndBoxListDebugPrint(bndBoxList *boxList) {
	for (ulong i = 0; i < boxList->size; ++i) {
		bndBoxDebugPrint(&boxList->list[i]);
	}
}
