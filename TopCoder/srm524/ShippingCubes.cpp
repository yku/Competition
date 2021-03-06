#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class ShippingCubes {
public:
int minimalCost(int N) {
    int ret = 1 << 30;
    for(int i=1; i <= N; i++) {
        for(int j=1; j <= N; j++) {
            for(int k=1; k <= N; k++) {
                if(i*j*k == N) {
                    ret = min(ret, i+j+k);
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
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; verify_case(0, Arg1, minimalCost(Arg0)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 6; verify_case(1, Arg1, minimalCost(Arg0)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 9; verify_case(2, Arg1, minimalCost(Arg0)); }
	void test_case_3() { int Arg0 = 200; int Arg1 = 18; verify_case(3, Arg1, minimalCost(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ShippingCubes ___test;
    ___test.run_test(-1);
}
// END CUT HERE
