/*
TODO : Insert fancy header
*/

#include "bwMatrixList.h"

void bwMatrixListInit(bwMatrixList *bwML) {
	bwML->next = NULL;
	bwML->size = 0;
}

void bwMatrixListFree(bwMatrixList *bwML) {
	bwMatrixList *cur = bwML->next;
	while (cur) {
		bwMatrixList *tofree = cur;
		cur = cur->next;
		bwMatrixFree(tofree->data);
		tofree->next = NULL;
		free(tofree);
	}
	bwML->next = NULL;
	bwML->size = 0;
	free(bwML);
}

void bwMatrixListPush(bwMatrixList *bwML, bwMatrixList *elm) {
	elm->next = bwML->next;
	bwML->next = elm;
	++bwML->size;
}

bwMatrixList *bwMatrixListPop(bwMatrixList *bwML) {
	bwMatrixList *cur = bwML->next;
	if (cur) {
		bwML->next = cur->next;
		cur->next = NULL;
	}
	--bwML->size;
	return cur;
}

bwMatrixList *bwMatrixListGet(bwMatrixList *bwML, int i) {
	bwMatrixList *cur = bwML->next;
	while (cur && i > 0) {
		cur = cur->next;
		--i;
	}
	assert(cur);
	return cur;
}

void bwMatrixListDebugPrint(bwMatrixList *bwML) {
	bwMatrixList *cur = bwML->next;
	printf("=== BEGIN BWMLIST PRINT ===\n");
	while (cur) {
		bwMatrixPrintCompact(cur->data, Advanced);
		cur = cur->next;
	}
	printf("=== END BWMLIST PRINT ===\n");
}

/*
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
*/