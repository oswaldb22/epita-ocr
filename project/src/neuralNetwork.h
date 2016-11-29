#ifndef NN_H
#define NN_H

#include "includes.h"

#define VERBOSE_TRAINXOR 0

typedef struct NeuralNetwork
{
	struct Layer *layArray;
	int layCount;
	struct Neuron *lastNe;
	int lastCount;
} NeuralNetwork;

#include "layer.h"
#include "neuron.h"
#include "saving.h"

void testXOR();
NeuralNetwork *initNeurNet(int nArray[], int layCount);
double workErr(Neuron *ne, double res);
void onward(NeuralNetwork *net);
void backwards(NeuralNetwork *net, double *res);
void workoutXOR(NeuralNetwork *net, double **inputs,
	double *res, int entry_th, int inCount);
void train(NeuralNetwork *net, double **inputs, double *res);

#endif
