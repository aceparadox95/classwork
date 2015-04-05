#include <iostream>
#ifndef RCOSBY_HELPERS_H
#define RCOSBY_HELPERS_H
using std::cout;
using std::endl;
using std::string;
void shiftCoordinates(int* x, int* y);
bool checkvalidCoordinates(string userCommand, int x,int y);
void printBoard(char (&currentBoard)[42][100]);
void prepBoard(char(&currentBoard)[42][100]);
void transferBoard(char (&currentBoard)[42][100], char (&futureBoard)[42][100]);
#endif