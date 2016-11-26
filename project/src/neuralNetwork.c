#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL/SDL.h>

#include "neuralNetwork.h"
#include "layer.h"
#include "neuron.h"
//#include "fonctions.h"
//#include "save.h"
//#include "recognition.h"

// void runNetwork(struct NeuralNetwork *network, int nbIte)
// {
//   //network = initializingNetwork(neurons, 3);

//   if (network != NULL)
//   {
//     /*(int i = 0; i < network->nbLayer; i++)
//     {
//       printf("Couche %d - ", i);
//       for (int j = 0; j < network->layers[i].nbNeuron; j++)
//       {
//         printf("\nNeuron %d : ", j);
//         for (int k = 0; k < network->layers[i].neurons[j].nbSynap; k++)
//         {
//           printf("%f, ", network->layers[i].neurons[j].synapses[k]);
//         }
//       }
//       printf("\n");
//     }*/

//     for (int i = 0; i < nbIte; i++)
//     {
//       for (int j = 0; j <26; j++)
//       {
//         //double **symbolMatrix = loadMatrix("Recognition/Alpha.mat", 'A' - 65 + j);
//         //double *expectedMatrix = loadExpectMatrix("Recognition/AlphaExpected.mat", 'A'-65+j);

//         train(network, symbolMatrix, expectedMatrix);
//         if (i == nbIte - 1)
//         {
//           printf("%c\n", 'A' + j);
//           for (int k = 0; k < 26; k++)
//           {
//             printf("%d = %f - e : %f - o : %f\n", k, network->lastNeuron[k].sum, network->lastNeuron[k].deltaError, network->lastNeuron[k].out);
//           }
//         }
//       }
//     }

//     /*if (nbIte != 1)
//     {
//       int count = 0;
//       while (count != 25 && nbIte != 0)
//       {
//         count = 0;
//         train(network, tab, expected);
//         for (int i = 0; i < 26; i++)
//         {
//           if (network->lastNeuron[i].out < 0.1)
//             count++;
//         }
//         nbIte--;
//       }

//       for (int j = 0; j < 26; j++)
//       {
//         printf("%d = %f - e : %f - o : %f\n", j, network->lastNeuron[j].sum, network->lastNeuron[j].deltaError, network->lastNeuron[j].out);
//       }

//     }
//     else
//     {*/
//       /*for (int i = 0; i < nbIte; i++)
//       {
//         train(nietwork, tab, expected);
//       }*/
//    // }
//    //saveNetwork(network, "Recognition/Alpha");
//   }
// }

void runXorNetwork()
{
	const int in_count = 4;
	const int in_size = 2;
	const int out_size = 1;

	int data[3] = { in_count, in_size, out_size };
	double **entries = malloc(in_count * sizeof(int*));

	int i = 0;
	while (i < in_count) {
		entries[i] = malloc(in_size * sizeof(int));
		++i;
	}

	entries[0][0] = 0; entries[0][1] = 0;
	entries[1][0] = 0; entries[1][1] = 1;
	entries[2][0] = 1; entries[2][1] = 0;
	entries[3][0] = 1; entries[3][1] = 1;

	double *expected = malloc(in_count * sizeof(double));
	expected[0] = 0;
	expected[1] = 1;
	expected[2] = 1;
	expected[3] = 0;

	struct NeuralNetwork *network = initializingNetwork(data, 3);
	//struct NeuralNetwork *network = loadNetwork("Recognition/Xor");

	if (network != NULL)
	{
		printf("\nL");
		do
		{
			switch (time(NULL) % 4)
			{
			case 0:
				printf("\r|");
				break;
			case 1:
				printf("\r/");
				break;
			case 2:
				printf("\r-");
				break;
			case 3:
				printf("\r\\");
				break;
			}
			trainXOR(network, entries, expected, in_count, in_size);
		} while (network->lastNeuron->deltaError > 0.1
			|| network->lastNeuron->deltaError < -0.1);

		printf("\r \n");

		int i = 0;
		while (i < in_count) {
			int j = 0;
			while (j < in_size) {
				network->layers[0].neurons[j].out = entries[i][j];
				++j;
			}
			forwardPropa(network);
			backPropa(network, &expected[i]);
			int in_A = (int)network->layers[0].neurons[0].out;
			int in_B = (int)network->layers[0].neurons[1].out;
			float delta = network->lastNeuron->deltaError;
			float out = network->lastNeuron->out;
			int res = out > 0.5;

			printf("IN[ %d , %d ] \t(%f) \t%f \tOUT[ %d ]\n",
				in_A,
				in_B,
				delta,
				out,
				res);
			++i;
		}
	}
	/*saveNetwork(network);*/
}

//neurons[] gives the number of neurons by layer
struct NeuralNetwork *initializingNetwork(int neurons[], int nbLayers)
{
	struct NeuralNetwork *network = malloc(sizeof(struct NeuralNetwork));
	network->nbLayer = nbLayers;
	network->layers = malloc(nbLayers * sizeof(struct Layer));

	int i = 0;
	srand(2);	//total random
	while (i < nbLayers)
	{
		network->layers[i] = (i == 0) ? *initializingLayer(neurons[i], 0) :
			*initializingLayer(neurons[i], neurons[i - 1]);
		++i;
	}

	network->lastNeuron = network->layers[i - 1].neurons;
	network->nbLastNeuron = network->layers[i - 1].nbNeuron;

	return network;
}

double computeError(struct Neuron *neuron, double expected)
{
	return expected - neuron->out;
}

void forwardPropa(struct NeuralNetwork *network)
{
	int i = 1;
	while (i < network->nbLayer) {
		computeSum(&network->layers[i - 1], &network->layers[i]);
		++i;
	}
}

void backPropa(struct NeuralNetwork *network, double *expected)
{
	int i = 0;
	while (i < network->nbLastNeuron) {
		network->lastNeuron[i].deltaError =
			computeError(&network->lastNeuron[i], expected[i]);
		++i;
	}

	i = network->nbLayer - 2;
	while (i > 0) {
		updateError(&network->layers[i], &network->layers[i + 1]);
		--i;
	}

	i = 1;
	while (i < network->nbLayer) {
		updateWeight(&network->layers[i - 1], &network->layers[i]);
		++i;
	}
}

void trainXOR(struct NeuralNetwork *network, double **entries,
	double *expected,
	int entry_th, int nbEntries)
{
	int i = 0;
	while (i < entry_th) {
		int j = 0;
		while (j < nbEntries) {
			network->layers[0].neurons[j].out = entries[i][j];
			++j;
		}
		forwardPropa(network);
		backPropa(network, &expected[i]);

		if (VERBOSE_TRAINXOR) {
			int in_A = (int)network->layers[0].neurons[0].out;
			int in_B = (int)network->layers[0].neurons[1].out;
			float delta = network->lastNeuron->deltaError;
			float out = network->lastNeuron->out;
			int res = out > 0.5;

			printf("IN[ %d , %d ] \t(%f) \t%f \tOUT[ %d ]\n",
				in_A,
				in_B,
				delta,
				out,
				res);
		}
		++i;
	}
}

void train(struct NeuralNetwork *network, double **entries, double *expected)
{
	int count = 0;
	int j = 0;
	while (j < 10) {
		int i = 0;
		while (i < 10) {
			network->layers[0].neurons[count].out = entries[i][j];
			count++;
			++i;
		}
		++j;
	}

	forwardPropa(network);
	if (expected != NULL)
		backPropa(network, expected);
}
