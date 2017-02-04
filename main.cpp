/**********************************************************************************
Project 1, CSCE 557
Author: Eric Reeves
Last Modified: 1/25/2016

This program reads in a .txt file of ciphertext (given in the command line), and
outputs the decrypted plaintext.  The program will print out the ciphertext,
and the salient portions of each step of the decryption: finding the key-length,
finding the component letters of the key, and using the key to decrypt the message.

Input: .txt file containing the ciphertext
Output: only a log in the command window

**********************************************************************************/

#include "main.h"

int main (int argc, char* argv[]) {
   // Check for correct number of command line arguments
   if (argc < 2) {
      cout << "Please include the file to be read in!" << endl;
      return 1;
   }

   int numChar = 0;
   int keylength;
   char letter;
   string fileName;
   vector<char> ciphertext;
   vector<char> keyLetters;

   // get the filename from command line
   fileName = argv[1];
   
   // Open file
   Scanner inStream;
   cout << "Opening input file." << fileName  << endl;
   inStream.openFile(fileName);
   cout << "Input file opened." << endl;

   // Add each character from file to ciphertext vector, removing newlines and spaces
   while(inStream.hasMoreData()) {
      letter = inStream.nextChar();
      if (letter == '\n' || letter == ' ') {
         continue;
      }
      ciphertext.push_back(letter);
      numChar++;
   }

   // Close the input stream
   inStream.close();

   cout << "There are " << numChar << " characters in this file." <<endl;
   printVector(ciphertext);

   // find the keylength
   keylength = findKeyLength(ciphertext);
   cout << "The keylength is: " << keylength << endl;

   // find the letters of the key
   keyLetters = findKeyLetter(keylength, ciphertext);
   cout << "The key is: ";
   printVector(keyLetters);

   // decrypt the message using the key
   decrypt(keyLetters, ciphertext);

   // quit
   return 0;
}