#include"headfile.h"

 
int row;
int col;
int cells[X][Y];
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event;

int SDLwindow(int col1, int cow1)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return 1;
	}
	window = SDL_CreateWindow("Game of Life", 300, 300, cow1+1, col1+1, SDL_WINDOW_SHOWN);
	if (!window)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}
	return 0;
}
int readf()
{
	char acf[128];
	int y;
	int x;
	for (int i = 0; i < X; i++) {
		for (int k = 0; k < Y; k++) {
			cells[i][k] = 0;    /*0 means all cells are dead*/
		}
	}
	FILE* fp = NULL;
	fopen_s(&fp, "../file.txt", "r");
	if(!fp)
	{
		fprintf(stderr, "Error when opening file.txt\n");
		return 1;
	}
	if (fgets(acf, 128, fp) == NULL)
	{
		fprintf(stderr, "Error in reading: file.txt\n");
		return 1;
	}
	sscanf(acf, "%d %d", &row, &col);
	fgets(acf, 128, fp);
	while(feof(fp) == 0){
		sscanf(acf, "%d %d", &x, &y);
		cells[x][y] = 1;
		fgets(acf, 128, fp);
	}
	fclose(fp);  
	return 0;
}

int writef()
{
	FILE* fp = NULL;
	fopen_s(&fp, "../file.txt", "w");
	if (!fp)
	{
		return 1;
	}
	fprintf(fp, "%d %d\n", row, col);
	for (int i = 0; i < X; i++)
	{
		for (int k = 0; k < Y; k++)
		{
			if (cells[i][k] == 1) fprintf(fp, "%d %d\n", i, k);
		}
	}
	fclose(fp);
	return 0;
}


int living_neighbor(int x, int y)
{
	int nei = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int k = y - 1; k <= y + 1; k++)
		{
			if ((x >= 0) && (y >= 0) && x < X && y < Y && !(i == x && k == y))
			{
				if (cells[i][k] == 1) nei++;
			}
		}
	}
	return nei;
}

int up_cellstate()
{
	int nei[X][Y] = {0};
	for (int i = 0; i < X; i++)
	{
		for (int k = 0; k < Y; k++)
		{
			nei[i][k] = living_neighbor(i, k);
		}
	}
	for (int i = 0; i < X; i++)
	{
		for (int k = 0; k < Y; k++)
		{
			if (cells[i][k] == 1)
			{
				if (nei[i][k] <= 1 || nei[i][k] > 3) cells[i][k] = 0;
				else
				{
					if (nei[i][k] == 3 || nei[i][k] == 2) cells[i][k] = 1;
				}
			}
			else {
				if (nei[i][k] == 3) cells[i][k] = 1;
			}
		}
	}
	return 1;
}

void showup()
{
	for (int i = 0; i < X; i++) {
		for (int k = 0; k < Y; k++) {
			SDL_Rect rect = { 10 * k, 10 * i, 10 * (k + 1), 10 * (i + 1) };
			if(cells[i][k] == 0) SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);//dead cells use white
			else SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE); //live cells use black
			SDL_RenderFillRect(renderer, &rect);
		}
	}
	SDL_RenderPresent(renderer);
}

void quit()
{
	if (renderer) SDL_DestroyRenderer(renderer);
	if (window) SDL_DestroyWindow(window);
	SDL_Quit();
}
