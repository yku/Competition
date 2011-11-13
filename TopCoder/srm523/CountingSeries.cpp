#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

class CountingSeries {
public:
/* T.Oで死亡 */
/*
long long countThem(long long a, long long b, long long c, long long d, long long upperBound) {
    set<ll> elem;
    ll arithmetic, geometric;

    for(int x = 0; ; x++) {
        arithmetic = a+b*x;
        if(upperBound < arithmetic) break;
        elem.insert(arithmetic);
    }

    for(int y = 0; ; y++) {
        ll t = 1;
        for(int i = 0; i < y; i++) t *= d;
        geometric = c * t;
        if(upperBound < geometric) break;
        elem.insert(geometric);
        if(d == 1) break;
    }
    return elem.size(); 
}
*/
/**
 * 等比数列の個数はすくないので、まず等差数列の個数を求める。
 * 等差数列に含まれない要素について、等比数列の計算をして答えの要素数に加える
 *
 * arithmetic: a <= a+b*x <= upperBound
 * geometric:  c <= c*d^y <= upperBound
 */
long long countThem(long long a, long long b, long long c, long long d, long long upperBound) {
    ll ret = 0;

    /**
     * ex). 1+2x <= 101
     *        2x <= 100
     *         x <=  50
     * xが0のときも要素に含めるので+1して要素数は51
     */
    if(a <= upperBound)
        ret = (upperBound - a) / b + 1; // +1 when x = 0.

    for(ll i = c; i <= upperBound; i *= d)
    {
        /**
         * i<a または a+bx != i (x=0,1,...)のときは
         * 等差数列に含まれていないので答えに加算
         */
        if(i < a or (i-a)%b != 0)
            ret++;
        if(d==1) break; // infinite loop
    }
    return ret;
}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 1LL; long long Arg3 = 2LL; long long Arg4 = 1000LL; long long Arg5 = 1000LL; verify_case(0, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 3LL; long long Arg1 = 3LL; long long Arg2 = 1LL; long long Arg3 = 2LL; long long Arg4 = 1000LL; long long Arg5 = 343LL; verify_case(1, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 40LL; long long Arg1 = 77LL; long long Arg2 = 40LL; long long Arg3 = 100000LL; long long Arg4 = 40LL; long long Arg5 = 1LL; verify_case(2, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 452LL; long long Arg1 = 24LL; long long Arg2 = 4LL; long long Arg3 = 5LL; long long Arg4 = 600LL; long long Arg5 = 10LL; verify_case(3, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { long long Arg0 = 234LL; long long Arg1 = 24LL; long long Arg2 = 377LL; long long Arg3 = 1LL; long long Arg4 = 10000LL; long long Arg5 = 408LL; verify_case(4, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 1LL; long long Arg3 = 2LL; long long Arg4 = 1000000000000LL; long long Arg5 = 1000000000000LL; verify_case(5, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CountingSeries ___test;
    ___test.run_test(-1);
}
// END CUT HERE
