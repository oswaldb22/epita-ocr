#include "includes.h"
#include "bwMatrix.h"

void Testbw0() {

	time_t t;
	srand(t);

	bwMatrix test = bwMatrix_new(20, 20);

	for (size_t i = 0; i < test.width; i++)
		for (size_t j = 0; j < test.height; j++)
			bwMatrix_SetVal(test, i, j, rand() % 2);

	for (size_t i = 0; i < test.width; i++) {
		for (size_t j = 0; j < test.height; j++) {
			size_t A = bwMatrix_GetVal(test, i, j);
			printf("%u ", A);
		}
		printf("\n");
	}
}