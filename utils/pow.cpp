#include <iostream>
using namespace std;

int pow (int inp, int pow) { 
  // 'inp' stands for Input, 'pow' stands for power
  int out = 1; // 'out' stands for output. Output will be 1 to make sure it's start counting from input^1

  for (int i = 0; i < pow; i++) out *= inp; // Loop input calc until 'i' == 'pow'
  if (pow == 0) inp = 1; // If any number powered with 0, it will return 1

  return out;
}

int main () {
  cout << pow(5,2);
}