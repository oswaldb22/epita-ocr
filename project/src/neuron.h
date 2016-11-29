#ifndef N_H
#define N_H

#include "includes.h"

typedef struct Neuron
{
	double dErr;
	double out;
	double bias;
	double total;
	int sCount;
	double *synArray;
} Neuron;

Neuron *initNeur(int synArray);
double sig(double d);
double dSig(double x);
void workSigmoid(Neuron *ne);

#endif
