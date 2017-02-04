/**********************************************************************************
Project 1, CSCE 557
Author: Eric Reeves
Last Modified: 1/28/2016

Functions in this file deal with translating a char to an int, and an int to a 
char.
*********************************************************************************/




/* int letterLookup(char)
    This function takes as an argument a char.  That char is then used as input
    to a switch, which finds a match and its corresponding integer value.  
    0 is equivalent to a, 1 to b, and so on.  The equivalent integer value is
    stored in the int variable 'result' and is returned.
    Input: char
    Output: int
*******************************************************************************/
int letterLookup(char letter) {
   int result;
   switch (letter) {
      case 'a': result = 0;
                break;
      case 'b': result = 1;
                break;
      case 'c': result = 2;
                break;
      case 'd': result = 3;
                break;
      case 'e': result = 4;
                break;
      case 'f': result = 5;
                break;
      case 'g': result = 6;
                break;
      case 'h': result = 7;
                break;
      case 'i': result = 8;
                break;
      case 'j': result = 9;
                break;
      case 'k': result = 10;
                break;
      case 'l': result = 11;
                break;
      case 'm': result = 12;
                break;
      case 'n': result = 13;
                break;
      case 'o': result = 14;
                break;
      case 'p': result = 15;
                break;
      case 'q': result = 16;
                break;
      case 'r': result = 17;
                break;
      case 's': result = 18;
                break;
      case 't': result = 19;
                break;
      case 'u': result = 20;
                break;
      case 'v': result = 21;
                break;
      case 'w': result = 22;
                break;
      case 'x': result = 23;
                break;
      case 'y': result = 24;
                break;
      case 'z': result = 25;
                break;
      default: result = 100;
               break;
   }
   return result;
}



/* char numLookup(int)
    This function takes as an argument an int.  That int is then used as input
    to a switch, which finds a match and its corresponding char value.  
    a is equivalent to 0, b to 1, and so on.  The equivalent char value is
    stored in the char variable 'result' and is returned.
    Input: int
    Output: char
*******************************************************************************/
char numLookup(int num) {
   char result;
   switch (num) {
      case 0: result = 'a';
                break;
      case 1: result = 'b';
                break;
      case 2: result = 'c';
                break;
      case 3: result = 'd';
                break;
      case 4: result = 'e';
                break;
      case 5: result = 'f';
                break;
      case 6: result = 'g';
                break;
      case 7: result = 'h';
                break;
      case 8: result = 'i';
                break;
      case 9: result = 'j';
                break;
      case 10: result = 'k';
                break;
      case 11: result = 'l';
                break;
      case 12: result = 'm';
                break;
      case 13: result = 'n';
                break;
      case 14: result = 'o';
                break;
      case 15: result = 'p';
                break;
      case 16: result = 'q';
                break;
      case 17: result = 'r';
                break;
      case 18: result = 's';
                break;
      case 19: result = 't';
                break;
      case 20: result = 'u';
                break;
      case 21: result = 'v';
                break;
      case 22: result = 'w';
                break;
      case 23: result = 'x';
                break;
      case 24: result = 'y';
                break;
      case 25: result = 'z';
                break;
      default: result = '@';
               break;
   }
   return result;
}