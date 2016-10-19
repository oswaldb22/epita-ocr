/* You can put all your quick structure/functions tests in this file */

#include "includes.h"
#include "bwMatrix.h"
#include "bndBox.h"
#include "bndBoxList.h"
#include "treatment.h"

void TestMat(bwMatrix *mat) {

	srand(time(NULL));
	//*/
	for (ulong w = 0; w < mat->width; w++)
		for (ulong h = 0; h < mat->height; h++)
		{
			uint r = rand() % 2;
			bwMatrixSetValue(mat, w, h, r);
		}
	for (ulong h = 0; h < mat->height; h++)
	{
		for (ulong w = 0; w < mat->width; w++)
		{
			uint val = bwMatrixGetValue(mat, w, h);
			printf(" %i", val);
		}
		printf("\n");
	}
	//*/

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
	bwMatrix two = cropUsingBox(&test, &box);
	printf("=====\n");
	for (ulong h = 0; h < two.height; h++)
	{
		for (ulong w = 0; w < two.width; w++)
		{
			uint val = bwMatrixGetValue(&two, w, h);
			printf(" %i", val);
		}
		printf("\n");
	}
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
