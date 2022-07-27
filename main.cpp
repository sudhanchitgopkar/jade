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
#include <math.h>
#include "../toolbox/line.h"
#include "../toolbox/3dTransform.h"

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
		       1000, 1000, SDL_WINDOW_SHOWN);
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

  int x = 0, y = 0;
  int count = 0;
  bool flag = false;
  SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
  inputLines("cubeback.txt");
  display(r);
  SDL_RenderPresent(r);
  rotateY(-0.1);
  while (1) {
    SDL_Delay(10);
    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
    SDL_RenderClear(r);
    SDL_SetRenderDrawColor(r, 255, 0, 0, 255);

    /* ROTATION TESTING */
    //rotateX((rand() % 10) * 0.005);
    //rotateY((rand() % 10) * 0.005);
    //rotateZ((rand() % 10) * 0.005);
    //rotateX(0.005);
    if (flag)
      rotateY(-0.007);
    else
      rotateY(0.007);

    if (count++ % 50 == 0) {
      if (flag) flag = false;
      else flag = true;
    } //if
    
    // rotateZ(0.005);
    
    
    /* SCALING TESTING */
    //scale(1.01,1,1);
    //scale(1,1.01,1);
    //scale(1,1,1.01);
    //scale(0.999,0.999,0.9991);
    
    
    /* TRANSLATE TESTING */
    /*
    translate(0.01,0,0);
    translate(0,0.01,0);
    translate(0,-.01,-.01);
    */
    transform();
    display(r);
    SDL_RenderPresent(r);
  
    if (SDL_PollEvent(&e) && e.type == SDL_QUIT)
      break;

  } //while
  
  SDL_DestroyRenderer(r);
  SDL_DestroyWindow(w);
  SDL_Quit();
} //main
