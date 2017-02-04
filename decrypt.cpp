/**********************************************************************************
Project 1, CSCE 557
Author: Eric Reeves
Last Modified: 1/25/2016

File containing functions necessary to decrypt the ciphertext: decrypt() and 
subNumLookup().  

*********************************************************************************/

#include "decrypt.h"

/*  void decrypt(vector<char>, vector<char>)
   This function decrypts the ciphertext.  It takes each character of ciphertext,
   and subtracts from it the amount of its corresponding key value.  The subtraction
   is done using the function subNumLookup.  Once the plaintext character is 
   obtained, it is added to the plaintext vector.  Upon completion of all characters,
   the vector is printed.
   Input: vector<char>, vector<char>
   Output: none
**********************************************************************************/
void decrypt(vector<char> &key, vector<char> &ciphertext) {
   int letterNum;
   char plainChar;
   vector<int> keyNum;
   vector<char> plaintext;

   // Convert the letters in the key to numbers
   for(int i=0; i<key.size(); i++) {
      keyNum.push_back(letterLookup(key[i]));
   }

   // Convert each ciphertext letter to its number and subtract the key value
   for(int i=0; i<ciphertext.size(); i++) {
      letterNum = letterLookup(ciphertext[i]);
      plainChar = subNumLookup(letterNum, keyNum[i%keyNum.size()]);
      plaintext.push_back(plainChar);
   }
   printVector(plaintext);
}


/* char subNum Lookup(int, int)
   This function takes two ints as inputs: the ciphertext character 
   (its numerical value) and the corresponding key value (its numerical value)
   and subtracts the two, yielding the numerical value of the plaintext
   letter.  This number is modulo-divided by 26, to ensure that the value 
   remains within the 0-25 possible values of the alphabet.  In C++, this
   modulo-division can result in a regative number, so if the result is 
   negative, the absolute value of this number must be subtracted from 26.
   This will result in the correct shift from the end of the alphabet.  
   The function then looks up the character that corresponds to the calculated
   number, and returns it.  
   Input: int, int
   Output: char
****************************************************************************/
char subNumLookup(int letterNum, int key) {
   char result;

   // subtraction of ciphertext char - key value
   letterNum = (letterNum-key)%26;
   if(letterNum<0) {
      letterNum = abs(letterNum);
      letterNum = 26-letterNum;
   }
   
   // find the resulting char
   result = numLookup(letterNum);

   return result;
}



