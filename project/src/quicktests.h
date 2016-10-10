/* You can put all your quick structure/functions tests in this file */

#include "includes.h"
#include "bwMatrix.h"


void TestMat(bwMatrix *mat) {

	time_t t;
	srand((unsigned)time(&t));

	for (ulong w = 0; w < mat->width; w++)
		for (ulong h = 0; h < mat->height; h++)
		{
			ulong r = rand() % 2;
			bwMatrix_SetVal(mat, w, h, r);
		}

	for (ulong w = 0; w < mat->width; w++)
	{
		for (ulong h = 0; h < mat->height; h++)
		{
			uint val = bwMatrix_GetVal(*mat, w, h);
			printf(" %i", val);
		}
		printf("\n");
	}

}

void Testbw0() {

	//*/
	

	bwMatrix test = bwMatrix_New(3, 3);
	bwMatrix test2 = bwMatrix_New(5, 5);

	TestMat(&test);
	TestMat(&test2);
	//*/
}