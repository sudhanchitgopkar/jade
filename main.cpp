/*
  @file main.cpp

  THIS IS A TEMPLATE FOR YOUR IMPLEMENTATION USING JADE.
  COMPILE THIS FILE WITH MAKE JADE.
  
  @author: Sudhan Chitgopkar
  @contact: hi@sudhan.dev
*/

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
		       600, 600, SDL_WINDOW_SHOWN); //Set window name, attributes
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
  SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
  
  while (1) {
    
    /*
      YOUR IMPLEMENTATION HERE!
    */
    
    SDL_RenderPresent(r);
    
    if (SDL_PollEvent(&e) && e.type == SDL_QUIT)
      break;
  } //while

  SDL_DestroyRenderer(r);
  SDL_DestroyWindow(w);
  SDL_Quit();
} //main
