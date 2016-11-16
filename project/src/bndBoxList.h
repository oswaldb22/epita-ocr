#include "includes.h"
#include "bndBox.h"

#ifndef BNDBOXLIST
#define BNDBOXLIST

typedef struct bndBoxList
{
	ulong size;		//Size of the array
	bndBox *list;	//Array containing multiple bndBox
} bndBoxList;

/* Prototypes */

void bndBoxListInit(bndBoxList *boxList);
void bndBoxListFree(bndBoxList *boxList);
void bndBoxListAdd(bndBoxList *boxList, const bndBox box);
void bndBoxListDebugPrint(bndBoxList *boxList);
#endif
