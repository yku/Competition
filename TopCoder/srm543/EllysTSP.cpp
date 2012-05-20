#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class EllysTSP {
public:
int getMax(string places) {
    int c, v, ret;
    c = v = 0;
    ret = 1;
    for(int i = 0; i < places.size(); i++) {
        if(places[i] == 'C') c++;
        else                 v++;
    }
    char current;
    if(c > v) current = 'C';
    else      current = 'V';
    while(c > 0 && v > 0) {
        if(current == 'C') {
            c--;
            current = 'V';
        }else{
            v--;
            current = 'C';
        }
        ret++;
    }
    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "CVVVC"; int Arg1 = 5; verify_case(0, Arg1, getMax(Arg0)); }
	void test_case_1() { string Arg0 = "VVV"; int Arg1 = 1; verify_case(1, Arg1, getMax(Arg0)); }
	void test_case_2() { string Arg0 = "VVVVCVV"; int Arg1 = 3; verify_case(2, Arg1, getMax(Arg0)); }
	void test_case_3() { string Arg0 = "CVCVCVC"; int Arg1 = 7; verify_case(3, Arg1, getMax(Arg0)); }
	void test_case_4() { string Arg0 = "V"; int Arg1 = 1; verify_case(4, Arg1, getMax(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    EllysTSP ___test;
    ___test.run_test(-1);
}
// END CUT HERE
