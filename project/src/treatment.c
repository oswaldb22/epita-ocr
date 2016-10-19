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

bwMatrix cropUsingBox(bwMatrix *mat, bndBox *box) {

	ulong width = bndBoxGetWidth(box);
	ulong height = bndBoxGetHeight(box);

	bwMatrix bwM;
	bwMatrixInit(&bwM, width, height);

	for (ulong w = 0; w < width; ++w)
		for (ulong h = 0; h < height; ++h) {
			uint newval = bwMatrixGetValue(mat, box->x1 + w, box->y1 + h);
			bwMatrixSetValue(&bwM, w, h, newval);
		}
	return bwM;
}