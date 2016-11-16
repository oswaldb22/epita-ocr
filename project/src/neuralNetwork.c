#include "neuralNetwork.h"
#include <math.h>

void matrixInit(Matrix *x,const ulong w, const ulong h){
	ulong i=0,j=0;
	x->width=w;
	x->height=h;

	x->matrix = malloc(w * sizeof(float));
	for(i=0;i<w;i++){
			x->matrix[i]=malloc(h*sizeof(float));
	}

	for(i=0;i<w;i++){
		for(j=0;j<h;j++){
			x->matrix[i][j]=0;
		}
	}
}

void matrixPrint(Matrix *rgbM){
  for (ulong j = 0; j < rgbM->height; j++)
	{
		for (ulong i = 0; i < rgbM->width; i++)
		{
            printf(" %f ",rgbM->matrix[j][i]);
		}
		printf("\n");
	}
}




//Primitive
void neuralNetInit(NeuralNetwork* N){

   	N->inputLayerSize=2;
	N->outputLayerSize=1;
	N->hiddenLayerSize=3;
    /*W1*/
    double w=N->hiddenLayerSize;
    double h=N->inputLayerSize;

    /*WEIGHT INIT WITH SIZE*/
    N->weight = malloc(w * sizeof(double*));
	for(int i=0;i<w;i++){
			N->weight[i]=malloc(h*sizeof(double));
	}

	/*WEIGHT INIT WITH RANDOM VALUE*/
    for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
            srand(time(NULL));
            float r = rand()%5;
			N->weight[i][j]=r;
		}
	}


    /*W2*/
    w=N->outputLayerSize;
    h=N->hiddenLayerSize;
    /*WEIGHT INIT WITH SIZE*/
    N->weight2 = malloc(w * sizeof(double*));
	for(int i=0;i<w;i++){
			N->weight2[i]=malloc(h*sizeof(double));
	}

	/*WEIGHT INIT WITH RANDOM VALUE*/
    for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
            srand(time(NULL));
            float r = rand()%5;
			N->weight2[i][j]=r;
		}
	}



}

void matrixDot(Matrix *sum,Matrix *x, Matrix *y){
    matrixInit(sum,y->width,x->height);
    for(int i =0;i<x->height;i++){
    	for(int j=0;j<y->height;j++){
			for(int k = 0; k < y->width; k++){
				sum->matrix[i][j]+=x->matrix[i][k]*y->matrix[k][j];
			}
		}
	}
}

void forward(NeuralNetwork *neuralN,Matrix *r){

}


void sigmoidMatrix(Matrix *z){

	for(int i=0;i<z->width;i++)
		for(int j=0;j<z->height;j++)
			z->matrix[j][i]=sigmoid(z->matrix[j][i]);
}

void randMatrix(Matrix *z,float max){
    srand(time(NULL));
    for(int i=0;i<z->width;i++){
		for(int j=0;j<z->height;j++){

            float r = ((float)rand()/(float)(RAND_MAX)) * max;
			z->matrix[i][j]=r;
		}
    }
}


float sigmoid(float x)
{
    return 1 / (1 + exp((double) -x));
}
