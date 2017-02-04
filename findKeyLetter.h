/**************************
Project 1, CSCE 557
Author: Eric Reeves
Last Modified: 1/25/2016

Header file for findKeyLetter.cpp
*************************/



#ifndef  FINDKEYLETTER_H
#define FINDKEYLETTER_H

#include <iostream>
#include <vector>
#include <string>
#include "printVector.h"
#include "translateLetters.h"
using namespace std;

vector<char> findKeyLetter(int, vector<char> &characters);
float dotProduct(vector<float> standard, vector<float> letterCount);
vector<float> shiftVector (vector<float> &letterCount);
int innerSum(vector<float> &letterCount);

const int ALPHABETSIZE = 26;
#endif // FINDKEYLETTER_H