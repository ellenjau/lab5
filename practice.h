#ifndef PRACTICE_H
#define PRACTICE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HugeInt {
    friend ostream &operator << (ostream& out, HugeInt& x);
    friend istream &operator >> (istream& in, HugeInt& x);
   
  public:
    HugeInt();
    HugeInt(int i);
    HugeInt(string s);
	HugeInt operator + (HugeInt x);
	HugeInt operator - (HugeInt x); 

  private:
    vector<int> vec;
};
#endif
