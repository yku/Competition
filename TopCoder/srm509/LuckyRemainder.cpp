#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class LuckyRemainder {
public:
int getLuckyRemainder(string X) {
    /*
     * X mod 9 = (x1 + x2 + ... + xn) mod 9が成り立つ.xnはXの各桁の数値.
     * Xがn桁の整数であるとすると,
     * X = x1*10^n-1 + x2*10^n-2 + ... + xn*10^0 で表せる.
     * このときmod mをとると,
     * X mod m = (x1*10^n-1 + x2*10^n-2 + ... + xn*10^0) mod m
     * (a + b) mod m = (a mod m) + (b mod m) より,
     * = (x1*10^n-1 + x2*10^n-2 + ... + xn*10^0) mod m
     * = (x1*10^n-1) mod m + (x2*10^n-2) mod m + ... + (xn*10^0) mod m
     * また (a * b) mod m = (a mod m) * (b mod m) より
     * = (x1 mod m) * (10^n-1) mod m + (x2 mod m) * (10^n-2) mod m + ... + (xn mod m) * (10^0) mod m
     * ここでm=9とすると10 mod 9 = 1より
     * = (x1 mod 9) * 1 + (x2 mod m) * 1 + ... + (xn mod m) * 1
     * = (x1 mod 9)  + (x2 mod 9)  + ... + (xn mod 9)
     * = (x1 + x2 + ... + xn) mod 9
     * よって
     * X mod 9 = (x1 + x2 + ... +xn) mod 9 が成り立つ
     */
    int sum = 0;

    /**
     * 桁数をnとするとある桁の数値xは2^(n-1)回足される
     * 組み合わせの個数は2^n.ある桁は常に存在するとみなすので2^(n-1)
     *
     * 具体例. X = 123とすると組み合わせの個数はそれぞれの桁があるかないかの2通りなので
     * 2 * 2 * 2 = 8.
     * 1 2 3
     * 1 2 0
     * 1 0 3
     * 1 0 0
     * 0 2 3
     * 0 2 0
     * 0 0 3
     * 0 0 0
     * このとき0は詰めて考えれば問題と同じ。ex) 1 0 3 => 13
     * 
     * この例の場合,例えばある数を1で固定して考えると1が存在する組み合わせが1が加算される回数となる。
     * つまり、1はあるものとして残りの桁がそれぞれあるかないかの2通りの
     * 組み合わせなので 1 * 2 * 2 = 4となる。
     * よってある数が組み合わせの中で加算される個数を見るには、
     * ある数値の桁が常に存在する組み合わせを見ればよい。
     * n桁の場合、ある一桁が存在するので 1 * 2 * 2 * .. * 2 = 1 * 2 ^ (n-1) = 2^(n-1)
     */
    for(int i = 0; i < X.size(); i++) {
        int n = pow(2, (X.size() - 1));
        /**
         * ((a mod n) * b) mod n
         * = (((a mod n) mod n) * (b mod n))
         * = (a mod n) * (b mod n)
         * = (a * b) mod n
         */
        sum += ((X[i] - '0') * n) % 9;
    }
    sum %= 9;
    return sum;
    
}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "123"; int Arg1 = 6; verify_case(0, Arg1, getLuckyRemainder(Arg0)); }
	void test_case_1() { string Arg0 = "24816"; int Arg1 = 3; verify_case(1, Arg1, getLuckyRemainder(Arg0)); }
	void test_case_2() { string Arg0 = "8"; int Arg1 = 8; verify_case(2, Arg1, getLuckyRemainder(Arg0)); }
	void test_case_3() { string Arg0 = "11235813213455"; int Arg1 = 7; verify_case(3, Arg1, getLuckyRemainder(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    LuckyRemainder ___test;
    ___test.run_test(-1);
}
// END CUT HERE
