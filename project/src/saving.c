#include "saving.h"

void save(NeuralNetwork *net, char path[])
{
	FILE* fichier = fopen(path, "w");

	if (fichier == NULL)
	{
		printf("*** ERROR *** Cannot create file !\n");
	}
	else
	{
		for (int i = 0; i < net->layCount; i++)
		{
			fprintf(fichier, "L");
			for (int j = 0; j < net->layArray[i].nCount; j++)
			{
				fprintf(fichier, "N");
				for (int k = 0; k < net->layArray[i].nArray[j].sCount; k++)
				{
					fprintf(fichier,
						"S%f",
						net->layArray[i].nArray[j].synArray[k]);
				}
			}
		}
		fclose(fichier);
	}
}

NeuralNetwork *load(char path[])
{
	FILE *fichier = fopen(path, "r");

	if (fichier == NULL)
	{
		printf("*** ERROR *** File doesn't exist !\n");
		return NULL;
	}

	int currentChar = 0;
	int nCount = 0;
	int layer_th = 0;
	int *tab = NULL;

	int sCount = 0;
	double *synArray = NULL;
	currentChar = fgetc(fichier);
	do
	{
		if (currentChar == 'L')
		{
			tab = realloc(tab, (layer_th + 1) * sizeof(int));
			if (layer_th != 0)
			{
				tab[layer_th - 1] = nCount;
				nCount = 0;
			}
			layer_th++;
			currentChar = fgetc(fichier);
		}
		else if (currentChar == 'N')
		{
			nCount++;
			currentChar = fgetc(fichier);
		}
		else if (currentChar == 'S')
		{
			if (synArray == NULL)
			{
				synArray = malloc(sizeof(double));
			}
			else
			{
				synArray = realloc(synArray, (sCount + 1) * sizeof(double));
			}

			currentChar = fgetc(fichier);

			if (currentChar == '-')
			{
				char tab[10] = "";
				currentChar = fseek(fichier, -1, SEEK_CUR);
				char* z = fgets(tab, 10, fichier);
				(void)(z);
				synArray[sCount] = atof(tab);
			}
			else
			{
				char tab[9] = "";
				currentChar = fseek(fichier, -1, SEEK_CUR);
				char* z = fgets(tab, 9, fichier);
				(void)(z);
				synArray[sCount] = atof(tab);
			}
			sCount++;
		}
		else
		{
			currentChar = fgetc(fichier);
		}

		if (currentChar == EOF)
			tab[layer_th - 1] = nCount;
	} while (currentChar != EOF);

	NeuralNetwork *net = initNeurNet(tab, layer_th);
	sCount = 0;

	for (int i = 1; i < net->layCount; i++)
		for (int j = 0; j < net->layArray[i].nCount; j++)
			for (int k = 0; k < net->layArray[i].nArray[j].sCount; k++)
			{
				net->layArray[i].nArray[j].synArray[k] = synArray[sCount];
				sCount++;
			}

	fclose(fichier);

	return net;
}
