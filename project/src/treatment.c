#include "treatment.h"

bwMatrix convertToBw(rgbMatrix *rgbM) {

	bwMatrix bwM;
	bwMatrixInit(&bwM, rgbGetWidth(rgbM), rgbGetHeight(rgbM));

	color c;
	for (ulong w = 0; w < rgbGetWidth(rgbM); w++)
	{
		for (ulong h = 0; h < rgbGetHeight(rgbM); h++)
		{
			c = rgbGetColorXY(rgbM, w, h);
			float res = (float)c.r * 0.3 + (float)c.b * 0.11 + (float)c.g * 0.59;
			res = res < 128 ? 0 : 1;
			bwMatrixSetValue(&bwM, w, h, (uint)res);
		}
	}

	return bwM;/*A modifier*/
}

bwMatrix cropUsingBox(bwMatrix *bwM_toCrop, bndBox *box) {

	ulong width = bndBoxGetWidth(box);
	ulong height = bndBoxGetHeight(box);

	bwMatrix bwM_res;
	bwMatrixInit(&bwM_res, width, height);
	bwMatrixPrintCompact(&bwM_res, Simple);
	bwMatrixPrintCompact(&bwM_res, Advanced);

	for (ulong w = 0; w < width; ++w)
		for (ulong h = 0; h < height - 1; ++h) {
			uint newval = bwMatrixGetValue(bwM_toCrop, box->x1 + w, box->y1 + h);
			bwMatrixSetValue(&bwM_res, w, h, newval);
			//bwMatrixPrintCompact(&bwM_res, Advanced);
		}
	return bwM_res;
}

bndBoxList getLines(bwMatrix *bwM_block) {
	bndBoxList boxList;
	bndBoxListInit(&boxList);

	int buildingline = 0;
	ulong h = 0;
	ulong start = 0;

	//For each row in the Matrix
	while (h < bwM_block->height)
	{
		ulong w = 0;
		while (w < bwM_block->width) {
			//If we encounter a line and are not building one, start a new line
			if (buildingline == 0 && bwMatrixGetValue(bwM_block, w, h) == 1) {
				start = h;
				buildingline = 1;
				break;
			}
			//If we are building a line
			if (buildingline == 1) {
				//If we encounter something, this is part of our line so go to next row
				if (bwMatrixGetValue(bwM_block, w, h) == 1)
					break;
				//If we reach the end of the row without encountering anything, end the line
				if (w == bwM_block->width - 1) {
					bndBox newline = bndBoxNew(0, start, w, h - 1);
					bndBoxListAdd(&boxList, newline);
					buildingline = 0;
					break;
				}
			}
			w++;
		}
		h++;
	}

	return boxList;
}