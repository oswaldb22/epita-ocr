#include "neuron.h"

struct Neuron *initNeuron(int nbSynapse) {

	struct Neuron *neuron = malloc(sizeof(struct Neuron));
	neuron->nbSynapse = nbSynapse;

	neuron->synapses = malloc(nbSynapse * sizeof(double));
	for (int i = 0; i < nbSynapse; i++)
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

void compute(struct Neuron *neuron) {
	neuron->out = sigmoid(neuron->sum);
}