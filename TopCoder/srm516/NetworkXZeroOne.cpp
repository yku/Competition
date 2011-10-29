#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class NetworkXZeroOne {
public:
string reconstruct(string message) {
    const int len = message.size();
    bool f = false;
    string ret = "";
    string sub = "";

    for(int i = 0; i < len; i += 2) {
        sub = message.substr(i, 2);
        if(sub == "xo" or sub == "x?" or sub == "?o") {
            f = true;
            sub = "xo";
            break;
        }
        else if(sub == "ox" or sub == "o?" or sub == "?x") {
            f = true;
            sub = "ox";
            break;
        }
    }
   
    if(len & 1 && !f) {
        if(message[len - 1] == 'x') sub = "xo";
        else                        sub = "ox";
    }

    for(int i = 0; i < len / 2; i++) ret += sub;
    if(len & 1) ret += sub[0];

    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "x?x?"; string Arg1 = "xoxo"; verify_case(0, Arg1, reconstruct(Arg0)); }
	void test_case_1() { string Arg0 = "?xo?"; string Arg1 = "oxox"; verify_case(1, Arg1, reconstruct(Arg0)); }
	void test_case_2() { string Arg0 = "xo"; string Arg1 = "xo"; verify_case(2, Arg1, reconstruct(Arg0)); }
	void test_case_3() { string Arg0 = "o??x??o"; string Arg1 = "oxoxoxo"; verify_case(3, Arg1, reconstruct(Arg0)); }
	void test_case_4() { string Arg0 = "???????x"; string Arg1 = "oxoxoxox"; verify_case(4, Arg1, reconstruct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    NetworkXZeroOne ___test;
    ___test.run_test(-1);
}
// END CUT HERE
