#include <stdlib.h>
#include <time.h>

#include "layer.h"
#include "neuron.h"

struct Layer *initializingLayer(int nbNeuron, int nbSynap)
{
  struct Layer *layer = malloc(sizeof(struct Layer));
  layer->nbNeuron = nbNeuron;

  layer->neurons = malloc(nbNeuron * sizeof(struct Neuron));
  for (int i = 0; i < nbNeuron; i++)
  {
    layer->neurons[i] = *initializingNeuron(nbSynap);
  }

  return layer;
}

void computeSum(struct Layer *before, struct Layer *current)
{
  for (int i = 0; i < current->nbNeuron; i++)
  {
    current->neurons[i].sum = 0;
    for (int j = 0; j < before->nbNeuron; j++)
    {
      current->neurons[i].sum += 
        before->neurons[j].out * 
        current->neurons[i].synapses[j];
    }
    computeOut(&current->neurons[i]);
  }
}

void updateError(struct Layer *current, struct Layer *next)
{
  for (int i = 0; i < current->nbNeuron; i++)
  {
    current->neurons[i].deltaError = 0;
    for (int j = 0; j < next->nbNeuron; j++)
    {
      current->neurons[i].deltaError +=
        next->neurons[j].synapses[i] *
        next->neurons[j].deltaError;

    }
  }
}

void updateWeight(struct Layer *before, struct Layer *current)
{
  for (int i = 0; i < current->nbNeuron; i++)
  { 
    for (int j = 0; j < current->neurons[i].nbSynap; j++)
    {
      current->neurons[i].synapses[j] +=
        current->neurons[i].deltaError * 0.1 *
        derivateSig(current->neurons[i].sum) * 
        before->neurons[j].out;
    }
  }
}