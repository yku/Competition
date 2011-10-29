#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

class PalindromizationDiv2 {
public:
bool isP(string s) {
    int i, j;
    for(i = 0, j = s.size() - 1; i < j; i++, j--)
        if(s[i] != s[j]) return false;
    return true;
}
    
int getMinimumCost(int X) {
    for(int i = 0; ; i++) {
        stringstream ss1;
        stringstream ss2;
        ss1 << X + i;
        ss2 << X - i;

        if(isP(ss1.str())) {
            return i;
        }
        if(X - i >= 0 and isP(ss2.str())) {
            return i;
        }
    }
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 25; int Arg1 = 3; verify_case(0, Arg1, getMinimumCost(Arg0)); }
	void test_case_1() { int Arg0 = 12321; int Arg1 = 0; verify_case(1, Arg1, getMinimumCost(Arg0)); }
	void test_case_2() { int Arg0 = 40; int Arg1 = 4; verify_case(2, Arg1, getMinimumCost(Arg0)); }
	void test_case_3() { int Arg0 = 2011; int Arg1 = 9; verify_case(3, Arg1, getMinimumCost(Arg0)); }
	void test_case_4() { int Arg0 = 12345; int Arg1 = 24; verify_case(4, Arg1, getMinimumCost(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PalindromizationDiv2 ___test;
    ___test.run_test(-1);
}
// END CUT HERE
