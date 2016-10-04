/* You can put all your quick structure/functions tests in this file */

#include "includes.h"
#include "bwMatrix.h"

void Testbw0() {

	time_t t;
	srand((unsigned)time(&t));

	bwMatrix test;
	test.width = 20;
	test.height = 20;
	test.matrix = malloc(20 * sizeof(int*));
	for (int i = 0; i<20; i++) test.matrix[i] = malloc(20 * sizeof(int));

	for (size_t i = 0; i < test.width; i++)
	{
		for (size_t j = 0; j < test.height; j++)
		{
			unsigned int A = rand() % 2;
			test.matrix[i][j] = A;
			printf("%u ", A);
		}
		printf("\n");
	}
}