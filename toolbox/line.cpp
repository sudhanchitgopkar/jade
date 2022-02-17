#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>
#include "line.h"

void putPixel (SDL_Renderer* ren, int x, int y) {
  SDL_RenderDrawPoint(ren, x, y);
} //putPixel

void bresLine (SDL_Renderer* ren, int x1, int y1, int x2, int y2) {

  
  int dx = x2 - x1,dy = y2 - y1,dx1 = fabs(dx),dy1 = fabs(dy);
  int px = 2 * dy1 - dx1,py = 2 * dx1 - dy1;
  int x,y,xe,ye,i;

  if(dy1 <= dx1) {
    if(dx >= 0) {
      x=x1;
      y=y1;
      xe=x2; 
    } else {
      x=x2;
      y=y2;
      xe=x1;
    } //if
    putPixel(ren,x,y);
    for(i=0;x++<xe;i++) {
      if(px<0)
	px=px+2*dy1;
      else {
	if((dx<0 && dy<0) || (dx>0 && dy>0))
	  y++;
	else
	  y--;
	px=px+2*(dy1-dx1);
      } //if
      putPixel(ren,x,y);
    } //for
  } else {
    if(dy>=0) {
      x=x1;
      y=y1;
      ye=y2;
    } else {
      x=x2;
      y=y2;
      ye=y1;
    } //if
    putPixel(ren,x,y);
    for(i=0;y<ye;i++) {
      y=y+1;
      if(py<=0)
	py=py+2*dx1;
      else {
	if((dx<0 && dy<0) || (dx>0 && dy>0)) {
	  x=x+1;
	} else {
	  x=x-1;
	} //if
	py=py+2*(dx1-dy1);
      } //else
      putPixel(ren,x,y);
    } //for
  } //else
} //bresLine

void line (SDL_Renderer* s, int x1, int y1, int x2, int y2) {

  float x1f = (float) x1, x2f = (float) x2;
  float y1f = (float) y1, y2f = (float) y2;

  if (x1 == x2 && y1 == y2) { //point
    putPixel(s,x1,y1);
  } else if (x1 == x2 && y1 < y2) { //vertical
    while (y1 < y2)
      putPixel(s,x1,y1++);
  } else if (x1 == x2) { //vertical
    while(y2 < y1)
      putPixel(s,x1,y2++);
  } else if (y1 == y2 && x1 < x2) { //horizontal
    while (x1 < x2)
      putPixel(s,x1++,y1);
  } else if (y1 == y2) { //horizontal
    while (x2 < x1)
      putPixel(s,x2++,y1);
  } else if (x2-x1 > y2-y1 && x1 < x2 && y1 < y2) { //<45,up
    float yinc = (y2f-y1f)/(x2f-x1f);
    int dx = x2-x1;
    for (int i = 0; i < dx; i++) {
      y1f += yinc;
      putPixel(s,++x1,floor(y1f));
    } //for
  } else if (x1-x2 > y1-y2 && x1 > x2 && y1 > y2) { //<45,up
    float yinc = (y1f-y2f)/(x1f-x2f);
    int dx = x1 - x2;
    for (int i = 0; i < dx; i++) {
      y2f += yinc;
      putPixel(s,++x2,floor(y2f));
    } //for
  } else if (x2-x1 > y1-y2 && x1 < x2 && y1 > y2) { //<45,down
    float yinc = (y1f-y2f)/(x2f-x1f);
    int dx = x2 - x1;
    for (int i = 0; i < dx; i++) {
      y1f -= yinc;
      putPixel(s,++x1,floor(y1f));
    } //for
  } else if (x1-x2 > y2-y1 && x1 > x2 && y1 < y2) { //<45,down
    float yinc = (y2f-y1f)/(x1f-x2f);
    int dx = x1 - x2;
    for (int i = 0; i < dx; i++) {
      y1f += yinc;
      putPixel(s,--x1,floor(y1f));
    } //for
  } else if (x2-x1 < y2-y1 && x1 < x2 && y1 < y2) { //>45,up
    float xinc = (x2f-x1f)/(y2f-y1f);
    int dy = y2 - y1;
    for (int i = 0; i < dy; i++) {
      x1f += xinc;
      putPixel(s,floor(x1f),++y1);
    } //for
  } else if (x1-x2 < y1-y2 && x1 > x2 && y1 > y2) { //>45,up
    float xinc = (x1f-x2f)/(y1f-y2f);
    int dy = y1-y2;
    for	(int i = 0; i < dy; i++) {
      x1f -= xinc;
      putPixel(s,floor(x1f),--y1);
    } //for
  } else if (x2-x1 < y1-y2 && x1 < x2 && y1 > y2) { //>45,down
    float xinc = (x2f-x1f)/(y1f-y2f);
    int dy = y1-y2;
    for	(int i = 0; i < dy; i++) {
      x1f += xinc;
      putPixel(s,floor(x1f),--y1);
    } //for
  } else if (x1-x2 < y2-y1 && x1 > x2 && y1 < y2) { //>45,down
    float xinc = (x1f-x2f)/(y2f-y1f);
    int dy = y2-y1;
    for	(int i = 0; i < dy; i++) {
      x1f -= xinc;
      putPixel(s,floor(x1f),++y1);
    } //for
  } else if (x1 < x2 && y1 < y2) { //diag
    while (x1 < x2)
      putPixel(s,++x1,++y1);
  } else if (x1 > x2 && y1 > y2) { //diag
    while (x2 < x1)
      putPixel(s,--x1,--y1);
  } else if (x1 < x2 && y1 > y2) { //diag
    while (x1 < x2)
      putPixel(s,++x1,--y1);
  } else if (x1 > x2 && y1 < y2) { //diag
    while (x1 > x2)
      putPixel(s,--x1,++y1);
  } else {
    std::cout << "Line type not recognized!\n";
  } //if
} //line
