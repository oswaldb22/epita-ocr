#include "saving.h"

void save(NeuralNetwork *net, char path[])
{
	FILE* file = fopen(path, "w");
	printf("Writing to : %s\n", path);

	if (!file)
	{
		printf("*** ERROR *** Cannot create file !\n");
	}
	else
	{
		for (int i = 0; i < net->layCount; i++)
		{
			fprintf(file, "L");
			for (int j = 0; j < net->layArray[i].nCount; j++)
			{
				fprintf(file, "N");
				for (int k = 0; k < net->layArray[i].nArray[j].sCount; k++)
				{
					fprintf(file,
						"S%f",
						net->layArray[i].nArray[j].synArray[k]);
				}
			}
		}
		fclose(file);
	}
}

NeuralNetwork *load(char path[])
{
	FILE *file = fopen(path, "r");
	printf("Loading from : %s\n", path);

	if (file == NULL)
	{
		printf("*** ERROR *** File doesn't exist !\n");
		return NULL;
	}

	int curChar = 0;
	int nCount = 0;
	int layIterator = 0;
	int *tab = NULL;

	int sCount = 0;
	double *synArray = NULL;
	curChar = fgetc(file);
	do
	{
		if (curChar == 'L')
		{
			tab = realloc(tab, (layIterator + 1) * sizeof(int));
			if (layIterator != 0)
			{
				tab[layIterator - 1] = nCount;
				nCount = 0;
			}
			layIterator++;
			curChar = fgetc(file);
		}
		else if (curChar == 'N')
		{
			nCount++;
			curChar = fgetc(file);
		}
		else if (curChar == 'S')
		{
			if (synArray == NULL)
			{
				synArray = malloc(sizeof(double));
			}
			else
			{
				synArray = realloc(synArray, (sCount + 1) * sizeof(double));
			}

			curChar = fgetc(file);

			if (curChar == '-')
			{
				char tab[10] = "";
				curChar = fseek(file, -1, SEEK_CUR);
				char* z = fgets(tab, 10, file);
				(void)(z);
				synArray[sCount] = atof(tab);
			}
			else
			{
				char tab[9] = "";
				curChar = fseek(file, -1, SEEK_CUR);
				char* z = fgets(tab, 9, file);
				(void)(z);
				synArray[sCount] = atof(tab);
			}
			sCount++;
		}
		else
		{
			curChar = fgetc(file);
		}

		if (curChar == EOF)
			tab[layIterator - 1] = nCount;
	} while (curChar != EOF);

	NeuralNetwork *net = initNeurNet(tab, layIterator);
	sCount = 0;

	for (int i = 1; i < net->layCount; i++)
		for (int j = 0; j < net->layArray[i].nCount; j++)
			for (int k = 0; k < net->layArray[i].nArray[j].sCount; k++)
			{
				net->layArray[i].nArray[j].synArray[k] = synArray[sCount];
				sCount++;
			}

	fclose(file);

	return net;
}
