#ifndef L_H
#define L_H

#include "includes.h"
#include "neuron.h"

typedef struct Layer
{
  Neuron *nArray;
  int nCount;
} Layer;

Layer *initLay(int nCount, int sCount);
void workoutTotal(Layer *prev, Layer *cur);
void workoutErr(Layer *cur, Layer *next);
void workoutWeight(Layer *prev, Layer *cur);

#endif
