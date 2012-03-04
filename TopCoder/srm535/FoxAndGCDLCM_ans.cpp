#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class FoxAndGCDLCM {
public:
long long gcd(long long x, long long y) 
{
    if(y == 0) return x;
    else return gcd(y, x % y);
}
/**
 * G = gcd(A, B)
 * L = (A*B)/G
 * A = aG, B = bG => a = A/G, b=B/G => 最大公約数で割った物なのでa,bは互いに素
 * L = (aG*bG)/G
 *   = a * b * G
 * L/G = a * b
 * A+B = (a+b)*G
 *  -> min(a+b) * G
 */

long long get(long long G, long long L) {
    if(L%G != 0) return -1;
    long long t = L/G;
    long long ret = t + 1; // a + b <= a * b 
    for(long long i = 1; i * i <= t; i++) {
        if(t % i == 0 && gcd(i, t/i) == 1) { // aとbは互いに素 => gcd(a, b) = 1
            ret = min(ret, i + t / i);
        }
    }
    return ret * G;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 20LL; long long Arg2 = 14LL; verify_case(0, Arg2, get(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 5LL; long long Arg1 = 8LL; long long Arg2 = -1LL; verify_case(1, Arg2, get(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1000LL; long long Arg1 = 100LL; long long Arg2 = -1LL; verify_case(2, Arg2, get(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 100LL; long long Arg1 = 1000LL; long long Arg2 = 700LL; verify_case(3, Arg2, get(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 10LL; long long Arg1 = 950863963000LL; long long Arg2 = 6298430LL; verify_case(4, Arg2, get(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FoxAndGCDLCM ___test;
    ___test.run_test(-1);
    //___test.run_test(0);
}
// END CUT HERE
