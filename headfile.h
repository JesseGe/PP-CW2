#pragma once
#include<stdio.h>
#include<string.h>
#include<SDL.h>
#include<stdbool.h>
#include <stdlib.h>
#define X 500
#define Y 500

extern int cells[X][Y];
extern int row;
extern int col;
Uint32 tickspcycle;
char *rfile;
char *wfile;
int SDLwindow(int row1, int col1);

int readf(char*file);

int writef(char*file);

int living_neighbor(int x, int y);

int up_cellstate();

void showup();

void quit();

int ui();