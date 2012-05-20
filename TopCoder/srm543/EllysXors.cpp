#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

/**
 * (1) L xor L+1 xor ... R-1 xor R =(1 xor 2 xor .. L-1 xor L xor .. R-1 xor R) xor (1 xor 2 xor .. xor L-1)
 * f(L, R) = f(1, R) xor f(1, L-1)
 * LからRまでのXORの累積和は0からRまでのXORの累積和から0からL-1までのXORの累積和のXOR
 *
 * (2) 0からNまでのXORの累積和はmod 4で周期性がある
 * n = 0, 4, 8...
 * n xor (n+1) = 1, (n+2) xor (n+3) = 1
 * n xor (n+1) xor (n+2) xor (n+3) = 0
 * 
 * N mod 4)
 * 0) n => N
 * 1) n xor (n+1) => 1
 * 2) n xor (n+1) xor (n+2) => N+1 (このときはN=n+2は偶数なのでxor 1で+1)
 * 3) n xor (n+1) xor (n+2) xor (n+3) => 0
 *
 * 別解としては、ビットごとに立っているビットの累積和の偶奇をみてXOR?
 */
class EllysXors {
public:
ll f(ll n) {
    int mod = n % 4;
    if(mod == 0) return n;
    else if(mod == 1) return 1;
    else if(mod == 2) return n+1;
    else if(mod == 3) return 0;
}

long long getXor(long long L, long long R) {
    return f(R) xor f(L-1);
}

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { long long Arg0 = 3LL; long long Arg1 = 10LL; long long Arg2 = 8LL; verify_case(0, Arg2, getXor(Arg0, Arg1)); }
    void test_case_1() { long long Arg0 = 5LL; long long Arg1 = 5LL; long long Arg2 = 5LL; verify_case(1, Arg2, getXor(Arg0, Arg1)); }
    void test_case_2() { long long Arg0 = 13LL; long long Arg1 = 42LL; long long Arg2 = 39LL; verify_case(2, Arg2, getXor(Arg0, Arg1)); }
    void test_case_3() { long long Arg0 = 666LL; long long Arg1 = 1337LL; long long Arg2 = 0LL; verify_case(3, Arg2, getXor(Arg0, Arg1)); }
    void test_case_4() { long long Arg0 = 1234567LL; long long Arg1 = 89101112LL; long long Arg2 = 89998783LL; verify_case(4, Arg2, getXor(Arg0, Arg1)); }

    // END CUT HERE

};

// BEGIN CUT HERE
int main() {
    EllysXors ___test;
    ___test.run_test(-1);
}
// END CUT HERE
