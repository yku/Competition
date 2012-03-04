#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

class LeastMajorityMultiple {
public:
int leastMajorityMultiple(int a, int b, int c, int d, int e) {
    int ret = 0;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);
    sort(v.begin(), v.end());

    for(int i = 1; i <= 100*100*100; i++) {
        int res = 0;
        for(int j = 0; j < v.size(); j++) {
            if(i % v[j] == 0) res++;
        }
        if(res >= 3) { ret = i; break; }
    }
    
    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 3; int Arg3 = 4; int Arg4 = 5; int Arg5 = 4; verify_case(0, Arg5, leastMajorityMultiple(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 30; int Arg1 = 42; int Arg2 = 70; int Arg3 = 35; int Arg4 = 90; int Arg5 = 210; verify_case(1, Arg5, leastMajorityMultiple(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 45; int Arg2 = 23; int Arg3 = 26; int Arg4 = 56; int Arg5 = 1170; verify_case(2, Arg5, leastMajorityMultiple(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 14; int Arg2 = 15; int Arg3 = 92; int Arg4 = 65; int Arg5 = 195; verify_case(3, Arg5, leastMajorityMultiple(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    LeastMajorityMultiple ___test;
    ___test.run_test(-1);
}
// END CUT HERE
