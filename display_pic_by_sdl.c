#include "SDL/SDL.h"

int main(int argc,char *argv[])
{
	SDL_Surface *hello = NULL;
	SDL_Surface *screen = NULL;
	SDL_Init(SDL_INIT_EVERYTHING);

	screen = SDL_SetVideoMode(480,208,32,SDL_SWSURFACE);
	hello = SDL_LoadBMP("hello.bmp");
	SDL_BlitSurface(hello,NULL,screen,NULL);

	SDL_Flip(screen);
	SDL_Delay(5000);
	SDL_FreeSurface(hello);

	SDL_Quit();
	return 0;
}	
