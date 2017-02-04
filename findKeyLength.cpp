/**********************************************************************************
Project 1, CSCE 557
Author: Eric Reeves
Last Modified: 1/27/2016

Functions in this file are associated with finding the length of the key using
analysis of the ciphertext.  

* findKeyLength() compares two copies of the ciphertext, each time looking for
matches ("coincidences") in letter pairs between the two copies. After shifting
and comparing a number of times, the offset which results in the largest number 
of coincidenes is likely to be equal to the length of the key.  

* offsetTheArray() shifts the vector by one element.  A '#' is added to the 
beginning to signify blank space, and the last element is dropped.
*********************************************************************************/

#include "findKeyLength.h"

/* int findKeyLength(vector<char>) 
   This function takes as input a vector<char> containing the ciphertext.
   Another vector of the same size as the input vector is first initialized - 
   this will be the copy of the input vector used for comparison of the two.  
   First, the second vector is offset by one element, and then all elements
   are compared between the two vectors with matches ("coincidences") being 
   counted.  After shifting for a certain number of times, the shift which 
   resulted in the largest number of coincidences is said to equal the
   key length.  This number, offset, is returned.
   The number of shifts performed is largely aribtrary, and depends on the 
   eventual length of the key.  Any number of shifts that is similar to the
   keylength will likely result in a correct value, while if too many shifts
   are performed the result will likely be a multiple of the true length.
   Here, 10 shifts is chosen as a good starting point, and is likely
   to dectect most medium-length or less keys.
   Input: vector<char>
   Output: int
*******************************************************************************/
int findKeyLength(vector<char> &characters) {
  vector<char> offsetArray;
  int coincidences=0;
  int highestCoincidense=0;
  int offset=0;

// Initialize empty offset vector
  for(int i=0; i<characters.size(); i++) {
   offsetArray.push_back(characters[i]);
  }

  // for each offset of vector from 1 to 10, 10 because any larger starts
  // getting multiples of key.  If key is suspected to be longer, increase
  // this limit.
  for(int i=1; i<10; i++) {
   offsetArray = offsetTheArray(offsetArray);

   // cycle through entirety of both vectors, comparing each character 
   // if they match, increment coincidences
   for(int j=0;j<characters.size();j++){
      if(characters[j]==offsetArray[j]) {
         coincidences++;
      }
   } 
   cout << "coincidences for offset of " << i << ": " << coincidences << endl;

   // save the highest coincidence count, and the offset number
   if(coincidences>highestCoincidense){
        highestCoincidense=coincidences;
        offset=i; 
   }
   // reset coincidences for each offset pass
   coincidences=0;
  }
  return offset;
}



/* vector<char> offsetTheArray(vector<char>)
   This function takes in a <char> vector as input, and 
   appends a '#' to the beginning of the vector, and 
   removes the last element, effectively "shifting" the 
   vector down by one element.  The once-shifted vector
   is returned.
   Input: vector<char>
   Output: vector<char>
************************************************************************/
vector<char> offsetTheArray(vector<char> &array) {
   vector<char>::iterator it;

   it = array.begin();
   array.insert (it, '#');
   array.pop_back();

   return array;
}
