#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#ifndef SEARCHSORTALGS_H
#define SEARCHSORTALGS_H

using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::srand;

void loadFiletoVect(ifstream &inFile, vector<int> &inpVect);
void genFile(int totNums, int zeroIndex, string fileName);
void vect2outFile(vector<int> &inpVect, string fileName);
int search(vector<int> &inpVect, int searchVal);
void bubbleSort(vector<int> &inpVect);
int binarySearch(vector<int> &inpVect, int searchVal);
#endif