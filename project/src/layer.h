#ifndef L_H
#define L_H

#include "includes.h"
#include "neuron.h"

typedef struct Layer
{
  Neuron *nArray;
  int nCount;
} Layer;

struct Layer *initLay(int nCount, int sCount);
void workoutTotal(struct Layer *before, struct Layer *current);
void workoutErr(struct Layer *current, struct Layer *next);
void workoutWeight(struct Layer *before, struct Layer *current);

#endif
