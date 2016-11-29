#ifndef S_H
#define S_H

#include "includes.h"
#include "neuralNetwork.h"
#include "layer.h"
#include "neuron.h"

void save(NeuralNetwork *net, char path[]);
NeuralNetwork *load(char path[]);

#endif
