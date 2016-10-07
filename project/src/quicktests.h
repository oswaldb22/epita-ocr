/* You can put all your quick structure/functions tests in this file */

#include "includes.h"
#include "bwMatrix.h"

void Testbw0() {

	/*/
	time_t t;
	srand((unsigned)time(&t));

	bwMatrix test = bwMatrix_New(20, 20);

	for (ulong w = 0; w < test.width; w++)
		for (ulong h = 0; h < test.height; h++) 
		{
			ulong r = rand() % 2;
			bwMatrix_SetVal(test, w, h, r);
		}

	for (ulong w = 0; w < test.width; w++)
	{
		for (ulong h = 0; h < test.height; h++)
		{
			ulong val = bwMatrix_GetVal(test, w, h);
			printf(" %lu", val);
		}
		printf("\n");
	}
	//*/
}