/* You can put all your quick structure/functions tests in this file */

#include "includes.h"
#include "bwMatrix.h"
#include "bndBox.h"
#include "bndBoxList.h"
#include "treatment.h"


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
	bwMatrixPrintCompact(&test, Advanced);

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

	bwMatrixPrintCompact(&test, Advanced);


	bwMatrix foo;
	bwMatrixInit(&foo, 10, 10);
	bwMatrixPrintCompact(&foo, Advanced);
	bwMatrixFree(&foo);

	
	bndBoxList testList;
	bndBoxListInit(&testList);
	getLines(&test, &testList);
	

	for (ulong i = 0; i < testList.size; i++)
	{
		bwMatrix line;
		bndBox current = testList.list[i];
		bwMatrixInit(&line, bndBoxGetWidth(&current), bndBoxGetHeight(&current));
		cropUsingBox(&test, &line, &current);
		bwMatrixPrintCompact(&line, Advanced);
		bwMatrixFree(&line);
	}

	bndBoxListFree(&testList);
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
}

void TestbndBox() {

	bndBox box = bndBoxNew(2, 3, 12, 14);
	bndBoxDebugPrint(&box);
}

void TestbndBoxList() {

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
}
