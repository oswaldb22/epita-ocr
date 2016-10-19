#ifndef TREATMENT
#define TREATMENT

#include "bndBoxList.h"
#include "bwMatrix.h"
#include "rgbMatrix.h"

bwMatrix cropUsingBox(bwMatrix *mat, bndBox *box);

#endif