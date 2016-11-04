#include "neuralNetwork.h"
#include <math.h>

void neuralNetInit(NeuralNetwork* N,int sizes[],int len){

	N->inputLayerSize=sizes[0];
	N->outputLayerSize=1;
	N->hiddenLayerSize=sizes[1];

}

void forward(NeuralNetwork *neuralN,Matrix *r){




}

void sigmoidMatrix(Matrix *z){

	for(int i=0;i<z->width;i++)
		for(int j=0;j<z->height;j++)
			z->matrix[j][i]=sigmoid(z->matrix[j][i]);
}


float sigmoid(float x)
{
    return 1 / (1 + exp((double) -x));
}

