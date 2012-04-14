#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class LeftOrRight {
public:
int maxDistance(string program) {
    int farthest, curr;
    farthest = curr = 0;
    for(int i = 0; i < program.length(); i++) {
        if(program[i] == 'L') curr--;
        else if(program[i] == 'R') curr++;
        else curr++;
        farthest = max(farthest, abs(curr));
    }
    curr = 0;
    for(int i = 0; i < program.length(); i++) {
        if(program[i] == 'L') curr--;
        else if(program[i] == 'R') curr++;
        else curr--;
        farthest = max(farthest, abs(curr));
    }
    return farthest;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLLRLRRR"; int Arg1 = 3; verify_case(0, Arg1, maxDistance(Arg0)); }
	void test_case_1() { string Arg0 = "R???L"; int Arg1 = 4; verify_case(1, Arg1, maxDistance(Arg0)); }
	void test_case_2() { string Arg0 = "??????"; int Arg1 = 6; verify_case(2, Arg1, maxDistance(Arg0)); }
	void test_case_3() { string Arg0 = "LL???RRRRRRR???"; int Arg1 = 11; verify_case(3, Arg1, maxDistance(Arg0)); }
	void test_case_4() { string Arg0 = "L?L?"; int Arg1 = 4; verify_case(4, Arg1, maxDistance(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    LeftOrRight ___test;
    ___test.run_test(-1);
}
// END CUT HERE
