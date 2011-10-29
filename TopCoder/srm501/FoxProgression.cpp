#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class FoxProgression {
public:
int theCount(vector <int> seq) {
    int ret = 0;
    int a, g;
    a = g = 0;
    int last_idx = seq.size() - 1;
    if(seq.size() <= 1) return -1;

    if(isArithmetic(seq)) {
        a = seq[last_idx] + (seq[1] - seq[0]); 
        ret++;
    }
    if(isGeometric(seq)) {
        g = seq[last_idx] * (seq[1] / seq[0]);    
        ret++; 
    }

    if(ret != 0 && a == g) ret--;
    return ret;
}

bool isArithmetic(vector<int> seq) {
    int prev, diff;
    
    prev = seq[1] - seq[0];
    for(int i = 2; i < seq.size(); i++) {
        diff = seq[i] - seq[i-1];
        if(prev != diff) return false;
        prev = diff;
    }
    
    return true;
}

bool isGeometric(vector<int> seq) {
    double prev, diff, mod;

    prev = seq[1] / seq[0];
    mod = seq[1] % seq[0];
    for(int i = 2; i < seq.size(); i++) {
        diff = seq[i] / seq[i-1];
        if(prev != diff || mod != 0) return false;
        prev = diff;
        mod = seq[i] % seq[i-1];
    }
    return true;
}
};

