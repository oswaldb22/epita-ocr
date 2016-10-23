/* Treatment regroups all operations on bw and rgb matrices */

#ifndef TREATMENT
#define TREATMENT

#include "bndBoxList.h"
#include "bwMatrixList.h"
#include "bwMatrix.h"
#include "rgbMatrix.h"

void convertToBw(rgbMatrix *rgbM_in, bwMatrix *bwM_out, int threshold);
void convertToRgb(bwMatrix *bwM_in, rgbMatrix *rgbM_out);

void drawBoundingBoxes(rgbMatrix *rgbM_in, bndBoxList *bndList_draw, DrawMode mode);

void getLines(bwMatrix *bwM_block, bndBoxList *bndList_out, bndBoxList *bndList_draw, ulong originW, ulong originH);
void getChars(bwMatrix *bwM_line, bndBoxList *bndList_out, bndBoxList *bndList_draw, ulong originW, ulong originH);

/*	When used in cunjunction with a bwMatrix/bndBox pair,
	this will remove the whitespaces
	and modify the bndBox to fit the new size */
void removeWhiteSpaces(bwMatrix *bwM_noModify, bndBox *box_toResize);

/* Returns the bwMatrix cropped from given bwMatrix using bndBox as boundaries (included) */
void cropUsingBox(bwMatrix *bwM_toCrop, bwMatrix *bwM_res, bndBox *box);

void getEverything(bwMatrix *bwM_block_in, bwMatrixList *bwMList_lines_out, bwMatrixList *bwMList_chars_out, bndBoxList *bndList_draw_lines, bndBoxList *bndList_draw_chars);

#endif
