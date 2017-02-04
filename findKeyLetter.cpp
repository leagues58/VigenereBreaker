/**********************************************************************************
Project 1, CSCE 557
Author: Eric Reeves
Last Modified: 1/25/2016

Functions in this file deal with finding the individual letters of the key.
The bulk of the work takes place in 'findKeyLetter()' and there are several
helper functions which perform simple arithmetic on vectors of ints.  

*********************************************************************************/
#include "findKeyLetter.h"

/* vector<char> findKeyLetter(int keyLength, vector<char> &characters)
    This function takes as an argument an integer for the keylength, as well as 
    a vector<char>, which contains the ciphertext.  The function first initializes
    several vectors it will later use, including a vector with the standard letter
    freqeuncies in English.  Next, for each letter of the key, a vector is created
    that contains every i-th letter of the ciphertext, where i is the keylength.
    This is because each i-th letter will have been shifted by the same amount
    during the encryption process.  The frequencies of each letter for each 
    vector is calculated, and then the dot product is taken of that vector of 
    frequencies and the vector of standard English frequencies.  This dot product
    is calculated 25 times, each time shifting the ciphertext frequency vector by one.
    The shift which yields the largest dot product is probably the one that those
    letters had been shifted by in the encryption process.  This shift amount is
    saved in a vector.  This entire process is repeated for as many times as the
    input keylength.  Upon completion of this loop, we now have a vector<int>
    containing the shift number for each element in the key.  This is then 
    translated into characters, which are saved in a vector<char>.  This vector is
    returned.
    Input: int, vector<char>
    Output: vector<char> 
*******************************************************************************/

vector<char> findKeyLetter(int keyLength, vector<char> &characters) {

   int letterNum;
   vector<float> letterCount;
   vector<char> keyLetters;
   vector<int> keyNumbers;
   float tempDotProduct;
   float maxDotProduct=0;
   int letterCountSum;
   int shiftCount;

   // Initialize letterCount vector
   for(int i=0; i<ALPHABETSIZE; i++) {
      letterCount.push_back(0);
   }

   // Initialize keyLetters vector
   for(int i=0; i<keyLength; i++) {
      keyLetters.push_back(' ');
   }

   // Initialize keyNumbers vector
   for(int i=0; i<keyLength; i++) {
      keyNumbers.push_back(0);
   }   

   // Add standard letter frequencies to standardLetterFreq vector
   vector<float> standardLetterFreq;
   standardLetterFreq.push_back(.0812); // A
   standardLetterFreq.push_back(.0149); // B
   standardLetterFreq.push_back(.0271); // C
   standardLetterFreq.push_back(.0432); // D
   standardLetterFreq.push_back(.1202); // E
   standardLetterFreq.push_back(.0230); // F
   standardLetterFreq.push_back(.0203); // G
   standardLetterFreq.push_back(.0592); // H
   standardLetterFreq.push_back(.0731); // I
   standardLetterFreq.push_back(.0010); // J
   standardLetterFreq.push_back(.0069); // K
   standardLetterFreq.push_back(.0398); // L
   standardLetterFreq.push_back(.0261); // M
   standardLetterFreq.push_back(.0695); // N
   standardLetterFreq.push_back(.0768); // O
   standardLetterFreq.push_back(.0182); // P
   standardLetterFreq.push_back(.0011); // Q 
   standardLetterFreq.push_back(.0602); // R
   standardLetterFreq.push_back(.0628); // S
   standardLetterFreq.push_back(.0910); // T
   standardLetterFreq.push_back(.0288); // U
   standardLetterFreq.push_back(.0111); // V
   standardLetterFreq.push_back(.0209); // W
   standardLetterFreq.push_back(.0017); // X
   standardLetterFreq.push_back(.0211); // Y
   standardLetterFreq.push_back(.0007); // Z


   // The business.
   for (int i=0; i<keyLength; i++) {  // for each letter in the key
      cout << endl << endl;
      cout << "*********Pass " << i+1 << " ***********" << endl; // i+1 because it looks better in the printout
      cout << "Characters: ";

      // finding the i-th letters of each pass.  So pass 0 get letters 0, 0+keylength, 0+2*keylength...
      for(int j=i; j<characters.size(); j=j+keyLength) {
         cout << characters[j] << " ";
         letterNum = letterLookup(characters[j]);
         letterCount[letterNum]++; 
      }

      printVector(letterCount); 

      letterCountSum = innerSum(letterCount);
      cout << "LETTERCOUNT SIZE: " << letterCountSum << endl;

      for(int k=0; k<ALPHABETSIZE; k++) {
         letterCount[k]=letterCount[k]/letterCountSum; // Divide to get individual letter frequencies
      }

      cout << "LETTER FREQ: ";
      printVector(letterCount);

      // for all 25 shifts, calculate dot product of standard frequencies 
      // and frequencies of ciphertext vector
      for(int l=0; l<ALPHABETSIZE; l++) {
         tempDotProduct = dotProduct(standardLetterFreq, letterCount);
   
         // check if largest dot product.  Save if so
         if(tempDotProduct>maxDotProduct) {
            maxDotProduct = tempDotProduct;
            shiftCount = l;
         }
         letterCount = shiftVector(letterCount);
      }
      // Clear out letterCount for next pass
      for(int m=0; m<ALPHABETSIZE; m++) {
         letterCount[m] = 0;
      }

      cout << "MAX DOT PRODUCT: " << maxDotProduct << " at shift count: " << shiftCount << endl;

      // Assign newly-found key number to keyNumber vector and clear out tempDotProduct
      // and maxDotProduct for future use
      keyNumbers[i] = shiftCount;
      tempDotProduct = 0;
      maxDotProduct = 0;
   }

   // Convert key numbers to letters
   for(int n=0; n<keyLength; n++) {
      keyLetters[n] = numLookup(keyNumbers[n]);
   }
   return keyLetters;
}





/* float dotProduct(vector<float> standard, vector<float> letterCount)
    This function takes as an argument two vector<float>'s and computes the
    dot product of these two vectors.  As these are 1 by n vectors, the dot
    product will always be a single value, here called 'sum', which is returned.
    Input: vector<float>, vector<float>
    Output: float
*******************************************************************************/
float dotProduct(vector<float> standard, vector<float> letterCount) {
   float sum=0;
   for(int i=0;i<standard.size(); i++) {
      sum+=standard[i]*letterCount[i];
   }
   return sum;
}



/* vector<float> shiftVector (vector<float> &letterCount)
    This function takes as an argument a vector<float>.  The function
    effectively shifts the vector elements down by one, circular buffer-style,
    so that the previously last element is now the first.  The shifted vector
    is then returned.
    Input: vector<float>
    Output: vector<float>
*******************************************************************************/
vector<float> shiftVector (vector<float> &letterCount){
   float first = letterCount[0];
   for(int i=0; i<ALPHABETSIZE;i++) {
      letterCount[i] = letterCount[i+1];
   }
   letterCount[25] = first;
   return letterCount;
}



/* int innerSum(vector<float> &letterCount)
    This function takes as an argument a vector<float> and adds all the elements
    contained within.  This sum, called 'sum', is returned.
    Input: vector<float>
    Output: int
*******************************************************************************/
int innerSum(vector<float> &letterCount) {
   int sum=0;
   for(int i=0; i<letterCount.size(); i++) {
      sum+=letterCount[i];
   }
   return sum;
}






