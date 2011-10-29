#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

class NetworkXMessageRecovery {
public:
string recover(vector <string> messages) {
    set<char> s;
    string ret = "";
    for(int i = 0; i < messages.size(); i++) {
        string str = messages[i];
        for(int j = 0; j < str.size(); j++) {
            s.insert(str[j]);
        }
    }
    set<char>::iterator it = s.begin();
    while(it != s.end()) {
        ret += *it;
        it++;
    }

    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"acd", "bce"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abcde"; verify_case(0, Arg1, recover(Arg0)); }
	void test_case_1() { string Arr0[] = {"ed", "dc", "cb", "ba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "edcba"; verify_case(1, Arg1, recover(Arg0)); }
	void test_case_2() { string Arr0[] = {"Fox", "Ciel", "FoxCiel"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "FoxCiel"; verify_case(2, Arg1, recover(Arg0)); }
	void test_case_3() { string Arr0[] = {"a", "A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Aa"; verify_case(3, Arg1, recover(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    NetworkXMessageRecovery ___test;
    ___test.run_test(-1);
}
// END CUT HERE
