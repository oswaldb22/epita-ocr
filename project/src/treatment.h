/* Treatment regroups all operations on bw and rgb matrices */

#ifndef TREATMENT
#define TREATMENT

#include "bndBoxList.h"
#include "bwMatrix.h"
#include "rgbMatrix.h"

bwMatrix convertToBw(rgbMatrix *rgbM);
rgbMatrix convertToRgb(bwMatrix *bwM);

void getLines(bwMatrix *bwM_block, bndBoxList *bwM_out);
bndBoxList getChars(bwMatrix *bwM_line);

rgbMatrix drawBoundingBoxes(rgbMatrix *rgbM, color c);

/* Returns the bwMatrix cropped from given bwMatrix using bndBox as boundaries (included) */
void cropUsingBox(bwMatrix *bwM_toCrop, bwMatrix *bwM_res, bndBox *box);

#endif
