#include "layer.h"

Layer *initLay(int nCount, int sCount)
{
	Layer *layer = malloc(sizeof(Layer));
	layer->nCount = nCount;

	layer->nArray = malloc(nCount * sizeof(Neuron));
	int i = 0;
	while(i < nCount){
		layer->nArray[i] = *initNeur(sCount);
		++i;
	}

	return layer;
}

void workoutTotal(Layer *before, Layer *current)
{
	int i = 0;
	while(i < current->nCount)
	{
		current->nArray[i].total = 0;
		int j = 0;
		while(j < before->nCount){
			current->nArray[i].total +=
				before->nArray[j].out *
				current->nArray[i].synArray[j];
			++j;
		}
		workSigmoid(&current->nArray[i]);
		++i;
	}
}

void workoutErr(Layer *current, Layer *next)
{
	int i = 0;
	while(i < current->nCount){
		current->nArray[i].dErr = 0;
		int j = 0;
		while(j < next->nCount){
			current->nArray[i].dErr +=
				next->nArray[j].synArray[i] *
				next->nArray[j].dErr;
			++j;
		}
		++i;
	}
}

void workoutWeight(Layer *before, Layer *current)
{
	int i = 0;
	while(i < current->nCount){
		int j = 0;
		while(j < current->nArray[i].sCount){
			current->nArray[i].synArray[j] +=
				current->nArray[i].dErr * 0.1 *
				dSig(current->nArray[i].total) *
				before->nArray[j].out;
			++j;
		}
		++i;
	}
}
