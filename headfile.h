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
int SDLwindow(int col1, int cow1);

int readf();

int writef();

int living_neighbor(int x, int y);

int up_cellstate();

void showup();

void quit();
