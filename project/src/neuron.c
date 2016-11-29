#include "neuron.h"

Neuron *initNeur(int sCount)
{
	Neuron *ne = malloc(sizeof(Neuron));
	ne->sCount = sCount;
	ne->synArray = malloc(sCount * sizeof(double));
	int i = 0;
	while(i < sCount){
		ne->synArray[i] = ((double)rand() / (double)RAND_MAX);
		++i;
	}
	ne->total = 0;
	ne->dErr = 0;
	ne->out = 0;
	return ne;
}

double sig(double d)
{
	return 1 / ( 1 + exp(-d));
}

double dSig(double d)
{
	return sig(d) * (1 - sig(d));
}

void workSigmoid(Neuron *ne)
{
	ne->out = sig(ne->total);
}
