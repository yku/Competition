#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class AnagramFree {
public:
int getMaximumSubset(vector <string> S) {
    int i, j;
    vector<string> v;
    int ret = 0;

    for(i = 0; i < S.size(); i++) {
       string s = S[i];
       sort(s.begin(), s.end());
       v.push_back(s);
    }

    for(i = 0; i < v.size(); i++) {
        bool flag = true;
        for(j = i + 1; j < v.size(); j++) {
            if(v[i] == v[j]) flag = false;
        }
        if(flag) ret++;
    }
    return ret;
}
};
