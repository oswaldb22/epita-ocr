#include <stdlib.h>
#include <time.h>

#include "layer.h"
#include "neuron.h"

struct Layer *initializingLayer(int nbNeuron, int nbSynap)
{
	struct Layer *layer = malloc(sizeof(struct Layer));
	layer->nbNeuron = nbNeuron;

	layer->neurons = malloc(nbNeuron * sizeof(struct Neuron));
	int i = 0;
	while(i < nbNeuron){
		layer->neurons[i] = *initializingNeuron(nbSynap);
		++i;
	}

	return layer;
}

void computeSum(struct Layer *before, struct Layer *current)
{
	int i = 0;
	while(i < current->nbNeuron)
	{
		current->neurons[i].sum = 0;
		int j = 0;
		while(j < before->nbNeuron){
			current->neurons[i].sum +=
				before->neurons[j].out *
				current->neurons[i].synapses[j];
			++j;
		}
		computeOut(&current->neurons[i]);
		++i;
	}
}

void updateError(struct Layer *current, struct Layer *next)
{
	int i = 0;
	while(i < current->nbNeuron){
		current->neurons[i].deltaError = 0;
		int j = 0;
		while(j < next->nbNeuron){
			current->neurons[i].deltaError +=
				next->neurons[j].synapses[i] *
				next->neurons[j].deltaError;
			++j;
		}
		++i;
	}
}

void updateWeight(struct Layer *before, struct Layer *current)
{
	int i = 0;
	while(i < current->nbNeuron){
		int j = 0;
		while(j < current->neurons[i].nbSynap){
			current->neurons[i].synapses[j] +=
				current->neurons[i].deltaError * 0.1 *
				derivateSig(current->neurons[i].sum) *
				before->neurons[j].out;
			++j;
		}
		++i;
	}
}
