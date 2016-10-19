#ifndef NEURON
#define NEURON

struct Neuron
{
	int nbSynapses;
	double *synapses;
	double bias;
	double sum;
	double delta;
	double out;
};

struct Neuron *init(int nbSynapses);
double sigmoid(double val);
double derivateSigmoid(double x);
void calculateOutput(struct Neuron *neuron);

#endif
