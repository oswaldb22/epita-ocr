#include "treatment.h"

bwMatrix convertToBw(rgbMatrix *rgbM) {

	bwMatrix bwM;
	bwMatrixInit(&bwM, rgbGetWidth(rgbM), rgbGetHeight(rgbM));

	/*/ WIP - waiting for rbgM fix
	color c;
	for (ulong i = 0; i < rgbGetWidth(rgbM); i++)
	{
		for (ulong j = 0; j < rgbGetHeight(rgbM); j++)
		{
			c = rgb
		}
	}
	//*/
}

bwMatrix cropUsingBox(bwMatrix *bwM_toCrop, bndBox *box) {

	ulong width = bndBoxGetWidth(box);
	ulong height = bndBoxGetHeight(box);

	bwMatrix bwM_res;
	bwMatrixInit(&bwM_res, width, height);

	for (ulong w = 0; w < width; ++w)
		for (ulong h = 0; h < height; ++h) {
			uint newval = bwMatrixGetValue(bwM_toCrop, box->x1 + w, box->y1 + h);
			bwMatrixSetValue(&bwM_res, w, h, newval);
		}
	return bwM_res;
}