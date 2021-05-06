#include"headfile.h"
SDL_Event event;
int main(int argc, char* argv[])
{
	
	Uint32 lastup = 0;
	int Delay = 100;
	int check = 0;
	int checkreturn = 0;
	int paused = 0;
	checkreturn = ui();
	switch (checkreturn)
	{
	case -1: return 0;
		break;
	case 0: SDLwindow(row, col);
		showup();
		while (check == 0)
		{
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					check = 1; /*the game is over*/
				}
				else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
					bool Keydown = event.type == SDL_KEYDOWN;
					if (event.key.keysym.sym == SDLK_SPACE) {
						paused = Keydown ^ paused;
						break;
					}
					if (event.key.keysym.sym == SDLK_UP)
					{
						if (tickspcycle > 100) tickspcycle -= 50;
						break;
					}
					if (event.key.keysym.sym == SDLK_DOWN)
					{
						if (tickspcycle < 5000) tickspcycle += 50;
						break;
					}
				}
			}

			if (paused == 0 && ((SDL_GetTicks() - lastup) >= tickspcycle))
			{
				up_cellstate();
				showup();
				lastup = SDL_GetTicks();
			}
		}
		writef(wfile);
		quit();
		return 0;
		break;
	default: 
		SDLwindow(row, col);
		showup();
		int checkturn = 0;
		while (check == 0)
		{
			if (checkturn == checkreturn && paused == 0)
			{
				bool rt = 1;
				paused = rt ^ paused;
			}
			while (SDL_PollEvent(&event)) 
			{
				if (event.type == SDL_QUIT) {
					check = 1; /*the game is over*/
				}
				else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
					bool Keydown = event.type == SDL_KEYDOWN;
					if (event.key.keysym.sym == SDLK_SPACE) {
						paused = Keydown ^ paused;
						break;
					}
					
					if (event.key.keysym.sym == SDLK_UP)
					{
						if (tickspcycle > 100) tickspcycle -= 50;
						break;
					}
					if (event.key.keysym.sym == SDLK_DOWN)
					{
						if (tickspcycle < 5000) tickspcycle += 50;
						break;
					}
				}
			}
			
			if (paused == 0 && ((SDL_GetTicks() - lastup) >= tickspcycle))
			{
				up_cellstate();
				showup();
				lastup = SDL_GetTicks();
				checkturn++;
			}
			
		}
		writef(wfile);
		quit();
		return 0;
	}
	return 0;
}