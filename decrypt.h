/**************************
Project 1, CSCE 557
Author: Eric Reeves
Last Modified: 1/25/2016

Header file for decrypt.cpp
*************************/



#ifndef DECRYPT_H
#define DECRYPT_H


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "printVector.h"
#include "translateLetters.h"

using namespace std;

void decrypt(vector<char> &key, vector<char> &ciphertext);
char subNumLookup(int letterNum, int key);

#endif // DECRYPT_H