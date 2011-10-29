#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class FoxMakingDiceEasy {
public:
int theCount(int N, int K) {
    long ret = 0; 
    /**
     * 有効なsumは K <= sum <=  n + (n-1) = 2*n-1
     */
    for(int sum = K; sum <= 2*N-1; sum++) {
        long r = 0;

        for(int i = 1; i <= N; i++) {
            int j = sum - i;
            if(j <= i or j > N) continue;
            r++;
        }
        /* rが3以上のとき解. それ未満のときはret += 0 */
        ret += r * (r - 1) * (r - 2) / 6; /* rC3 */
    }
    return ret * 2; /* 鏡合わせでx2 */
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 7; int Arg2 = 2; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 7; int Arg2 = 0; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 1; int Arg2 = 105800; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 31; int Arg1 = 46; int Arg2 = 504; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 48; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FoxMakingDiceEasy ___test;
    ___test.run_test(-1);
}
// END CUT HERE
