#ifndef SomeFile_h
#define SomeFile_h
#include <iostream>
typedef float (*funcType)(float);
void printValues(float start, float step, float end, funcType functSolving);
#endif