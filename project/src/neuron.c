#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "neuron.h"

struct Neuron *init(int nbSynapses) {

	struct Neuron *neuron = malloc(sizeof(struct Neuron));
	neuron->nbSynapses = nbSynapses;

	neuron->synapses = malloc(nbSynapses * sizeof(double));
	for (int i = 0; i < nbSynapses; i++)
		neuron->synapses[i] = ((double)rand() / (double)RAND_MAX);

	neuron->sum = 0;
	neuron->delta = 0;
	neuron->out = 0;

	return neuron;
}

double sigmoid(double x) {
	return 1 / (1 + exp(-x));
}

double derivateSigmoid(double x) {
	return sigmoid(x) * (1 - sigmoid(x));
}

void calculateOutput(struct Neuron *neuron) {
	neuron->out = sigmoid(neuron->sum);
}