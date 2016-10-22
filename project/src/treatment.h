/* Treatment regroups all operations on bw and rgb matrices */

#ifndef TREATMENT
#define TREATMENT

#include "bndBoxList.h"
#include "bwMatrix.h"
#include "rgbMatrix.h"

bwMatrix convertToBw(rgbMatrix *rgbM);
rgbMatrix convertToRgb(bwMatrix *bwM);

void getLines(bwMatrix *bwM_block, bndBoxList *bndList_out, bndBoxList *bndList_draw, ulong originW, ulong originH);
void getChars(bwMatrix *bwM_line, bndBoxList *bndList_out, bndBoxList *bndList_draw, ulong originW, ulong originH);

/*	When used in cunjunction with a bwMatrix/bndBox pair, 
	this will remove the whitespaces 
	and modify the bndBox to fit the new size */
void removeWhiteSpaces(bwMatrix *bwM_noModify, bndBox *box_toResize);

/* Returns the bwMatrix cropped from given bwMatrix using bndBox as boundaries (included) */
void cropUsingBox(bwMatrix *bwM_toCrop, bwMatrix *bwM_res, bndBox *box);

#endif
