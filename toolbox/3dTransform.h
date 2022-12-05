#include <vector>

std::vector<std::vector<float>> tMatrix (float tx, float ty, float tz);
std::vector<std::vector<float>> sMatrix (float sx, float sy, float tz);
std::vector<std::vector<float>> rxMatrix (float rad);
std::vector<std::vector<float>> ryMatrix (float rad);
std::vector<std::vector<float>> rzMatrix (float rad);

std::vector<std::vector<float>> worldToClip (std::vector<std::vector<float>>);
std::vector<std::vector<float>> clipToDisp (std::vector<std::vector<float>>);

void translate (float tx, float ty, float tz);
void scale (float sx, float sy, float sz);
void scale (float sx, float sy, float sz, float cx, float cy, float cz);
void rotateX(float rad);
void rotateY(float rad);
void rotateZ(float rad);

int inputLines (std::string filename);
void transform ();
void display (SDL_Renderer * r);
