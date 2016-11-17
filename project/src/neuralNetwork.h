#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include "includes.h"

#define RANDOM_MAXIMUM 2147483647
typedef struct{
	ulong width;	//nombre de colonnes
	ulong height;	//nombre de lignes
	float **matrix;
}Matrix;

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
	double **weight2;

	Matrix w1;
	Matrix w2;

}NeuralNetwork;



void matrixInit(Matrix *x,const ulong w, const ulong h);
void matrixDot(Matrix *sum,Matrix *x, Matrix *y);
void matrixPrint(Matrix *m);
void randMatrix(Matrix *z,float max);

void neuralNetInit(NeuralNetwork* N);
Matrix* forward(NeuralNetwork *N,Matrix *rgbM);
void sigmoidMatrix(Matrix *z);
float sigmoid(float x);


#endif
