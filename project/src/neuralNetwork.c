#include "neuralNetwork.h"

#define VERBOSE_TRAINXOR 0

char *table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

char table2[10][3] = {
	"00",
	"01",
	"04",
	"05",
	"08",
	"09",
	"12",
	"13",
	"16",
	"85",
};

NeuralNetwork *global = NULL;

int recognize(bwMatrix *bwM){
	if(global == NULL){
		global = load("networks/62x85_trained");
	}

	bwMatrixPrintCompact(bwM, Advanced);

	for (int j = 0; j < 256; ++j)
	{
		global->layArray[0].nArray[j].out = bwM->matrix[j];
	}

	onward(global);

	int wonted = 0;
	float max = 0;
	for (int z = 0; z < 62; ++z) {
		float out = global->lastNe[z].out;
		if (out > max) {
			max = out;
			wonted = z;
		}
	}
	printf("%d\n", wonted);
	int res = table[wonted];
	printf("%c\n", res);
	return res;
}

void workoutNetwork(int ite) {

	const int in_count = 62;
	const int in_size = 256;
	const int out_size = 62;

	int data[3] = { in_count, in_size, out_size };
	(void)(data);
	double **inputs = malloc(in_count * sizeof(int*));

	int i = 0;
	while (i < in_count) {
		inputs[i] = malloc(in_size * sizeof(int));
		++i;
	}

	init_sdl();
	SDL_Surface* img = NULL;
	bwMatrix *bwM = malloc(sizeof(bwMatrix));
	bwMatrixInit(bwM, 16, 16);

	//Define last layer wonted output
	double **wonted = malloc(in_count * out_size * sizeof(double));
	for (int i = 0; i < in_count; ++i)
	{

		wonted[i] = malloc(out_size * sizeof(double));
		for (int j = 0; j < out_size; ++j) {
			wonted[i][j] = i == j;
		}

	}

	int counter = 0;
	//Defines first layer inputs
	for (int i = 0; i < in_count; ++i) {

		char path[35];
		strcpy(path, "./trainingdata/");
		char got = table[i % 62];
		char c[2];
		c[1] = '\0';
		c[0] = got;
		if (i % 62 > 35) {
			strcat(path, "_");
			strcat(path, c);
		}
		else {
			strcat(path, c);
		}
		strcat(path, "/00");
		strcat(path, "85");
		strcat(path, "format.bmp");
		printf("Loading : %s\n", path);
		img = load_image(path);
		load_bwM(bwM, img);

		for (int j = 0; j < in_size; ++j)
		{
			inputs[i][j] = bwM->matrix[j];
		}
		if ((i + 1) % 62 == 0) {
			counter++;
			if (counter > 9) {
				counter = 0;
			}
		}

	}
	//NeuralNetwork *net = initNeurNet(data, 3);
	NeuralNetwork *net = load("networks/62x85_trained");

	printf("\r \r");

	int t = 1;
	while (t < 1000 && t < ite) {
		printf("Loop : %d\n", t);
		if (t % 100 == 0) {
			save(net, "networks/62x85_trained");
		}
		for (int i = 0; i < in_count; ++i) {
			for (int j = 0; j < in_size; ++j)
			{
				net->layArray[0].nArray[j].out = inputs[i][j];
			}
			onward(net);
			backwards(net, wonted[i]);
		}
		++t;
	}

	for (int i = 0; i < in_count; ++i) {
		for (int j = 0; j < in_size; ++j)
		{
			net->layArray[0].nArray[j].out = inputs[i][j];
		}
		onward(net);
		backwards(net, wonted[i]);
		float delta = net->lastNe->dErr;
		float out = net->lastNe->out;
		int wonted = 0;
		float max = 0;
		for (int z = 0; z < out_size; ++z) {
			float out = net->lastNe[z].out;
			if (out > max) {
				max = out;
				wonted = z;
			}
		}

		printf("IN[ %c ]  (%f) \t%f \tOUT[ %c ] %d\n",
				table[i % 62],
				delta,
				out,
				table[wonted],
				table[i % 62] == table[wonted]);
	}

	save(net, "networks/62x85_trained");
	bwMatrixFree(bwM);
	free(bwM);
}

void testXOR()
{
	printf("===== BEGIN XOR TEST =====\n");
	const int in_count = 4;
	const int in_size = 2;
	const int out_size = 1;

	int data[3] = { in_count, in_size, out_size };
	(void)(data);
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

	double *wonted = malloc(in_count * sizeof(double));
	wonted[0] = 0;
	wonted[1] = 1;
	wonted[2] = 1;
	wonted[3] = 0;

	NeuralNetwork *net = initNeurNet(data, 3);
	//NeuralNetwork *net = load("networks/XOR_trained");

	if (net != NULL)
	{
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
			workoutXOR(net, inputs, wonted, in_count, in_size);
		} while (net->lastNe->dErr > 0.1 || net->lastNe->dErr < -0.1);

		printf("\r \r");

		int i = 0;
		while (i < in_count) {
			int j = 0;
			while (j < in_size) {
				net->layArray[0].nArray[j].out = inputs[i][j];
				++j;
			}
			onward(net);
			backwards(net, &wonted[i]);
			int in_A = (int)net->layArray[0].nArray[0].out;
			int in_B = (int)net->layArray[0].nArray[1].out;
			float delta = net->lastNe->dErr;
			float out = net->lastNe->out;
			int wonted = out > 0.5;

			printf("IN[ %d , %d ] \t(%f) \t%f \tOUT[ %d ]\n",
					in_A,
					in_B,
					delta,
					out,
					wonted);
			++i;
		}
	}
	//save(net, "networks/XOR_trained");
	printf("===== END XOR TEST =====\n");
}

NeuralNetwork *initNeurNet(int nArray[], int layCount)
{
	NeuralNetwork *net = malloc(sizeof(NeuralNetwork));
	net->layCount = layCount;
	net->layArray = malloc(layCount * sizeof(Layer));

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

double workErr(Neuron *ne, double wonted)
{
	return wonted - ne->out;
}

void onward(NeuralNetwork *net)
{
	int i = 1;
	while (i < net->layCount) {
		workoutTotal(&net->layArray[i - 1], &net->layArray[i]);
		++i;
	}
}

void backwards(NeuralNetwork *net, double *wonted)
{
	int i = 0;
	while (i < net->lastCount) {
		net->lastNe[i].dErr =
			workErr(&net->lastNe[i], wonted[i]);
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
		double *wonted,
		int inputsCount, int inCount)
{
	int i = 0;
	while (i < inputsCount) {
		int j = 0;
		while (j < inCount) {
			net->layArray[0].nArray[j].out = inputs[i][j];
			++j;
		}
		onward(net);
		backwards(net, &wonted[i]);

		if (VERBOSE_TRAINXOR) {
			int in_A = (int)net->layArray[0].nArray[0].out;
			int in_B = (int)net->layArray[0].nArray[1].out;
			float delta = net->lastNe->dErr;
			float out = net->lastNe->out;
			int wonted = out > 0.5;

			printf("IN[ %d , %d ] \t(%f) \t%f \tOUT[ %d ]\n",
					in_A,
					in_B,
					delta,
					out,
					wonted);
		}
		++i;
	}
}
