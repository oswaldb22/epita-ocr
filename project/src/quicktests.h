/* You can put all your quick structure/functions tests in this file */

#include "includes.h"
#include "bwMatrix.h"


void TestMat(bwMatrix *mat) {

	srand(time(NULL));
	//*/
	for (ulong w = 0; w < mat->width; w++)
		for (ulong h = 0; h < mat->height; h++)
		{
			uint r = rand() % 2;
			bwMatrixSetValue(mat, w, h, r);
		}
	for (ulong w = 0; w < mat->width; w++)
	{
		for (ulong h = 0; h < mat->height; h++)
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