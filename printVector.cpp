/**********************************************************************************
Project 1, CSCE 557
Author: Eric Reeves
Last Modified: 1/25/2016


This file contains an overloaded printVector() function.  The function takes
any of three types of vector: <char>, <float>, or <int> and will print
that vector to standard output.
* Optional output statements of vector type and size are commented out, but 
can be added.
Input: vector<char>
Output: None/text to standard out
*********************************************************************************/

#include "printVector.h"

void printVector(vector<char> &characters) {
   //cout << "Character vector: " << endl;
   for(int i = 0; i<characters.size(); i++) {
      cout << characters[i];
   }
   cout << endl;
   cout << endl;
   //cout << "Vector length: " << characters.size() << endl;
}

void printVector(vector<float> &characters) {
   //cout << "Float vector: " << endl;
   for(int i = 0; i<characters.size(); i++) {
      cout << characters[i] << " ";
   }
   cout << endl;
   //cout << "Vector length: " << characters.size() << endl;
}

void printVector(vector<int> &characters) {
   //cout << "Int vector: " << endl;
   for(int i = 0; i<characters.size(); i++) {
      cout << characters[i] << " ";
   }
   cout << endl;
   cout << endl;
   //cout << "Vector length: " << characters.size() << endl;
}