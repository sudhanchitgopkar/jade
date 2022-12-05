#include <vector>

//private:
std::vector<std::vector<float>> tMatrix (float tx, float ty);
std::vector<std::vector<float>> sMatrix (float sx, float sy);
std::vector<std::vector<float>> rMatrix (float rad);
std::vector<float> mult (std::vector<float> a, std::vector<std::vector<float>> b);
std::vector<std::vector<float>> mult (std::vector<std::vector<float>> a, std::vector<std::vector<float>> b);
void printMatrix(std::vector<std::vector<float>> v);

//public:
int inputLines (std::string filename);
void transform ();
void display (SDL_Renderer * r);
int outputLines (std::string filename);
void printMenu();

void translate (float tx, float ty);
void scale (float sx, float sy);
void scale (float sx, float sy, float cx, float cy);
void rotate (float rad);
void rotate (float rad, float cx, float cy); 
/*
std::vector<std::vector<float>> translate (float tx, float ty);
std::vector<std::vector<float>> scale (float sx, float sy);
std::vector<std::vector<float>> scale (float sx, float sy, float cx, float cy);
std::vector<std::vector<float>> rotate (float rad);
std::vector<std::vector<float>> rotate (float rad, float cx, float cy); 
*/
