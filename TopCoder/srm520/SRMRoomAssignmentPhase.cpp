#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class SRMRoomAssignmentPhase {
public:
int countCompetitors(vector <int> ratings, int K) {
    const int me = ratings[0]; 
    int myroom = 0;
    int ret = 0;
    sort(ratings.begin(), ratings.end(), greater<int>());
    for(int i = 0; i < ratings.size(); i++) {
        int room = (i + 1) % K;
        if(me == ratings[i]) { myroom = room; break; }
    }

    for(int i = 0; i < ratings.size(); i++) {
        if(myroom == (i + 1) % K) {
            if(ratings[i] == me) break;
            ret++;
        }
    }

    return ret;
}

};

// BEGIN CUT HERE
int main() {
    SRMRoomAssignmentPhase ___test;
    ___test.run_test(-1);
}
// END CUT HERE
