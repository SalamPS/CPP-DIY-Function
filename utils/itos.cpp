#include <iostream>
using namespace std;

int pow (int inp, int pow) { 
  // 'inp' stands for Input, 'pow' stands for power
  int out = 1; // 'out' stands for output. Output will be 1 to make sure it's start counting from input^1

  if (pow == 0) out = 1; // If any number powered with 0, it will return 1
  else for (int i = 0; i < pow; i++) out *= inp; // Loop input calc until 'i' == 'pow'

  return out;
}

string in_st (int inp) {  // 'inp' stands for Input
  string out = "";        // 'out' stands for Output
  int    ind = 0;         // 'ind' stands for Writing Index

  for (int i = 1; i <= 11; i++) {
    // Find out the numbers entered in units, tens, hundreds, ...
    if ((inp / pow(10,i)) == 0) {ind = i-1; break;}
  }

  for (int i = ind; i >= 0; i--) {
    out += (inp/pow(10,i))+48; // ASCII conversion, then push into 'out'
    inp -= (inp/pow(10,i))*pow(10,i); // Known input decreased by the taken number
  }

  return out;
}

int main () {
  cout << in_st(55);
}