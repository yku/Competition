#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class SimpleGuess {
public:
int getMaximum(vector <int> hints) {
    int len = hints.size();
    int x, y;
    int ret = 0;

    sort(hints.begin(), hints.end());
    for(int i = 0; i < len; i++) {
        for(int j = i+1; j < len; j++) {
            if((hints[j] + hints[i]) % 2 != 0) continue;
            x = (hints[j] + hints[i]) / 2;
            y = (hints[j] - hints[i]) / 2;
            ret = max(ret, x * y);
        }
    }
    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 4, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, getMaximum(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 4, 5, 8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(1, Arg1, getMaximum(Arg0)); }
	void test_case_2() { int Arr0[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(2, Arg1, getMaximum(Arg0)); }
	void test_case_3() { int Arr0[] = { 2, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2499; verify_case(3, Arg1, getMaximum(Arg0)); }
	void test_case_4() { int Arr0[] = { 50, 58, 47, 57, 40 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 441; verify_case(4, Arg1, getMaximum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SimpleGuess ___test;
    ___test.run_test(-1);
}
// END CUT HERE
