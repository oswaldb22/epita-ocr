#include "includes.h"

#ifndef BNDBOX
#define BNDBOX

typedef struct
{
	ulong x1;	//x axis coordinate of top left corner
	ulong y1;	//y axis coordinate of top left corner
	ulong x2;	//x axis coordinate of bottom right corner
	ulong y2;	//y axis coordinate of bottom right corner
} bndBox;

/* Prototypes */

void bndBoxInit(bndBox *box, const ulong x1, const ulong y1, const ulong x2, const ulong y2);
void bndBoxFree(bndBox *box);
void bndBoxDebugPrint(const bndBox *box);
ulong bndBoxGetWidth(const bndBox *box);
ulong bndBoxGetHeight(const bndBox *box);
#endif
