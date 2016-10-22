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

void removeWhiteSpaces(bwMatrix *bwM_noModify, bndBox *box_toResize) {

	if (bwMatrixGetValue(bwM_noModify, box_toResize->x1, box_toResize->y1) && bwMatrixGetValue(bwM_noModify, box_toResize->x2, box_toResize->y2))
		return;

	if (bwMatrixGetValue(bwM_noModify, box_toResize->x2, box_toResize->y1) && bwMatrixGetValue(bwM_noModify, box_toResize->x1, box_toResize->y2))
		return;

	int getOut = 0;
	//Left
	while (!getOut) {
		if (box_toResize->x1 == box_toResize->x2)
			break;
		for (ulong i = box_toResize->y1; i < box_toResize->y2; ++i) {
			if (bwMatrixGetValue(bwM_noModify, box_toResize->x1, i) != 0) {
				getOut = 1;
				break;
			}
		}
		if (!getOut)
			++box_toResize->x1;
	}
	//Right
	getOut = 0;
	while (!getOut) {
		if (box_toResize->x1 == box_toResize->x2)
			break;
		for (ulong i = box_toResize->y1; i < box_toResize->y2; ++i) {
			if (bwMatrixGetValue(bwM_noModify, box_toResize->x2, i) != 0) {
				getOut = 1;
				break;
			}
		}
		if (!getOut)
			--box_toResize->x2;
	}
	//Top
	getOut = 0;
	while (!getOut) {
		if (box_toResize->y1 == box_toResize->y2)
			break;
		for (ulong i = box_toResize->x1; i < box_toResize->x2; ++i) {
			if (bwMatrixGetValue(bwM_noModify, i, box_toResize->y1) != 0) {
				getOut = 1;
				break;
			}
		}
		if (!getOut)
			++box_toResize->y1;

	}
	//Bottom
	getOut = 0;
	while (!getOut) {
		if (box_toResize->y1 == box_toResize->y2)
			break;
		for (ulong i = box_toResize->x1; i < box_toResize->x2; ++i) {
			if (bwMatrixGetValue(bwM_noModify, i, box_toResize->y2) != 0) {
				getOut = 1;
				break;
			}
		}
		if (!getOut)
			--box_toResize->y2;
	}
}

void cropUsingBox(bwMatrix *bwM_toCrop, bwMatrix *bwM_res, bndBox *box) {

	ulong width = bndBoxGetWidth(box);
	ulong height = bndBoxGetHeight(box);

	for (ulong w = 0; w < width; ++w)
		for (ulong h = 0; h < height; ++h) {
			uint newval = bwMatrixGetValue(bwM_toCrop, box->x1 + w, box->y1 + h);
			bwMatrixSetValue(bwM_res, w, h, newval);
			//bwMatrixPrintCompact(bwM_res, Advanced);
		}
}

void getLines(bwMatrix *bwM_block, bndBoxList *bndList_out, bndBoxList *bndList_draw, ulong originW, ulong originH) {

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
					bndBox newline;
					bndBoxInit(&newline, 0, start, w, h - 1);
					removeWhiteSpaces(bwM_block, &newline);
					bndBoxListAdd(bndList_out, newline);

					//Gives modified version in global coordinates to draw
					newline.x1 += originW;
					newline.x2 += originW;
					newline.y1 += originH;
					newline.y2 += originH;
					newline.mode = LINE;
					bndBoxListAdd(bndList_draw, newline);

					buildingline = 0;
					bndBoxFree(&newline);
					break;
				}
			}
			w++;
		}
		h++;
	}
}

void getChars(bwMatrix *bwM_line, bndBoxList *bndList_out, bndBoxList *bndList_draw, ulong originW, ulong originH) {

	int buildingchar = 0;
	ulong w = 0;
	ulong start = 0;
	//For each column in the Matrix
	while (w < bwM_line->width)
	{
		ulong h = 0;
		while (h < bwM_line->height) {
			//If we encounter a char and are not building one, start a new char
			if (buildingchar == 0 && bwMatrixGetValue(bwM_line, w, h) == 1) {
				start = w;
				buildingchar = 1;
				break;
			}
			//If we are building a char
			if (buildingchar == 1) {
				//If we encounter something, this is part of our char so go to next column
				if (bwMatrixGetValue(bwM_line, w, h) == 1)
					break;
				//If we reach the end of the column without encountering anything, end the char
				if (h == bwM_line->height - 1) {
					bndBox newchar;
					bndBoxInit(&newchar, start, 0, w - 1, h);
					removeWhiteSpaces(bwM_line, &newchar);
					bndBoxListAdd(bndList_out, newchar);

					//Gives modified version in global coordinates to draw
					newchar.x1 += originW;
					newchar.x2 += originW;
					newchar.y1 += originH;
					newchar.y2 += originH;
					newchar.mode = CHAR;
					bndBoxListAdd(bndList_draw, newchar);

					buildingchar = 0;
					bndBoxFree(&newchar);
					break;
				}
			}
			h++;
		}
		if (w == bwM_line->width - 1 && buildingchar == 1) {
			bndBox newchar;
			bndBoxInit(&newchar, start, 0, w, bwM_line->height - 1);
			removeWhiteSpaces(bwM_line, &newchar);
			bndBoxListAdd(bndList_out, newchar);

			//Gives modified version in global coordinates to draw
			newchar.x1 += originW;
			newchar.x2 += originW;
			newchar.y1 += originH;
			newchar.y2 += originH;
			newchar.mode = CHAR;
			bndBoxListAdd(bndList_draw, newchar);

			buildingchar = 0;
			bndBoxFree(&newchar);
		}
		w++;
	}
}
