#include <iostream>
using namespace std;

int main() {

  cout << "Enter a letter: ";
  char letter;
  cin >> letter;
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
   cout << "Letter " << letter << " equals " << result << endl;
}