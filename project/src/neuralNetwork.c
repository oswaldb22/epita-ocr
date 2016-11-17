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
			x->matrix[i][j]=1;
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

void randMatrix(Matrix *z,float max){
    srand(time(NULL));
    for(int i=0;i<z->width;i++){
		for(int j=0;j<z->height;j++){

            float r = ((float)rand()/(float)(RAND_MAX)) * max;
			z->matrix[i][j]=r;
		}
    }
}

void matrixDot(Matrix *sum,Matrix *x, Matrix *y){
    double ret;
    matrixInit(sum,y->width,x->height);
    for(int i =0;i<x->height;i++){
    	for(int j=0;j<y->height;j++){
			for(int k = 0; k < y->width; k++){
				ret+=x->matrix[i][k]*y->matrix[k][j];
			}
			sum->matrix[i][j]=ret;
			ret=0;
		}
	}
}


//Primitive
void neuralNetInit(NeuralNetwork* N){

   	N->inputLayerSize=2;
	N->outputLayerSize=1;
	N->hiddenLayerSize=3;

    double w=N->hiddenLayerSize;
    double h=N->inputLayerSize;


	matrixInit(&N->w1,w,h);
	randMatrix(&N->w1,1.0);

	matrixInit(&N->w2,1,w);
    randMatrix(&N->w2,1.0);

}



Matrix* forward(NeuralNetwork *N,Matrix *r){



    Matrix *z2=malloc(sizeof(Matrix));
    matrixInit(z2,1,1);
    matrixDot(z2,r,&N->w1);

    Matrix a2=*z2;
    sigmoidMatrix(&a2);

    Matrix *z3=malloc(sizeof(Matrix));
    matrixInit(z3,1,1);
    //matrixDot(z3,&a2,&N->w2);

    sigmoidMatrix(z3);

    return z3;
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
