#ifndef NEURALNETWORK_H_DEFINE
#define NEURALNETWORK_H_DEFINE

#define VERBOSE_TRAINXOR 0

struct NeuralNetwork
{
  struct Layer *layers;
  int nbLayer;
  struct Neuron *lastNeuron;
  int nbLastNeuron;
};

void runNetwork(struct NeuralNetwork *network, int nbIte);
void runXorNetwork();
struct NeuralNetwork *initializingNetwork(int neurons[], int nbLayers);
double computeError(struct Neuron *neuron, double expected);
void forwardPropa(struct NeuralNetwork *network);
void backPropa(struct NeuralNetwork *network, double *expected);
void trainXOR(struct NeuralNetwork *network, double **entries,
    double *expected, int entry_th, int nbEntries);
void train(struct NeuralNetwork *network, double **entries, double *expected);

#endif
