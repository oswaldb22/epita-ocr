#ifndef LAYER_H_DEFINE
#define LAYER_H_DEFINE

struct Layer 
{
  struct Neuron *neurons;
  int nbNeuron;
};

struct Layer *initializingLayer(int nbNeuron, int nbSynap);
void computeSum(struct Layer *before, struct Layer *current);
void updateError(struct Layer *current, struct Layer *next);
void updateWeight(struct Layer *before, struct Layer *current);

#endif