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
     * X mod 9 = (x1 + x2 + ... + xn) mod 9$B$,@.$jN)$D(B.xn$B$O(BX$B$N3F7e$N?tCM(B.
     * X$B$,(Bn$B7e$N@0?t$G$"$k$H$9$k$H(B,
     * X = x1*10^n-1 + x2*10^n-2 + ... + xn*10^0 $B$GI=$;$k(B.
     * $B$3$N$H$-(Bmod m$B$r$H$k$H(B,
     * X mod m = (x1*10^n-1 + x2*10^n-2 + ... + xn*10^0) mod m
     * (a + b) mod m = (a mod m) + (b mod m) $B$h$j(B,
     * = (x1*10^n-1 + x2*10^n-2 + ... + xn*10^0) mod m
     * = (x1*10^n-1) mod m + (x2*10^n-2) mod m + ... + (xn*10^0) mod m
     * $B$^$?(B (a * b) mod m = (a mod m) * (b mod m) $B$h$j(B
     * = (x1 mod m) * (10^n-1) mod m + (x2 mod m) * (10^n-2) mod m + ... + (xn mod m) * (10^0) mod m
     * $B$3$3$G(Bm=9$B$H$9$k$H(B10 mod 9 = 1$B$h$j(B
     * = (x1 mod 9) * 1 + (x2 mod m) * 1 + ... + (xn mod m) * 1
     * = (x1 mod 9)  + (x2 mod 9)  + ... + (xn mod 9)
     * = (x1 + x2 + ... + xn) mod 9
     * $B$h$C$F(B
     * X mod 9 = (x1 + x2 + ... +xn) mod 9 $B$,@.$jN)$D(B
     */
    int sum = 0;

    /**
     * $B7e?t$r(Bn$B$H$9$k$H$"$k7e$N?tCM(Bx$B$O(B2^(n-1)$B2sB-$5$l$k(B
     * $BAH$_9g$o$;$N8D?t$O(B2^n.$B$"$k7e$O>o$KB8:_$9$k$H$_$J$9$N$G(B2^(n-1)
     *
     * $B6qBNNc(B. X = 123$B$H$9$k$HAH$_9g$o$;$N8D?t$O$=$l$>$l$N7e$,$"$k$+$J$$$+$N(B2$BDL$j$J$N$G(B
     * 2 * 2 * 2 = 8.
     * 1 2 3
     * 1 2 0
     * 1 0 3
     * 1 0 0
     * 0 2 3
     * 0 2 0
     * 0 0 3
     * 0 0 0
     * $B$3$N$H$-(B0$B$O5M$a$F9M$($l$PLdBj$HF1$8!#(Bex) 1 0 3 => 13
     * 
     * $B$3$NNc$N>l9g(B,$BNc$($P$"$k?t$r(B1$B$G8GDj$7$F9M$($k$H(B1$B$,B8:_$9$kAH$_9g$o$;$,(B1$B$,2C;;$5$l$k2s?t$H$J$k!#(B
     * $B$D$^$j!"(B1$B$O$"$k$b$N$H$7$F;D$j$N7e$,$=$l$>$l$"$k$+$J$$$+$N(B2$BDL$j$N(B
     * $BAH$_9g$o$;$J$N$G(B 1 * 2 * 2 = 4$B$H$J$k!#(B
     * $B$h$C$F$"$k?t$,AH$_9g$o$;$NCf$G2C;;$5$l$k8D?t$r8+$k$K$O!"(B
     * $B$"$k?tCM$N7e$,>o$KB8:_$9$kAH$_9g$o$;$r8+$l$P$h$$!#(B
     * n$B7e$N>l9g!"$"$k0l7e$,B8:_$9$k$N$G(B 1 * 2 * 2 * .. * 2 = 1 * 2 ^ (n-1) = 2^(n-1)
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
