#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class LargestSubsequence {
public:
string getLargest(string s) {
    return solve(s);
}

string solve(string s) {
    if(s == "") return "";

    int idx  = 0;
    for(int i = 0; i < s.size(); i++) 
        if(s[i] > s[idx]) idx = i;
    return s[idx] + solve(s.substr(idx + 1));

}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "test"; string Arg1 = "tt"; verify_case(0, Arg1, getLargest(Arg0)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "a"; verify_case(1, Arg1, getLargest(Arg0)); }
	void test_case_2() { string Arg0 = "example"; string Arg1 = "xple"; verify_case(2, Arg1, getLargest(Arg0)); }
	void test_case_3() { string Arg0 = "aquickbrownfoxjumpsoverthelazydog"; string Arg1 = "zyog"; verify_case(3, Arg1, getLargest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    LargestSubsequence ___test;
    ___test.run_test(-1);
}
// END CUT HERE
