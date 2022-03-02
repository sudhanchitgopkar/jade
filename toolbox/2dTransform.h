#include <vector>

int inputLines (std::string filename);
void transform ();
void display ();
int outputLines (std::string filename);
void printMatrix(std::vector<std::vector<float>> v);

std::vector<std::vector<float>> translate (float tx, float ty);
std::vector<std::vector<float>> scale (float sx, float sy);
std::vector<std::vector<float>> scale (float sx, float sy, float cx, float cy);
std::vector<std::vector<float>> rotate (float rad);
std::vector<std::vector<float>> rotate (float rad, float cx, float cy); 
  
 
