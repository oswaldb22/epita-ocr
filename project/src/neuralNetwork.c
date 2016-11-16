#include "neuralNetwork.h"
#include <math.h>


void weight_init(float *weights, int size, float  minval, float maxval)
{
     int i;
     int random_generated;

     for(i=0;i<size;i++)  {
          random_generated = random();
          *(weights + i) = (maxval - minval)
	         * (float)random_generated / RANDOM_MAXIMUM + minval;
     }

     return;
}

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


//Primitive











//void weight_iniT()

void neuralNetInit(NeuralNetwork* N){

	/*N->inputLayerSize=sizes[0];
	N->outputLayerSize=1;
	N->hiddenLayerSize=sizes[1];*/

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

    sum->width=y->width;
    sum->height=x->height;

    for(int i =0;i<sum->width;i++)
        for(int j =0;j<sum->width;j++)
            sum->matrix[j][i]=0;

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





