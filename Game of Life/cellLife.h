#include <iostream>
#ifndef RCOSBY_CELLLIFE_H
#define RCOSBY_CELLLIFE_H
using std::cout;
using std::endl;
void addOscillator(int x, int y, char(&currentBoard)[42][100]);
void addGlider(int x, int y, char (&currentBoard)[42][100]);
void addGliderGun(int x, int y, char(&currentBoard)[42][100]);
void shiftCoordinates(int* x, int* y);
void conway(char(&currentBoard)[42][100], char(&futureBoard)[42][100]);
#endif