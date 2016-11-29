#ifndef L_H
#define L_H

#include "includes.h"
#include "neuron.h"

typedef Layer
{
  Neuron *nArray;
  int nCount;
} Layer;

Layer *initLay(int nCount, int sCount);
void workoutTotal(Layer *before, Layer *current);
void workoutErr(Layer *current, Layer *next);
void workoutWeight(Layer *before, Layer *current);

#endif
