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
  int structure[3] = {2, 4, 1};
  double **entries = malloc(4 * sizeof(int*));
  for (int i = 0; i < 4; i++)
  {
    entries[i] = malloc(2 * sizeof(int));
  }
  entries[0][0] = 0; entries[0][1] = 0;
  entries[1][0] = 0; entries[1][1] = 1;
  entries[2][0] = 1; entries[2][1] = 0;
  entries[3][0] = 1; entries[3][1] = 1;

  double *expected = malloc(4 * sizeof(double));
  expected[0] = 0;
  expected[1] = 1;
  expected[2] = 1;
  expected[3] = 0;

  struct NeuralNetwork *network = initializingNetwork(structure, 3);
  //struct NeuralNetwork *network = loadNetwork("Recognition/Xor");

  if (network != NULL)
  {
    for (int i = 0; i < network->nbLayer; i++)
    {
      printf("Couche %d - ", i);
      for (int j = 0; j < network->layers[i].nbNeuron; j++)
      {
        printf("\nNeuron %d : ", j);
        for (int k = 0; k < network->layers[i].neurons[j].nbSynap; k++)
        {
          printf("%f, ", network->layers[i].neurons[j].synapses[k]);
        }
      }
      printf("\n");
    }

    for (int i=0; i<8000; i++)
    do
    {
      trainXOR(network, entries, expected, 4, 2);
    } while(network->lastNeuron->deltaError > 0.1 &&
        network->lastNeuron->deltaError < -0.1);
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
  srand(time(NULL));
  for (; i < nbLayers; i++)
  {
    if (!i)
    {
      network->layers[i] = *initializingLayer(neurons[i], 0);
    }
    else
    {
      network->layers[i] = *initializingLayer(neurons[i], neurons[i-1]);
    }
  }

  network->lastNeuron = network->layers[i-1].neurons;
  network->nbLastNeuron = network->layers[i-1].nbNeuron;

  return network;
}

double computeError(struct Neuron *neuron, double expected)
{
  /*for (int i = 0; i < network->nbLastNeuron; i++)
  {
    network->lastNeuron[i].deltaError = expected[i] - network->lastNeuron[i].out;
  }*/
  return expected - neuron->out;
}

void forwardPropa(struct NeuralNetwork *network)
{
  for (int i = 1; i < network->nbLayer; i++)
  {
    computeSum(&network->layers[i-1], &network->layers[i]);
  }
}

void backPropa(struct NeuralNetwork *network, double *expected)
{
  for (int i = 0; i < network->nbLastNeuron; i++)
  {
    network->lastNeuron[i].deltaError = computeError(&network->lastNeuron[i], expected[i]);
  }

  for (int i = network->nbLayer - 2; i > 0; i--)
  {
    updateError(&network->layers[i], &network->layers[i+1]);
  }

  for (int i = 1; i < network->nbLayer; i++)
  {
    updateWeight(&network->layers[i-1], &network->layers[i]);
  }
}

void trainXOR(struct NeuralNetwork *network, double **entries, 
    double *expected,
    int entry_th, int nbEntries)
{
  for (int i = 0; i < entry_th; i++)
  {
    for (int j = 0; j < nbEntries; j++)
    {
      network->layers[0].neurons[j].out = entries[i][j];
    }

    forwardPropa(network);
    backPropa(network, &expected[i]);
    printf("a = %f, b = %f (e : %f) -- XOR = %f\n",
        network->layers[0].neurons[0].out,
        network->layers[0].neurons[1].out,
        network->lastNeuron->deltaError,
        network->lastNeuron->out);
  }
  printf("\n");
}

void train(struct NeuralNetwork *network, double **entries, double *expected)
{
  int count = 0;
  for (int j = 0; j < 10; j++)
  {
    for (int i = 0; i < 10; i++)
    {
      network->layers[0].neurons[count].out = entries[i][j];
      count++;
    }
  }

  forwardPropa(network);
  if (expected != NULL)
    backPropa(network, expected);
}
