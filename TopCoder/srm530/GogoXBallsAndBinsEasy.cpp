#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class GogoXBallsAndBinsEasy {
public:
int solve(vector <int> T) {
    int ret = 0;
    vector<int> S(T);
    do {
        int t = 0;
        for(int i = 0; i < S.size(); i++) {
            if(T[i] - S[i] >= 0) t += T[i] - S[i];
        }
        ret = max(ret, t);
    } while(next_permutation(S.begin(), S.end()));

    return ret;
}



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
