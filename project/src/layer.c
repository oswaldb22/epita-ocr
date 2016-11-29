#include "layer.h"

struct Layer *initLay(int nCount, int sCount)
{
	struct Layer *layer = malloc(sizeof(struct Layer));
	layer->nCount = nCount;

	layer->nArray = malloc(nCount * sizeof(Neuron));
	int i = 0;
	while(i < nCount){
		layer->nArray[i] = *initNeur(sCount);
		++i;
	}

	return layer;
}

void workoutTotal(struct Layer *before, struct Layer *current)
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

void workoutErr(struct Layer *current, struct Layer *next)
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

void workoutWeight(struct Layer *before, struct Layer *current)
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
