/* You can put all your quick structure/functions tests in this file */

#include "includes.h"
#include "bwMatrix.h"
#include "bndBox.h"
#include "bndBoxList.h"
#include "treatment.h"
#include "load_to_bw.h"
#include "rgbMatrix.h"


void TestBounding() {
	init_sdl();
	SDL_Surface* img = NULL;
	//SDL_Surface* screen = NULL;
	img = load_image("./data/Lorem-ju.bmp");
	
	display_image(img);
	//invertImg(img);
	//display_image(img);
	
	rgbMatrix rgbM;
	rgbInit(&rgbM, img->w, img->h);
	printf("Size = %lu, %lu\n", rgbM.width, rgbM.height);

	bwMatrix bwM;
	bwMatrixInit(&bwM, img->w, img->h);
	printf("Size = %lu, %lu\n", bwM.width, bwM.height);
	
	//load_rgbM(&rgbM, img);
	
	load_bwM(&bwM, img);

	bwMatrixList bwMList_lines;
	bwMatrixListInit(&bwMList_lines);

	bwMatrixList bwMList_chars;
	bwMatrixListInit(&bwMList_chars);

	bndBoxList drawList_lines;
	bndBoxListInit(&drawList_lines);

	bndBoxList drawList_chars;
	bndBoxListInit(&drawList_chars);
	
	//bwMatrixPrintCompact(&bwM, Advanced);
	
	//Not working to fix
	getEverything(&bwM, &bwMList_lines, &bwMList_chars, &drawList_lines, &drawList_chars);
	
	//printf("%lu %lu \n", drawList_lines.size, drawList_chars.size);
	
	//drawBoundingBoxesBw(&bwM, &drawList_lines);
	drawBoundingBoxesBw(&bwM, &drawList_chars);
	
	convertBwToBmp(&bwM, img);

	display_image(img);
	
	//bndBoxListFree(&drawList_lines);
	//bndBoxListFree(&drawList_chars);
	//bwMatrixListFree(&bwMList_lines);
	//bwMatrixListFree(&bwMList_chars);
	rgbFree(&rgbM);
	bwMatrixFree(&bwM);
	//*/
}

void TestMat(bwMatrix *mat) {
	srand(time(NULL));
	for (ulong w = 0; w < mat->width; w++)
		for (ulong h = 0; h < mat->height; h++)
		{
			uint r = rand() % 2;
			bwMatrixSetValue(mat, w, h, r);
		}
	bwMatrixPrintCompact(mat, Advanced);
}

void TestCut() {
	bwMatrix test;
	bwMatrixInit(&test, 10, 10);

	bwMatrixSetValue(&test, 1, 1, 1);
	bwMatrixSetValue(&test, 1, 2, 1);
	bwMatrixSetValue(&test, 1, 3, 1);
	bwMatrixSetValue(&test, 1, 4, 1);
	bwMatrixSetValue(&test, 1, 6, 1);
	bwMatrixSetValue(&test, 1, 7, 1);
	bwMatrixSetValue(&test, 1, 8, 1);

	bwMatrixSetValue(&test, 2, 1, 1);
	bwMatrixSetValue(&test, 2, 3, 1);

	bwMatrixSetValue(&test, 3, 1, 1);
	bwMatrixSetValue(&test, 3, 2, 1);
	bwMatrixSetValue(&test, 3, 3, 1);
	bwMatrixSetValue(&test, 3, 4, 1);
	bwMatrixSetValue(&test, 3, 6, 1);
	bwMatrixSetValue(&test, 3, 7, 1);

	bwMatrixSetValue(&test, 4, 6, 1);
	bwMatrixSetValue(&test, 4, 7, 1);

	bwMatrixSetValue(&test, 5, 1, 1);
	bwMatrixSetValue(&test, 5, 2, 1);
	bwMatrixSetValue(&test, 5, 3, 1);
	bwMatrixSetValue(&test, 5, 4, 1);

	bwMatrixSetValue(&test, 6, 1, 1);
	bwMatrixSetValue(&test, 6, 4, 1);
	bwMatrixSetValue(&test, 6, 6, 1);
	bwMatrixSetValue(&test, 6, 8, 1);

	bwMatrixSetValue(&test, 7, 7, 1);
	bwMatrixSetValue(&test, 7, 8, 1);

	bwMatrixSetValue(&test, 8, 1, 1);
	bwMatrixSetValue(&test, 8, 2, 1);
	bwMatrixSetValue(&test, 8, 4, 1);

	bwMatrixList bwMList_lines;
	bwMatrixListInit(&bwMList_lines);

	bwMatrixList bwMList_chars;
	bwMatrixListInit(&bwMList_chars);

	bndBoxList drawList_lines;
	bndBoxListInit(&drawList_lines);

	bndBoxList drawList_chars;
	bndBoxListInit(&drawList_chars);

	getEverything(&test, &bwMList_lines, &bwMList_chars, &drawList_lines, &drawList_chars);

	bndBoxListFree(&drawList_lines);
	bndBoxListFree(&drawList_chars);
	bwMatrixListFree(&bwMList_lines);
	bwMatrixListFree(&bwMList_chars);
	bwMatrixFree(&test);
}


void Testbw0() {

	//*/

	bwMatrix test;
	bwMatrixInit(&test, 5, 5);
	TestMat(&test);
	bwMatrixFree(&test);

	//*/
}

void TestTreatment0() {
	/* TODO : fix with bndBox as pointer
	bndBox box = bndBoxNew(1, 2, 4, 3);
	bwMatrix test;
	bwMatrixInit(&test, 5, 5);
	TestMat(&test);
	bwMatrix two;
	bwMatrixInit(&two, bndBoxGetWidth(&box), bndBoxGetHeight(&box));
	cropUsingBox(&test, &two, &box);
	printf("=====");
	bwMatrixPrintCompact(&two, Simple);
	bwMatrixPrintCompact(&two, Advanced);
	bwMatrixFree(&test);
	bwMatrixFree(&two);
	*/
}

void TestbndBox() {
	/* TODO : fix with bndBox as pointer
	bndBox box = bndBoxNew(2, 3, 12, 14);
	bndBoxDebugPrint(&box);
	*/
}

void TestbndBoxList() {
	/* TODO : fix with bndBox as pointer
		bndBoxList myboxlist;
		bndBoxListInit(&myboxlist);
		bndBox box0 = bndBoxNew(0, 0, 10, 10);
		bndBox box1 = bndBoxNew(1, 1, 11, 11);
		bndBox box2 = bndBoxNew(2, 2, 12, 12);
		bndBox box3 = bndBoxNew(3, 3, 13, 13);
		bndBox box4 = bndBoxNew(4, 4, 14, 14);
		bndBoxListAdd(&myboxlist, box0);
		bndBoxListAdd(&myboxlist, box1);
		bndBoxListAdd(&myboxlist, box2);
		bndBoxListAdd(&myboxlist, box3);
		bndBoxListAdd(&myboxlist, box4);
		bndBoxListDebugPrint(&myboxlist);
		bndBoxListFree(&myboxlist);
		*/
}
