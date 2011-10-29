#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define INF 100000
#define VISITED true
#define NON_VISIT !VISITED

class CubeRoll {
public:
int boundedCase(int lefthole, int initPos, int goalPos, int righthole) {
    bool holes[righthole + 1]; // hole range is from 1(min) to 50(max). +1 is hole 0. hole 0 is not used.
    unsigned int turns[righthole + 1];
    queue<int> q;

    fill(holes, holes + righthole + 1, NON_VISIT);     
    fill(turns, turns + righthole + 1, INF);     
    q.push(initPos);
    holes[initPos] = VISITED;
    turns[initPos] = 0;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int y = 1; x + y * y < righthole; y++) {
            int z = x + y * y;
            if(holes[z] == NON_VISIT) {
                q.push(z);
                holes[z] = VISITED;
                turns[z] = turns[x] + 1;
            }
        }

        for(int y = 1; x - y * y > lefthole; y++) {
            int z = x - y * y;
            if(holes[z] == NON_VISIT) {
                q.push(z);
                holes[z] = VISITED;
                turns[z] = turns[x] + 1;
            }
        } 
    }

    return turns[goalPos];
}

int unboundedCase(int distance) {
    
    // distance ... goal - init$B4V$N5wN%(B
    // distance$B$,J?J}?t$J$i0l2s(B
    for(int i = 1; i * i <= distance; i++) {
        if( i * i == distance ) return 1;
    }

    // distance$B$,4q?t$J$iI,$:(B2$B2s$G0\F02DG=(B
    // $BJ?J}?t$N:9$O4q?t$K$J$k$?$a!#0J2<$G@bL@$9$kJ?J}$N:9$G(Bk=1$B$N$H$-$KAjEv(B
    // $BNc$($P!"(B
    // 1, 4, 9, 16, ... , n^2
    // 3, 5, 7, ... , 2n-1( = n^2 - (n - 1)^2)
    // left$BB&$K0l2s!"(Bright$BB&$K0l2s0\F0$9$l$PG$0U$N4q?t0\F0$G$-$k(B
    //  => init$B$H(Bgoal$B$O8r492DG=$J$?$a!"(Bleft$BB&$rL58B1s$H$_$J$9(B
    if(distance % 2 == 1) return 2;

    // distance$B$,J?J}$NOB$GI=$;$k>l9g$O(B2
    for(int i = 1; i * i <= distance; i++) {
        for(int j = i; i * i + j * j <= distance; j++) {
            if( i * i + j * j == distance) return 2;
        }
    }

    // distance$B$,J?J}$N:9$GI=$;$k>l9g$O(B2
    // 1^2, 2^2, 3^2, ... , n^2 $B$r$R$C$/$j$+$($9$H(B
    // n^2, (n-1)^2, ..., (n-k)^2, ..., 2^2, 1^2 $B$H$_$J$;(B
    // $BG$0U$NJ?J}$N:9$O(B n^2 - (n-k)^2 = 2kn - k^2$B$H$J$k(B
    // $BG$0U$NJ?J}$N:9$G(Bdistance$B$,I=$;$k$H2>Dj$9$k$H(B
    // 2kn - k^2 = distance $B$h$j(B n = (distance + k^2) / 2k 
    // $B$3$3$G(Bn$B$O@5$N@0?t$J$?$a!"1&JU$,(B2k$B$G3d$j@Z$l$l$P(B2$B<j$GE~C#2DG=(B
    // 1 <= k <= n, n^2 <= distance
    // $B$3$3$N=hM}$G8!=P$G$-$k$N$O!"6v?t$+$DJ?J}$N:9$G$N$_I=8=$G$-$k>l9g(B
    // ex. distance = 12 (= 4^2 - 2^2)
    // $B%F%9%H%1!<%9$G$O%1!<%9(B5$B$,3:Ev(B
    for(int k = 1; k <= sqrt(distance); k++) {
        if((distance + k * k) % 2 * k == 0) return 2;
    }

    // $B$=$l0J30$O(B3$B<j!#J?J}?t$N:9$GG$0U$N4q?t(B(k=1)$B$r0\F0(B($B$3$3$G(B2$B2s(B)$B$7$?$"$H!"(B
    // +1$B0\F0$9$l$P$h$$$+$i(B
    //  => $B6v?t$+$DJ?J}$NOB(B/$B:9$G0\F0$G$-$J$$5wN%(B ex. 22
    return 1;
}

int getMinimumSteps(int initPos, int goalPos, vector <int> holePos) {
    int lefthole = -INF;
    int righthole = INF;

    if(initPos > goalPos) {
        // init -> goal $B$H(B goal -> init $B$K$+$+$k%3%9%H$OF1$8(B
        // goal $B$+$i(B init $B$K0\F0$7$?$H$_$J$;$P8r492DG=(B
        swap(initPos, goalPos);
    }

    for(int i = 0; i < holePos.size(); i++) {
        int x = holePos[i];
        if(x < initPos) {
            lefthole = max(lefthole, x);
        } else if(x > goalPos) {
            righthole = min(righthole, x);
        } else {
            return -1;
        }

    }
    // $BJRJ}$K$7$+7j$,$J$$>u67(B
    if(lefthole == -INF || righthole == INF) {
        return unboundedCase(goalPos - initPos);
    }else{
        // $B=i4|0LCV$H%4!<%k$,7j$K64$^$l$F$$$k>u67(B
        return boundedCase(lefthole, initPos, goalPos, righthole);
    }
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(0, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 36; int Arg1 = 72; int Arr2[] = {300, 100, 200, 400}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 21; int Arr2[] = {38,45}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 98765; int Arg1 = 4963; int Arr2[] = {10,20,40,30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 68332; int Arg1 = 825; int Arr2[] = {99726,371,67,89210}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(4, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 99998; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(5, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CubeRoll ___test;
    ___test.run_test(-1);
}
// END CUT HERE
