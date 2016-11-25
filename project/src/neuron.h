#ifndef NEURON_H_DEFINE
#define NEURON_H_DEFINE

struct Neuron
{
  double *synapses;
  int nbSynap;
  double bias;
  double sum;
  double deltaError;
  double out;
};

struct Neuron *initializingNeuron(int synapses);
double sigmoid(double x);
double derivateSig(double x);
void computeOut(struct Neuron *neuron);

#endif