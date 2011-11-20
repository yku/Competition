#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int luckyNumbers[20] = {  4,    7,   44,   47,   74,   77, 
                        444,  447,  474,  477,  744,  747, 774, 777,
                       4444, 4447, 4474, 4477, 4744, 4747 };
class TheLuckyGameDivTwo {
public:
/*
 * John$B$O$J$k$Y$/B?$/(BluckyNumber$B$r;D$=$&$H$9$k(B
 * Brus$B$O$J$k$Y$/(BluckyNumber$B$r;D$5$J$$$h$&$K$9$k(B
 */
int find(int a, int b, int jLen, int bLen) {
    const int l = 20;
    int jPoint = 0;

    for(int jS = a; jS <= b; jS++) {
        int bPoint = 9999;
        int jE = jS + jLen - 1;
        if(jE > b) break;
        for(int bS = jS; bS <= jE; bS++) {
            int ln = 0;
            int bE = bS + bLen - 1;
            if(bE > jE) break;
            for(int i = 0; i < l; i++) 
                if(bS <= luckyNumbers[i] && luckyNumbers[i] <= bE) ln++;
            // John$B$,A*$s$@HO0O$NCf$G$N:G>.CM$r5a$a$F$$$k(B
            bPoint = min(bPoint, ln);
        }
        // John$B$,A*$s$@HO0O$NCf$G!"(BBrus$B$,A*$s$@:GBgCM$r5a$a$F$$$k(B
        jPoint = max(jPoint, bPoint);
    }
     
    return jPoint;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 2; int Arg3 = 1; int Arg4 = 0; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 100; int Arg2 = 100; int Arg3 = 100; int Arg4 = 6; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 8; int Arg2 = 3; int Arg3 = 2; int Arg4 = 1; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 100; int Arg2 = 75; int Arg3 = 50; int Arg4 = 2; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TheLuckyGameDivTwo ___test;
    ___test.run_test(-1);
}
// END CUT HERE