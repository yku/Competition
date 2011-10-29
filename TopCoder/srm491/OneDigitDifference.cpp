#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

class OneDigitDifference {
public:
int getSmallest(int N) {
    int digits;
    int ret = N;
    stringstream ss;
    string str;
  
    ss << N;
    str = ss.str();

    digits = str.length();
    if ( N == 0 ) return 1;
    for(int i = 0; i < digits; i++) {
        string str2(str, 0, str.length());
        str2[i] = '0';
        ret = min(ret, atoi(str2.c_str()));
    }
    return ret;
}

int min(int x, int y) {
    if (x > y) {
        return y;
    } else {
        return x;
    }
}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
