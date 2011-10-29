#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class NinePuzzle {
public:
int getMinimumCost(string init, string goal) {
		
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BG*YRGRRYR" ; string Arg1 = "BGGY*YRRRR" ; int Arg2 = 0; verify_case(0, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "GBBB*BGBBG" ; string Arg1 = "RYYY*YRYYR"; int Arg2 = 9; verify_case(1, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "RRBR*BRBBB" ; string Arg1 = "BBRB*RBRRR" ; int Arg2 = 1; verify_case(2, Arg2, getMinimumCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    NinePuzzle ___test;
    ___test.run_test(-1);
}
// END CUT HERE
