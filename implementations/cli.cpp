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
#include <vector>
#include <string>
#include "../toolbox/line.h"
#include "../toolbox/2dTransform.h"

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
  SDL_SetRenderDrawColor(r, 0, 255, 0, 255);
  printMenu();
  char cmd;
  string file;
  float x,y,cx,cy,rad;

  //GENERAL ROTATION
  /*
  inputLines("implementations/lineInput/foo.txt");
  for (int i = 1; i <= 360; i++) {
    rotate((i * 0.017453), 300, 300);
    transform();
    display(r);
    rotate(-1 * (i * 0.017453), 300, 300);
    transform();
    outputLines("out.txt");
  } //for
  */

  //BASIC ROTATION
  /*
  inputLines("implementations/lineInput/bar.txt");
  for (int i = 1; i <= 360; i++) {
    rotate((i * 0.017453));
    transform();
    display(r);
    rotate(-1*(i * 0.017453));
    transform();
  } //for
  */

  //GENERAL SCALE
  /*
  inputLines("implementations/lineInput/square.txt");
  for (float i = 1; i > 0; i -= 0.01) {
    scale(i,i,300,300);
    transform();
    display(r);
  } //for
  */

  //BASIC SCALE
  /*
  inputLines("implementations/lineInput/square.txt");
  for (float i = 1; i > 0; i -= 0.01) {
    scale(i,i);
    transform();
    display(r);
  } //for
  */

  //GENERAL SCALE
  /*
  inputLines("implementations/lineInput/square.txt");
  for (float i = 0; i < 100; i++) {
    translate(5,5);
    transform();
    display(r);
  } //for
  */
  
  SDL_RenderPresent(r);
  while (1) {
    SDL_RenderPresent(r);
    cout << "user@jade$ ";
    cin >> cmd;
    try {
    if (cmd == 'h') {
      printMenu();
    } else if (cmd == 'q') {
      cout << "Goodbye!\n";
      return 0;
    } else if (cmd == 'a') {
      transform();
    } else if (cmd == 'i') {
      cin >> file;
      if (cin.fail()) throw "Invalid arguments";
      inputLines(file);
    } else if (cmd == 'o') {
      cin >> file;
      if (cin.fail()) throw "Invalid arguments";
      outputLines(file);
    } else if (cmd == 't') {
      cin >> x >> y;
      if (cin.fail()) throw "Invalid arguments";
      translate(x,y);
    } else if (cmd == 's') {
      cin >> x >> y;
      if (cin.fail()) throw "Invalid arguments";
      scale(x,y);
    } else if (cmd == 'S') {
      cin >> x >> y >> cx >> cy;
      if (cin.fail()) throw "Invalid arguments";
      scale(x,y,cx,cy);
    } else if (cmd == 'r') {
      cin >> rad;
      if (cin.fail()) throw "Invalid arguments";
      rotate(rad);
    } else if (cmd == 'R') {
      cin >> rad >> cx >> cy;
      if (cin.fail()) throw "Invalid arguments";
      rotate(rad,cx,cy);
    } else if (cmd == 'd') {
      display(r);
    } else if (cmd == 'c') {
      SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
      SDL_RenderClear(r);
      SDL_SetRenderDrawColor(r, 0, 255, 0, 255);
    } else {
      cout << "Command not recognized! Enter \'h\' for help.\n";
    } //if
    } catch (const char *  e) {
      cout << "Invalid arguments! Enter \'h\' for help.\n";
      cin.clear();
    }
    
    if (SDL_PollEvent(&e) && e.type == SDL_QUIT)
      break;
  } //while

  SDL_DestroyRenderer(r);
  SDL_DestroyWindow(w);
  SDL_Quit();
} //main
