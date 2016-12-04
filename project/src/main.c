/*
|
|	███╗   ███╗ █████╗ ██╗███╗   ██╗    ██████╗
|	████╗ ████║██╔══██╗██║████╗  ██║   ██╔════╝
|	██╔████╔██║███████║██║██╔██╗ ██║   ██║
|	██║╚██╔╝██║██╔══██║██║██║╚██╗██║   ██║
|	██║ ╚═╝ ██║██║  ██║██║██║ ╚████║██╗╚██████╗
|	╚═╝     ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝╚═╝ ╚═════╝
|
*/

#include "includes.h"
#include "bwMatrix.h"
//#include "quicktests.h"
#include "load_to_bw.h"
#include "rgbMatrix.h"
#include "neuralNetwork.h"

//const char usage[] =
//" <op> <filepath>\n"
//"\tOperators:\n"
//"\t\t0: Lines\n"
//"\t\t1: Chars\n";
/*
void tests(char testtodo)
{
	switch (testtodo) {
	case '!':
		printf("Hello World!\n");
		break;
	case '0':
		demoShowcase("./data/Lorem-ju.bmp", 0);
		break;
	case '1':
		demoShowcase("./data/Lorem-ju.bmp", 1);
		break;
	case 'F':
		//formatTrainingData(argv[2]);
		break;
	case 'X':
		testXOR();
		break;
	case 'B':
		printf("%s\n",convertToBwList());
		break;
	case 'L':
		workoutNetwork(10);
		break;
	default:
		errx(1, "No operations for : %s\n", testtodo);
		break;
	}
	fflush(stdout);

	//BLOC 2
	if (argc < 2)
		return 1;
	init_sdl();
	SDL_Surface* img = NULL;
	//SDL_Surface* screen = NULL;
	img = load_image(argv[1]);

	//INITIALISATION RGBMATRIX
	//rgbMatrix rgbM;
	//rgbInit(&rgbM,img->w,img->h);
	//printf("Size = %lu, %lu\n",rgbM.width,rgbM.height);

	//PRINTING RGB
	//load_rgbM(&rgbM,img);
	//rgbMprint(&rgbM);

	bwMatrix bwM;
	bwMatrixInit(&bwM, img->w, img->h);
	printf("Size = %lu, %lu\n", bwM.width, bwM.height);

	load_bwM(&bwM, img);
	bwMatrixPrintCompact(&bwM,Simple);
	bwMatrixPrintCompact(&bwM,Advanced);

	bwMatrix *new=bwMatrixResize(&bwM,bwM.width*1.25);

	bwMatrixPrintCompact(new,Simple);
	bwMatrixPrintCompact(new,Advanced);
	///

	//return 0;
}
*/


