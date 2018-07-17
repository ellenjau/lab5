#include <string>
#include <vector>
#include <iostream>
#include "practice.h"

using namespace std;

ostream& operator << (ostream& out, HugeInt& x) {
    for (int i=0; i<x.vec.size(); ++i) {
        out<<x.vec[x.vec.size()-1-i];
    }
    return out;
}

istream& operator >> (istream& in, HugeInt& x) {
    int hugeint;
    int single;
    in >> hugeint;
    while(hugeint>0) {
        single = hugeint%10;
        x.vec.push_back(single);
        hugeint = hugeint/10;
    }
    return in;
}

HugeInt HugeInt::operator + (HugeInt x) {
    HugeInt single;
    int total=0;
    int rest=0;
    int length;
    if(x.vec.size()>=vec.size()) {
        length=x.vec.size();
    } else {
        length=vec.size();
    }

    vector<int> v1(length);
    vector<int> v2(length);

    v1=vec;
    v2=x.vec;

    for(int i=0; i<length; ++i) {
        total = v1[i]+v2[i]+rest;
        if(total>=10) {
            rest=1;
            total-=10;
        } else {
            rest=0;
        }
        single.vec.push_back(total);
    }
    if(rest==1) {
        single.vec.push_back(1);
    }
    return single;
}

HugeInt HugeInt::operator-(HugeInt x) {
    int diff=0;
    int rest=0;
    int length;
    HugeInt single;
    if(x.vec.size()>=vec.size()) {
        length=x.vec.size();
    } else {
        length=vec.size();
    }
    vector<int> v1(length);
    vector<int> v2(length);

    v1=vec;
    v2=x.vec;
    for(int i=0; i<length; ++i) {
        diff=v1[i]-v2[i];
        if(diff<0) {
            v1[i+1]--;
            diff=v1[i]+10-v2[i];
        }
        single.vec.push_back(diff);
    }
    return single;
}


HugeInt::HugeInt() {
}

HugeInt::HugeInt(int i) {
    int single;
    while(i>0) {
        single=i%10;
        vec.push_back(single);
        i=i/10;
    }

}

HugeInt::HugeInt(string s) {
    for (int i=0; i< s.length(); ++i) {
        vec.push_back(s.at((s.length())-1-i));
    }
}

