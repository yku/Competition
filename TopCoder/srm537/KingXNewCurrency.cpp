#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * A*p+B*q = X*n+Y*m
 * (p,q)=(1,0) => A = X*n + Y*m
 * (p,q)=(0,1) => B = X*n + Y*m
 * A, BはX,Yの非負線形結合で表される
 * (A-X*n) = Y*m が成り立つなら(A-X*n)%Y == 0
 * Bも同様
 * A, BがともにX,Yの非負線形結合で表されるならそれがYの数
 * A = X*n1 + Y*m1, B = X*n2 + Y*m2
 * A+B = X*(n1+n2) + Y*(m1+m2)
 *
 * A*p = p*(X*n1+Y*m1), B*q = q*(X*n2+Y*m2)
 * A*p+B*q = p*(X*n1+Y*m1) + q*(X*n2+Y*m2)
 *         = X*(p*n1+q*n2) + Y*(p*m1 + q*m2)
 */

class KingXNewCurrency {
public:
int howMany(int A, int B, int X) {
    int ret = 0;

    if(A % X == 0 && B % X == 0) return -1;
    for(int Y=1; Y <= max(A, B); Y++) {
        bool can_a = false;
        for(int p = 0; X*p <= A; p++) 
            if((A - X*p)%Y == 0)
                can_a = true; 
        bool can_b = false;
        for(int p = 0; X*p <= B; p++) 
            if((B - X*p)%Y == 0)
                can_b = true;
        if(can_a && can_b) ret++;
    }
    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 8; int Arg2 = 5; int Arg3 = 5; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 4; int Arg2 = 2; int Arg3 = -1; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 13; int Arg3 = 1; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 74; int Arg2 = 44; int Arg3 = 2; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 128; int Arg1 = 96; int Arg2 = 3; int Arg3 = 65; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    KingXNewCurrency ___test;
    ___test.run_test(-1);
}
// END CUT HERE
