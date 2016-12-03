/* Treatment regroups all operations on bw and rgb matrices */

#ifndef TREATMENT
#define TREATMENT

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "neuralNetwork.h"
#include "pixel_operations.h"
#include "load_to_bw.h"
#include "bndBoxList.h"
#include "bwMatrixList.h"
#include "bwMatrix.h"
#include "rgbMatrix.h"

void invertImg(SDL_Surface *img);
void formatTrainingData(char *imgPath);
void demoShowcase(char *imgPath, int isCharMode);

void convertRbgToBmp(rgbMatrix *rgbM_in, SDL_Surface *surface_out);
void convertBwToBmp(bwMatrix *bwM_in, SDL_Surface *surface_out);

void convertToBw(rgbMatrix *rgbM_in, bwMatrix *bwM_out, int threshold);
void convertToRgb(bwMatrix *bwM_in, rgbMatrix *rgbM_out);

void drawBoundingBoxesRgb(rgbMatrix *rgbM_in, bndBoxList *bndList_draw);
void drawBoundingBoxesBw(bwMatrix *bwM_in, bndBoxList *bndList_draw);

void getLines(bwMatrix *bwM_block, bndBoxList *bndList_out,
	bndBoxList *bndList_draw, ulong originW, ulong originH);
void getChars(bwMatrix *bwM_line, bndBoxList *bndList_out,
	bndBoxList *bndList_draw, ulong originW, ulong originH);

/*	When used in cunjunction with a bwMatrix/bndBox pair,
	this will remove the whitespaces
	and modify the bndBox to fit the new size */
void removeWhiteSpaces(bwMatrix *bwM_noModify, bndBox *box_toResize);
char *convertToBwList();

/* Returns the bwMatrix cropped from given bwMatrix
	using bndBox as boundaries (included) */
void cropUsingBox(bwMatrix *bwM_toCrop, bwMatrix *bwM_res, bndBox *box);

void getEverything(bwMatrix *bwM_block_in, bwMatrixList *bwMList_lines_out,
	bwMatrixList *bwMList_chars_out,
	bndBoxList *bndList_draw_lines,
	bndBoxList *bndList_draw_chars);
#endif
