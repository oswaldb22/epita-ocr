#include "includes.h"

#ifndef NEURON
#define NEURON

struct Neuron
{
	int nbSynapse;
	double *synapses;
	double bias;
	double sum;
	double delta;
	double out;
};

struct Neuron *initNeuron(int nbSynapses);
double sigmoid(double val);
double derivateSigmoid(double x);
void compute(struct Neuron *neuron);

#endif
