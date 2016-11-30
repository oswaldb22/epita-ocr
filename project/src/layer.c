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

void workoutTotal(Layer *prev, Layer *cur)
{
	int i = 0;
	while(i < cur->nCount)
	{
		cur->nArray[i].total = 0;
		int j = 0;
		while(j < prev->nCount){
			cur->nArray[i].total +=
				prev->nArray[j].out *
				cur->nArray[i].synArray[j];
			++j;
		}
		workSigmoid(&cur->nArray[i]);
		++i;
	}
}

void workoutErr(Layer *cur, Layer *next)
{
	int i = 0;
	while(i < cur->nCount){
		cur->nArray[i].dErr = 0;
		int j = 0;
		while(j < next->nCount){
			cur->nArray[i].dErr +=
				next->nArray[j].synArray[i] *
				next->nArray[j].dErr;
			++j;
		}
		++i;
	}
}

void workoutWeight(Layer *prev, Layer *cur)
{
	int i = 0;
	while(i < cur->nCount){
		int j = 0;
		while(j < cur->nArray[i].sCount){
			cur->nArray[i].synArray[j] +=
				cur->nArray[i].dErr * 0.1 *
				dSig(cur->nArray[i].total) *
				prev->nArray[j].out;
			++j;
		}
		++i;
	}
}
