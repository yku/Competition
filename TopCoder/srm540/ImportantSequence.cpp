#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

/**
 * 0 < a[0] < INF $B$G(Ba[0]$B$N$H$j$&$kHO0O$,Ez$($K$J$k(B
 * a[0]$B$K:G>.CM$N(B1$B$H!":GBgCM$H$7$F5pBg$J?t;z$r$$$l$F$d$C$F?tNs$r:n$k(B
 * $B$?$@$7(Ba[i] <= 0$B$H$J$kIT@5$JCM$K$J$C$?$H$-$O!":G>.CM$H$7$F$N(B1$B$rBe$o$j$K(B
 * $B;H$$6/0z$K?tNs$rAO$j>e$2$k!#?tNs$,$G$-$?$iKvHx$+$i3N$+$a$F$$$/!#KvHx$+$i$_$F$$$/$H$-$K(B
 * a[i] <= 0 $B$H$J$k>l9g$OEz$($,$J$$$N$G(B0$B$rJV$9!#KvHx$+$i@hF,$KC)$l$l$P$"$H$O:G>.CM$H:GBgCM$r(B
 * $BM?$($?>l9g$N(Ba[0]$B$N:9J,$r8+$k!#:9J,$,5pBg$G$"$l$PEz$($OL5?t$K$"$k$H$_$J$7(B-1, $B$=$&$G$J$1$l$PHO0O$N:9J,(B+1$B$,Ez$((B
 */

class ImportantSequence {
public:
int getCount(vector <int> B, string operators) {
    int n = operators.size();
    ll a_mn[n+1], a_mx[n+1];

    a_mn[0] = 1, a_mx[0] = 1LL << 60;
    for(int i = 0; i < n; i++) {
        if(operators[i] == '+') {
            a_mn[i+1] = max(B[i] - a_mn[i], 1LL);
            a_mx[i+1] = max(B[i] - a_mx[i], 1LL);
        }else{
            a_mn[i+1] = max(a_mn[i] - B[i], 1LL);
            a_mx[i+1] = max(a_mx[i] - B[i], 1LL);
        }
    }

    for(int i = n-1; i >= 0; i--) {
        if(operators[i] == '+') {
            a_mn[i] = B[i] - a_mn[i+1]; 
            a_mx[i] = B[i] - a_mx[i+1]; 
        }else{
            a_mn[i] = B[i] + a_mn[i+1]; 
            a_mx[i] = B[i] + a_mx[i+1]; 
        }
        if(a_mx[i] <= 0 or a_mn[i] <= 0) return 0;
    }
/*
    for(int i = 0; i < n+1; i++) {
        cout << a_mn[i] << ",";
    }
    cout << endl;
    for(int i = 0; i < n+1; i++) {
        cout << a_mx[i] << ",";
    }
    cout << endl;
*/   
    return (a_mx[0] - a_mn[0]) > 1LL << 30 ? -1 : a_mx[0] - a_mn[0] + 1;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, -1, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+-+"; int Arg2 = 2; verify_case(0, Arg2, getCount(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-"; int Arg2 = -1; verify_case(1, Arg2, getCount(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+"; int Arg2 = 0; verify_case(2, Arg2, getCount(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+"; int Arg2 = 9; verify_case(3, Arg2, getCount(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {540, 2012, 540, 2012, 540, 2012, 540}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-+-+-+-"; int Arg2 = 1471; verify_case(4, Arg2, getCount(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-1000000000, -1000000000, -1000000000, -1000000000, -1000000000, -1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "++++++"; int Arg2 = 0; verify_case(5, Arg2, getCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ImportantSequence ___test;
    ___test.run_test(-1);
}
// END CUT HERE
