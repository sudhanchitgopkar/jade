#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../toolbox/line.h"

using namespace std;


int main(int argc, char** argv) {
  int SCREEN_HEIGHT = 600;
  int SCREEN_WIDTH = 600;
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

  SDL_SetRenderDrawColor(r,0,255,0,255);
  int MAX_LINES = 1000, count = 0;
  if (argc > 2)
    std::cout << "USAGE: ./run [LINES TO DRAW]\nDefault: 1000 lines\n";
  if (argc == 2) MAX_LINES = atoi(argv[1]);
  std::cout << "Drawing: " << MAX_LINES << " lines\n";
  clock_t t;
  t = clock();
  while (1) {
    bresLine(r,rand()%600,rand()%600,rand()%600,rand()%600);
    SDL_RenderPresent(r);
    if (count++ >= MAX_LINES) {
      t = clock() - t;
      double time_taken = ((double)t)/CLOCKS_PER_SEC;
      std::cout << time_taken << " seconds taken" << endl;
      break;
    }
    if (SDL_PollEvent(&e) && e.type == SDL_QUIT) break;
  } //while
  
  SDL_DestroyRenderer(r);
  SDL_DestroyWindow(w);
  SDL_Quit();
} //main
