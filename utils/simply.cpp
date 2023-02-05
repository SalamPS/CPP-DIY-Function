#include <iostream>
using namespace std;

int pow (int inp, int pow) { 
  // 'inp' stands for Input, 'pow' stands for power
  int out = 1; // 'out' stands for output. Output will be 1 to make sure it's start counting from input^1

  if (pow == 0) out = 1; // If any number powered with 0, it will return 1
  else for (int i = 0; i < pow; i++) out *= inp; // Loop input calc until 'i' == 'pow'

  return out;
}

// String to Int Convertor
int st_in (string inp) {  // 'inp' stands for Input
  int out = 0;            // 'out' stands for Output

  for (int i = inp.length(), ind = 0; i > 0; i--, ind++) {
    // ASCII converted from char of 'inp', then pushed into 'out'
    out += (inp[ind]-48)*pow(10,i-1);
  }
  return out;
}

// Int to String Convertor
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

// Main Program
string simply (string inp) {

  // (A / B)
  string  up_st = "", // 'up_st' stands for A in string
          lo_st = "", // 'lo_st' stands for B in string
            out = inp;// 'out' stands for Output
  int        sw = 0,  // 'sw' stands for Switch
          up_in = 0,  // 'up_in' stands for A in int
          lo_in = 0,  // 'lo_in' stands for B in int
          small;      // 'small' stands for smallest number

  for(int i = 0; i < inp.length(); i++) {
    if (inp[i] == 47) sw = 1; // if current == '/', switch side
    if (inp[i] != 47 && sw == 0) up_st += inp[i]; // Fill A (string)
    if (inp[i] != 47 && sw == 1) lo_st += inp[i]; // Fill B (string)
  }

  up_in = st_in(up_st); // Turn A into int
  lo_in = st_in(lo_st); // Turn B into int

  // Choose which one smaller
  if (up_in < lo_in) small = up_in;
  else small = lo_in;

  for (int i = small; i > 0; i--) {
    // Find for Greatest Common Divisor
    if (up_in % i == 0 && lo_in % i == 0) { 
      up_in = up_in/i;
      lo_in = lo_in/i;
    }
  }
  
  up_st = in_st(up_in); // Turn A into string
  lo_st = in_st(lo_in); // Turn B into string
  
  if (up_in != 0 && lo_in != 0) { // Validated if output is not 0
    if(up_in % lo_in == 0) out = in_st(up_in/lo_in); // 'lo_in' is divider factor of 'up_in'
    else                  out = up_st + "/" + lo_st; // 'lo_in' is not divider factor of 'up_in'
  }

  return out;
}

int main () {
  cout << simply("4/2");
  cout << "\n";
  cout << simply("10/4");
}