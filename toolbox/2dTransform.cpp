#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "line.h"
#include "2dTransform.h"

using namespace std;

vector<vector<float>>  m  {
  {1,0,0},
  {0,1,0},
  {0,0,1}};

vector<vector<float>> points{{}};

int numLines = 0;

void printMenu () {
  cout <<
    "\n    __     ______     _____     ______    \n" <<
    "   /\\ \\   /\\  __ \\   /\\  __-.  /\\  ___\\\n" <<
    "  _\\_\\ \\  \\ \\  __ \\  \\ \\ \\/\\ \\ \\ \\  __\\\n" <<
    " /\\_____\\  \\ \\_\\ \\_\\  \\ \\____-  \\ \\_____\\\n" <<
    " \\/_____/   \\/_/\\/_/   \\/____/   \\/_____/\n" << 
    "\n-----------------------------------------------------------------\n" <<
    "TRANSLATE: t [x] [y]\n" <<
    "SCALE (BASIC): s [x],[y]\n" <<
    "SCALE (GENERAL): S [scale x] [scale y] [center x],[center y]\n" <<
    "ROTATE (BASIC): r [radians]\n" <<
    "ROTATE (GENERAL): R [radians] [center x] [center y]\n" <<
    "DISPLAY LINES: d\n" <<
    "CLEAR: c";
  cout << "\n-----------------------------------------------------------------\n" <<
    "INPUT FILE: i [filename]\n" <<
    "\tFILE STRUCTURE: \n\tline 1: number of lines in file\n" <<
    "\tlines 2 - end: [x1] [y1] [x2] [y2]\n" <<
    "OUTPUT FILE: o [filename]" <<
    "\n-----------------------------------------------------------------\n" <<
    "QUIT: q\n" <<
    "HELP: h" << 
    "\n-----------------------------------------------------------------\n\n";
} //printMenu

int inputLines (string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "File " << filename << " could not be opened! Check name + permissions.\n";
    return -1;
  }

  ifs >> numLines;
  if (--numLines <= 0) {
    cout << "USAGE: \n\tline 1: number of lines in file\n" <<
    "\tlines 2 - end: [x1] [y1] [x2] [y2]\n";
    return -1;
  } else {
    cout << numLines <<  " lines processed." << endl;
  }
  points.resize(2*numLines);
  points[0].resize(3);
  
  float x1,y1,count = 0;
    
  while (ifs >> x1 >> y1)
    points[count++] = {x1,y1,1};

  ifs.close();
  return numLines;
} //inputLines

vector<vector<float>> mult (vector<vector<float>> a, vector<vector<float>> b) {
  if (a.size() != 3 || a[0].size() != 3) cout << "Matrix A must be 3x3\n";
  if (b.size() != 3 || b[0].size() != 3) cout << "Matrix B must be 3x3\n";
    
  vector<vector<float>> prod {
    {0,0,0},
    {0,0,0},
    {0,0,0}};

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) 
      for (int k = 0; k < 3; k++) 
	prod[i][j]+=a[i][k]*b[k][j];

  return prod;
} //mult

vector<float> mult (vector<float> a, vector<vector<float>> b) {
  if (a.size() != 3) cout << "Matrix A must be 1x3\n";
  if (b.size() != 3 || b[0].size() != 3) cout << "Matrix B must be 3x3\n";

  vector<float> prod = {0,0,0};

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      prod[i] += a[j] * b[j][i];

  return prod;
} //mult

vector<vector<float>> tMatrix (float tx, float ty) {
  return vector<vector<float>> {
    {1,0,0},
    {0,1,0},
    {tx,ty,1}};
} //tMatrix

void translate (float tx, float ty) {
  m = mult(m,tMatrix(tx,ty));
} //translate

vector<vector<float>> sMatrix (float sx, float sy) {
  return vector<vector<float>> {
    {sx,0,0},
    {0,sy,0},
    {0,0,1}};
} //sMatrix

void scale (float sx, float sy) {
  cout << "Scaling by (" << sx << "," << sy << ")\n";
  m = mult(m,sMatrix(sx,sy));
} //scale

void scale (float sx, float sy, float cx, float cy) {
  cout << "Scaling by (" << sx << "," << sy << ") about (" << cx << "," << cy << ")\n";
  vector<vector<float>> temp {
    {1,0,0},
    {0,1,0},
    {0,0,1}};
  temp = mult(tMatrix(-1 * cx, -1 * cy), sMatrix(sx,sy));
  temp = mult(temp,tMatrix(cx,cy));
  m = mult(m,temp);
} //scale

vector<vector<float>> rMatrix (float rad) {
  return vector<vector<float>> {
    {cos(rad),-1 * sin(rad),0},
    {sin(rad),cos(rad),0},
    {0,0,1}};
} //rMatrix

void rotate (float rad) {
  cout << "Rotating by " << rad << "radians\n";
  m = mult(m,rMatrix(rad));
} //rotate

void rotate (float rad, float cx, float cy) {
  cout << "Rotating by " << rad << "radians about (" << cx << "," << cy << ")\n";  
  vector<vector<float>> temp {
    {1,0,0},
    {0,1,0},
    {0,0,1}};
  temp = mult(tMatrix(-1 * cx, -1 * cy), rMatrix(rad));
  temp = mult(temp, tMatrix(cx,cy));
  m = mult(m,temp);
} //rotate

void printMatrix(vector<vector<float>> v) {
  for (int i = 0; i < v.size(); i++)
    for (int j = 0; j < v[0].size(); j++)
      if (j == v[0].size()-1) cout << v[i][j] << endl;
      else cout << v[i][j] << "\t";
  cout << endl;
} //printMatrix

void transform () {
  cout << "Transformation Matrix:\n";
  printMatrix(m);

  for (int i = 0; i < numLines*2; i++)
    points[i] = mult(points[i],m);

  m = {
    {1,0,0},
    {0,1,0},
    {0,0,1}};
  
} //transform

void display(SDL_Renderer* r) {
  //printMatrix(points);
  for (int i = 0; i < numLines*2-1; i++)
    line(r, points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
} 

int outputLines (string filename) {
  ofstream out(filename);

  out << numLines + 1 << "\n";
  for (int i = 0; i < numLines*2-1; i++)
    out << points[i][0] << " " << points[i][1] << " " <<
      points[i+1][0] << " " << points[i+1][1] << "\n";

  out.close();
  return numLines;
} //outputLines
