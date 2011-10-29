#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class StonesGame {
public:
bool can(int M1, int M2, int N, int K)
{
    int distance = abs(M1 - M2);
    
    // M1$B$H(BM2$B$,N>J}$H$b(BK$B$NHO0O$K<}$^$i$J$1$l$P>!$F$J$$(B
    if(distance > K) return false;

    // M1$B$H(BM2$B$GBP>N@-$r;}$F$J$$$J$i>!$F$J$$(B
    // ex) K=3 X X [M1 X M2] X X => K$B$,4q?t$J$i(BOK$B!#6v?t$J$i(BNG
    if((K+1)%2 != distance%2) return false;

    /* K$B$N3+;O%$%s%G%C%/%9$H=*N;%$%s%G%C%/%9$r5a$a$k(B */

    // distance+1$B$O(BM1-M2$B4V$K4^$^$l$F$$$k@P$N8D?t!#(B+1$B$O??$sCf$N@P$KAjEv(B
    // min(M1, M2)$B$O:8B&$N@P$N%$%s%G%C%/%9$r5a$a$k(B
    // K - (distance+1) $B$O(BK$B$NCf$KB8:_$9$k@P$NCf$G(BM1-M2$B4V$K4^$^$l$J$$@P$N8D?t$KAjEv(B
    // $B$=$l$r(B2$B$G3d$k$3$H$GJRJ}!J$3$N>l9g$O:8B&(B)$B$N@P$N8D?t$r$b$H$a$F$$$k(B
    int start_idx = min(M1, M2) - (K - (distance+1)) / 2;
    if(start_idx < 1) return false;

    // $BF1MM$K1&B&$b(B
    int end_index = max(M1, M2) + (K - (distance+1)) / 2;
    if(end_index > N) return false;

    return true;
}

string winner(int N, int M, int K, int L) {
    bool flag = true;
    // $B:G=i$N0l<j$G>!$F$k>l9g$O(BRomeo
    if(can(M, L, N, K)) return "Romeo";
    // $B0z$-J,$1$K$J$k>r7o$O!"(BStrangelet$B$N0l<jL\$GI,$:>!$F$J$$>l9g(B
    // Strangelet$B$,I,$:>!$F$k(B=Romeo$B$N$I$s$J<j$KBP$7$F$b2r$r$b$D(B
    // $BN"JV$;$P(BRomeo$B$N<j$KBP$7$F0l$D$G$b0l2s$G>!$F$J$$<j$,$"$l$P0z$-J,$1$H$J$k(B
    for(int pos = 1; pos <= N; pos++) {
        // $B2DG=$J(BRomeo$B$N<j(BM->pos$B$X0\F0(B
        if(can(M, pos, N, K)) {
            // Romeo$B$N$"$k<j$KBP$7$F(BStranglet$B$,0l<j$G>!$F$J$$$H$-(B
            // pos->L$B$X0l2s$G0\F0$G$-$J$$(B
            if(!can(pos, L, N, K)) {
                return "Draw";
            }
        }
    }
    // Romeo$B$,>!$?$:!"0z$-J,$1$G$b$J$$(B=Strangelet$B$N>!Mx(B
    return "Strangelet";
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; string Arg4 = "Draw"; verify_case(0, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; string Arg4 = "Romeo"; verify_case(1, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2; int Arg3 = 3; string Arg4 = "Strangelet"; verify_case(2, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2; int Arg3 = 2; string Arg4 = "Draw"; verify_case(3, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 804588; int Arg2 = 705444; int Arg3 = 292263; string Arg4 = "Romeo"; verify_case(4, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1000000; int Arg1 = 100000; int Arg2 = 500000; int Arg3 = 600000; string Arg4 = "Strangelet"; verify_case(5, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    StonesGame ___test;
    ___test.run_test(-1);
}
// END CUT HERE
