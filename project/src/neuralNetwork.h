#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include "includes.h"

typedef struct{

	/*int nbLayers;
	int size;

	float biases;
	float weights;*/


	//Luminose
	int inputLayerSize;
	int outputLayerSize;
	int hiddenLayerSize;


	double **input;
	double **weight;

}NeuralNetwork;

typedef struct{

	ulong width;	//width of the matrix
	ulong height;	//height of the matrix
	float **matrix;

}Matrix;


void neuralNetInit(NeuralNetwork* N,int sizes[],int len);

void forward(NeuralNetwork *neuralN,Matrix *rgbM);



void sigmoidMatrix(Matrix *z);

float sigmoid(float x);





#endif
