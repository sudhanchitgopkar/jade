
#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../toolbox/line.h"

using namespace std;

int main() {
  SDL_Surface* s = NULL;
  SDL_Window * w = NULL;
  SDL_Renderer* r = NULL;
  
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << "Error initializing: " << SDL_GetError() << std::endl;
    return 1;
  } //if
  
  w = SDL_CreateWindow("Jade",
		       SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		       600, 600, SDL_WINDOW_SHOWN);
  if (!w) {
    std::cout << "Window creation error: " << SDL_GetError() << endl; 
    return 1;
  } //if

  r = SDL_CreateRenderer(w, -1, SDL_RENDERER_SOFTWARE); 
  s = SDL_GetWindowSurface(w);

  if (!s) {
    std::cout << "Surface creation error: " << SDL_GetError() << endl;
    return 1;
  } //if

  bool quit = false;                                      
  SDL_Event e;     

  int x1 = 300, y1 = 300, x2 = 300, y2 = 300, step = 10;
  int winwidth = 600, winheight = 600;
  SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
  SDL_SetRenderDrawBlendMode(r, SDL_BLENDMODE_BLEND);

  while (1) {

    switch(rand() % 4) {
    case 0:
      SDL_SetRenderDrawColor(r, 255, 0, 0, 25);
       if (x2 + step < winwidth) x2 += step;
      break;
    case 1:
      SDL_SetRenderDrawColor(r, 0, 255, 0, 25);
      if (x2 - step > 0) x2 -= step;
      break;
    case 2:
      SDL_SetRenderDrawColor(r, 255, 255, 255, 25);
      if (y2 + step < winheight) y2 += step;
      break;
    case 3:
      SDL_SetRenderDrawColor(r, 0, 255, 255, 25);
      if (y2 - step > 0) y2 -= step;
      break;
    } //switch

    line(r,x1,y1,x2,y2);
    SDL_RenderPresent(r);

    x1 = x2;
    y1 = y2;
    
    if (SDL_PollEvent(&e) && e.type == SDL_QUIT)
      break;
  } //while

  SDL_DestroyRenderer(r);
  SDL_DestroyWindow(w);
  SDL_Quit();
} //main
