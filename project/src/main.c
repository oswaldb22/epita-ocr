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


int main(int argc,  char* argv[])
{
	/*printf("\nHello World\n\n");

	UNUSED(argc);
	UNUSED(argv);

	//Testbw0();
	*/


  if(argc < 2)
  return 1;
  init_sdl();
  SDL_Surface* img = NULL;
  //SDL_Surface* screen = NULL;
  img = load_image(argv[1]);
  
  rgbMatrix rgbM;
  rgbInit(&rgbM,img->w,img->h);
  printf("Size = %d, %d\n",rgbM.width,rgbM.height);
  
  //load_rgbM(&rgbM,img);

  load_rgbM(&rgbM,img);
   rgbMprint(&rgbM);
 





  /*for (int i = 0; i < img->w; i++)
  {
    for (int j = 0; j < img->h; j++)
    {
      Uint32 pixel = getpixel(img,i,j);
      Uint8 r = 0;
      Uint8 g = 0;
      Uint8 b = 0;
      SDL_GetRGB(pixel, img->format, &r, &g, &b);
      float res = (float)r * 0.3 +(float)b * 0.11 +(float)g * 0.59;
      if (res < 150)
          res = 0;
      else 
          res = 255;
      Uint32 grey = SDL_MapRGB(img->format, res, res, res);
      putpixel (img, i, j, grey);
    }
  }
  // test fonctionnement treshold
  display_image(img); // a enlever
  //wait_for_keypressed();

*/

	return 0;
}
