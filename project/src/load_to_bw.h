
# ifndef LOAD_H_
# define LOAD_H_
 
# include <stdlib.h>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
# include <err.h>
# include "pixel_operations.h"


void wait_for_keypressed(void);
 
void init_sdl(void);

SDL_Surface* load_image(char *path);

SDL_Surface* display_image(SDL_Surface *img);


# endif

