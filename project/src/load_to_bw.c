

# include "load_to_bw.h"


void wait_for_keypressed(void) {
	SDL_Event             event;
	// Infinite loop, waiting for event
	for (;;) {
		// Take an event
		SDL_PollEvent(&event);
		// Switch on event type
		switch (event.type) {
			// Someone pressed a key -> leave the function
		case SDL_KEYDOWN: return;
		default: break;
		}
		// Loop until we got the expected event
	}
}

void init_sdl(void) {
	// Init only the video part
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		// If it fails, die with an error message
		errx(1, "Could not initialize SDL: %s.\n", SDL_GetError());
	}
	// We don't really need a function for that ...
}

SDL_Surface* load_image(char *path) {
	SDL_Surface          *img;
	// Load an image using SDL_image with format detection
	img = IMG_Load(path);
	if (!img)
		// If it fails, die with an error message
		errx(3, "can't load %s: %s\n", path, IMG_GetError());
	return img;
}

SDL_Surface* display_image(SDL_Surface *img) {
	SDL_Surface          *screen;
	// Set the window to the same size as the image
	screen = SDL_SetVideoMode(img->w, img->h, 0, SDL_SWSURFACE | SDL_ANYFORMAT);
	if (screen == NULL) {
		// error management
		errx(1, "Couldn't set %dx%d video mode: %s\n",
			img->w, img->h, SDL_GetError());
	}

	/* Blit onto the screen surface */
	if (SDL_BlitSurface(img, NULL, screen, NULL) < 0)
		warnx("BlitSurface error: %s\n", SDL_GetError());

	// Update the screen
	SDL_UpdateRect(screen, 0, 0, img->w, img->h);

	// wait for a key
	wait_for_keypressed();

	// return the screen for further uses
	return screen;
}

/*int main(int argc, char *argv[])
{
  if(argc < 2)
	return 1;
  init_sdl();
  SDL_Surface* img = NULL;
  //SDL_Surface* screen = NULL;
  img = load_image(argv[1]);

  for (int i = 0; i < img->w; i++)
  {
	for (int j = 0; j < img->h; j++)
	{
	  Uint32 pixel = getpixel(img,i,j);
	  Uint8 r = 0;
	  Uint8 g = 0;
	  Uint8 b = 0;
	  SDL_GetRGB(pixel, img->format, &r, &g, &b);
	  float res = (float)r * 0.3 +(float)b * 0.11 +(float)g * 0.59;
	  if (res < 128)
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
}*/


