#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class TwiceString {
public:
string getShortest(string s) {
    string ret = s + s;
    const int len = s.size();

    for(int i = 1; i < len; i++) {
        string sub = s.substr(0, len - i);
        if(s.substr(i) == sub) { ret = s + s.substr(len - i); break; }
    }

    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; string Arg1 = "ababa"; verify_case(0, Arg1, getShortest(Arg0)); }
	void test_case_1() { string Arg0 = "xxxxx"; string Arg1 = "xxxxxx"; verify_case(1, Arg1, getShortest(Arg0)); }
	void test_case_2() { string Arg0 = "topcoder"; string Arg1 = "topcodertopcoder"; verify_case(2, Arg1, getShortest(Arg0)); }
	void test_case_3() { string Arg0 = "abracadabra"; string Arg1 = "abracadabracadabra"; verify_case(3, Arg1, getShortest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TwiceString ___test;
    ___test.run_test(-1);
}
// END CUT HERE
