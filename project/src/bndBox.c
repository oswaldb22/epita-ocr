/*
TODO : Insert fancy header
*/

#include "bndBox.h"

void bndBoxInit(bndBox *box, const ulong x1, const ulong y1, const ulong x2, const ulong y2) {
	box->x1 = x1;
	box->y1 = y1;
	box->x2 = x2;
	box->y2 = y2;
}

void bndBoxFree(bndBox *box) {
	box->x1 = 0;
	box->y1 = 0;
	box->x2 = 0;
	box->y2 = 0;
}

ulong bndBoxGetWidth(const bndBox *box) {
	return box->x2 - box->x1 + 1;
}

ulong bndBoxGetHeight(const bndBox *box) {
	return box->y2 - box->y1 + 1;
}

void bndBoxDebugPrint(const bndBox *box) {
	printf("bndBox : (x:%lu,y:%lu) (x:%lu,y:%lu)\n", box->x1, box->y1, box->x2, box->y2);
}
