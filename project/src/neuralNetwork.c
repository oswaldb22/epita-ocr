#include "neuralNetwork.h"

void testXOR()
{
	const int in_count = 4;
	const int in_size = 2;
	const int out_size = 1;

	int data[3] = { in_count, in_size, out_size };
	double **inputs = malloc(in_count * sizeof(int*));

	int i = 0;
	while (i < in_count) {
		inputs[i] = malloc(in_size * sizeof(int));
		++i;
	}

	inputs[0][0] = 0; inputs[0][1] = 0;
	inputs[1][0] = 0; inputs[1][1] = 1;
	inputs[2][0] = 1; inputs[2][1] = 0;
	inputs[3][0] = 1; inputs[3][1] = 1;

	double *res = malloc(in_count * sizeof(double));
	res[0] = 0;
	res[1] = 1;
	res[2] = 1;
	res[3] = 0;

	NeuralNetwork *net = initNeurNet(data, 3);
	//NeuralNetwork *net = load("data/net_XOR");

	if (net != NULL)
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
			workoutXOR(net, inputs, res, in_count, in_size);
		} while (net->lastNe->dErr > 0.1
			|| net->lastNe->dErr < -0.1);

		printf("\r \n");

		int i = 0;
		while (i < in_count) {
			int j = 0;
			while (j < in_size) {
				net->layArray[0].nArray[j].out = inputs[i][j];
				++j;
			}
			onward(net);
			backwards(net, &res[i]);
			int in_A = (int)net->layArray[0].nArray[0].out;
			int in_B = (int)net->layArray[0].nArray[1].out;
			float delta = net->lastNe->dErr;
			float out = net->lastNe->out;
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
	//save(net);
}

NeuralNetwork *initNeurNet(int nArray[], int layCount)
{
	NeuralNetwork *net = malloc(sizeof(NeuralNetwork));
	net->layCount = layCount;
	net->layArray = malloc(layCount * sizeof(struct Layer));

	int i = 0;
	srand(2);	//total random
	while (i < layCount)
	{
		net->layArray[i] = (i == 0) ? *initLay(nArray[i], 0) :
			*initLay(nArray[i], nArray[i - 1]);
		++i;
	}

	net->lastNe = net->layArray[i - 1].nArray;
	net->lastCount = net->layArray[i - 1].nCount;

	return net;
}

double workErr(Neuron *ne, double res)
{
	return res - ne->out;
}

void onward(NeuralNetwork *net)
{
	int i = 1;
	while (i < net->layCount) {
		workoutTotal(&net->layArray[i - 1], &net->layArray[i]);
		++i;
	}
}

void backwards(NeuralNetwork *net, double *res)
{
	int i = 0;
	while (i < net->lastCount) {
		net->lastNe[i].dErr =
			workErr(&net->lastNe[i], res[i]);
		++i;
	}

	i = net->layCount - 2;
	while (i > 0) {
		workoutErr(&net->layArray[i], &net->layArray[i + 1]);
		--i;
	}

	i = 1;
	while (i < net->layCount) {
		workoutWeight(&net->layArray[i - 1], &net->layArray[i]);
		++i;
	}
}

void workoutXOR(NeuralNetwork *net, double **inputs,
	double *res,
	int entry_th, int inCount)
{
	int i = 0;
	while (i < entry_th) {
		int j = 0;
		while (j < inCount) {
			net->layArray[0].nArray[j].out = inputs[i][j];
			++j;
		}
		onward(net);
		backwards(net, &res[i]);

		if (VERBOSE_TRAINXOR) {
			int in_A = (int)net->layArray[0].nArray[0].out;
			int in_B = (int)net->layArray[0].nArray[1].out;
			float delta = net->lastNe->dErr;
			float out = net->lastNe->out;
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

void train(NeuralNetwork *net, double **inputs, double *res)
{
	int count = 0;
	int j = 0;
	while (j < 10) {
		int i = 0;
		while (i < 10) {
			net->layArray[0].nArray[count].out = inputs[i][j];
			count++;
			++i;
		}
		++j;
	}

	onward(net);
	if (res != NULL)
		backwards(net, res);
}
