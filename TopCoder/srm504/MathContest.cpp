#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class MathContest {
public:
int countBlack(string ballSequence, int repetitions) {
    vector<char> stack;
    int ret = 0;

    for(int i = 0; i < repetitions; i++) {
        for(int j = 0; j < ballSequence.length(); j++) {
            stack.push_back(ballSequence[j]);
        }
    }

    int idx = 0;
    int top = 0;
    int bottom = stack.size() - 1;
    bool reversed = false;
    while(top <= bottom) {
        char color = stack[idx];
        if(color == 'W') {
            // reverse
            if(reversed) {
                top++;
                idx = top;
                reversed = false;
            } else {
                idx = bottom;
                bottom--;
                reversed = true;
            }
        } else if(color == 'B') {
            ret++;
            // invert
            if(reversed) {
                idx = bottom;
                bottom--;
                for(int i = idx; i >= top; i--) {
                    if(stack[i] == 'B') stack[i] = 'W';
                    else if(stack[i] == 'W') stack[i] = 'B';
                }
            } else {
                top++;
                idx = top;
                for(int i = idx; i <= bottom; i++) {
                    if(stack[i] == 'B') stack[i] = 'W';
                    else if(stack[i] == 'W') stack[i] = 'B';
                }
            }
        }
    }
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BBWWB"; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BBB"; int Arg1 = 10; int Arg2 = 1; verify_case(1, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "BW"; int Arg1 = 10; int Arg2 = 20; verify_case(2, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "WWWWWWWBWWWWWWWWWWWWWW"; int Arg1 = 1; int Arg2 = 2; verify_case(3, Arg2, countBlack(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MathContest ___test;
    ___test.run_test(-1);
}
// END CUT HERE
