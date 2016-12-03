#ifndef NN_H
#define NN_H

#include "includes.h"

typedef struct NeuralNetwork
{
	int layCount;
	struct Layer *layArray;
	int lastCount;
	struct Neuron *lastNe;
} NeuralNetwork;

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "pixel_operations.h"
#include "load_to_bw.h"

#include <curses.h>
#include "bwMatrix.h"
#include "bwMatrixList.h"
#include "layer.h"
#include "neuron.h"
#include "saving.h"

int recognize(bwMatrix *bwM);
void workoutNetwork(int ite);
void testXOR();
NeuralNetwork *initNeurNet(int nArray[], int layCount);
double workErr(Neuron *ne, double wonted);
void onward(NeuralNetwork *net);
void backwards(NeuralNetwork *net, double *wonted);
void workoutXOR(NeuralNetwork *net, double **inputs,
	double *wonted, int inputsCount, int inCount);
void train(NeuralNetwork *net, double **inputs, double *wonted);

#endif
