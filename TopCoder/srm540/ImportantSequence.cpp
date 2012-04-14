#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

/**
 * 0 < a[0] < INF でa[0]のとりうる範囲が答えになる
 * a[0]に最小値の1と、最大値として巨大な数字をいれてやって数列を作る
 * ただしa[i] <= 0となる不正な値になったときは、最小値としての1を代わりに
 * 使い強引に数列を創り上げる。数列ができたら末尾から確かめていく。末尾からみていくときに
 * a[i] <= 0 となる場合は答えがないので0を返す。末尾から先頭に辿れればあとは最小値と最大値を
 * 与えた場合のa[0]の差分を見る。差分が巨大であれば答えは無数にあるとみなし-1, そうでなければ範囲の差分+1が答え
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
