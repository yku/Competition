#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
/**
 * 考え方
 * ・塔2本の時の関係を考えた
 * ・(x, y) = (塔0の高さ, 塔1の高さ)のときの塔0-塔1間のrope長を値とするマトリックス作成
 * ・塔を一本増やす
 * ・(y, z) = (塔1の高さ, 塔2の高さ)で同様のマトリックスを考える
 *    => いっこ前の関係、(x, y)のrope長を足さないとだめだよね
 *    => たとえば(y1, z1)の値は(x, y1)の値を足すことになる。(y1, z1) = 塔1-塔2間のrope長+(x, y1) | (x, y1) = 塔0の高さがx-塔1の高さがy1のときのrope長(xの候補は1-height[0]まである)
 * 
 * ・塔iの高さをh(i-1), 塔iの高さをh(i)とおきその高さのときの塔i-1 - 塔i間のrope長Ri(h(i))は
 *   Ri(h(i)) = hypot(w, h(i)-h(i-1)) + Ri-1(h(i-1)) と表される. ( 1 <= h(i) <= height[i] )
 * ・最大のrope長を求めたいのでR0(h(0))から計算していき,Ri(h(i))が最大になる組み合わせを選択すればよい
 */
class PillarsDivTwo {
public:
/**
 * dp[i][j] = i番目の塔の高さをjとしたときの最大のロープ長
 * dp[i][j] = max(dp[i][j], dp[i-1][k] + hypot(w, j-k)) | 1 <= k <= height[i-1]
 * kはいっこ前の塔の高さを一段階ずつ変更して確認するための変数
 */
double maximalLength(vector <int> height, int w) {
    double dp[51][101];	
    double ret = 0.0; 
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i < height.size(); i++) {
        for(int j = 1; j <= height[i]; j++) {
            for(int k = 1; k <= height[i-1]; k++) {
                dp[i][j] = max(dp[i][j], dp[i-1][k] + hypot(w, j-k));
            }
        }
    }
    
    for(int i = 1; i <= height[height.size()-1]; i++) {
        ret = max(ret, dp[height.size()-1][i]);
    } 

    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 5.656854249492381; verify_case(0, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; double Arg2 = 300.0; verify_case(1, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100,2,100,2,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 396.32310051270036; verify_case(2, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 3.82842712474619; verify_case(3, Arg2, maximalLength(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PillarsDivTwo ___test;
    ___test.run_test(-1);
}
// END CUT HERE
