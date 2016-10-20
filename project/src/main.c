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

//TODO : Maybe make a big includes.h folder ?

#include "includes.h"
#include "bwMatrix.h"
#include "quicktests.h"
#include "load_to_bw.h"
#include "rgbMatrix.h"


int main(int argc, char* argv[])
{

	// SVP, ne pushez pas de main non commenté avant que l'interface soit là, cela permet à chacun de tester ses functions indépendamment
	// Voici un exemple de bloc de commentaire modulaire :

	// Enlevez ou ajoutez un '/' devant pour décommenter / commenter votre bloc
	//			//*/ -> //*/	Non commenté
	//			/*/	 -> //*/	Commenté

	//*/ BLOC 0 - Used to remove warning when testing without args
	UNUSED(argc);
	UNUSED(argv);
	//*/

	//*/ BLOC 1 - Used for quicktests
	//TestbndBoxList();
	//TestTreatment0();
	//TestCut();
	//*/

	//*/BLOC 2
	if (argc < 2)
		return 1;
	init_sdl();
	SDL_Surface* img = NULL;
	//SDL_Surface* screen = NULL;
	img = load_image(argv[1]);

	//rgbMatrix rgbM;
	//rgbInit(&rgbM,img->w,img->h);
	//printf("Size = %d, %d\n",rgbM.width,rgbM.height);

	bwMatrix bwM;
	bwMatrixInit(&bwM, img->w, img->h);
	printf("Size = %lu, %lu\n", bwM.width, bwM.height);


	//load_rgbM(&rgbM,img);
	//rgbMprint(&rgbM);

	load_bwM(&bwM, img);
	bwMprint(&bwM);
	//*/

	return 0;
}
