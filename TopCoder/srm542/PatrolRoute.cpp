#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

#define EMIRP 1000000007
/**
 * 3$BE@(B A, B, C $B$r$=$l$>$l(BX,Y$B$,F1$8$K$J$i$J$$$h$&$KCV$/(B
 * $B0\F05wN%$O(B3$BE@$r$*$$$?$H$-$K@8@.$5$l$k;M3Q7A$N2#$r(Bw, $B=D$r(Bh$B$H$7$?$H$-(B
 * 2*(w+h)$B$GI=$5$l$k(B($B9T$-$H5"$j$G(B*2)$B!#$3$l$,(Bt$B$K$J$k!#(B
 *
 * $B;M3Q7A$r$*$1$k0LCV$NAm?t$O(B (X-w)*(Y-h)
 * 
 * $B;M3Q7AFbIt$N(B3$BE@$NCV$-J}$O(B
 * 1.$B;M3Q7A$N:8>eC<$H1&2<C<$r(BA$B!"(BB$B$H8GDj$9$k!#(BC$B$O;M3Q7AFbIt$NG$0U$N0LCV$K$*$1$k$N$G(B
 * C$B$NCV$-J}$O(B(w-1)*(h-1)
 * 2.A,B,C$B$rJB$YBX$($k$H(B3!=6$BDL$j(B
 * 1,2$B$h$j;M3Q7AFbIt$NE@$NCV$-J}$O(B6*(w-1)*(h-1)
 */
class PatrolRoute {
public:
int countRoutes(int X, int Y, int minT, int maxT) {
    ll ret = 0;	
    for(int h = 2; h < Y; h++) {
        for(int w = 2; w < X; w++) {
            int d = 2*(w+h);
            if(minT <= d && d <= maxT) {
                ll a = (X - w) * (Y - h); // $B;M3Q7A$r$*$1$k0LCV$NAm?t(B
                ll b = 6 * (w - 1) * (h - 1); // $B;M3Q7AFbIt$N(B3$BE@$NCV$-J}$NAm?t(B
                ret = (ret + a * b) % EMIRP;
            }
        }
    }
    return (int)ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 20000; int Arg4 = 6; verify_case(0, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 4; int Arg3 = 7; int Arg4 = 0; verify_case(1, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 9; int Arg3 = 12; int Arg4 = 264; verify_case(2, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 5; int Arg2 = 13; int Arg3 = 18; int Arg4 = 1212; verify_case(3, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 4000; int Arg1 = 4000; int Arg2 = 4000; int Arg3 = 14000; int Arg4 = 859690013; verify_case(4, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PatrolRoute ___test;
    ___test.run_test(-1);
}
// END CUT HERE
