#include "includes.h"

#ifndef BNDBOX
#define BNDBOX

typedef enum { NONE, LINE, CHAR } DrawMode;

typedef struct bndBox
{
	ulong x1;		//x axis coordinate of top left corner
	ulong y1;		//y axis coordinate of top left corner
	ulong x2;		//x axis coordinate of bottom right corner
	ulong y2;		//y axis coordinate of bottom right corner
	DrawMode mode;	//Used to remember if this was a line or a char box
} bndBox;

/* Prototypes */
bndBox bndBoxNew(ULONG x1, ULONG y1, ULONG x2, ULONG y2);
void bndBoxInit(bndBox *box, ULONG x1, ULONG y1, ULONG x2, ULONG y2);
void bndBoxFree(bndBox *box);
void bndBoxDebugPrint(const bndBox *box);
ulong bndBoxGetWidth(const bndBox *box);
ulong bndBoxGetHeight(const bndBox *box);
#endif
