#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * 考え方
 * とりあえず適当な値をXとして試してみる
 * 必要なメソッドは
 *  1. LevelXで有効な昇順が構成できるか判定するメソッド
 * 1.ができたら今度はXの値を探す方法。
 *  2. 二分探索でXを特定していく
 */

class KingdomAndTrees {
public:

bool ok(vector<int>& heights, int X)
{
    int prev = max(1, heights[0] - X);
    for(int i = 1; i < heights.size(); i++) {
        if(prev >= heights[i]) {
            if(prev+1 > heights[i] + X) return false; // prev+1はprevの次の木の有効な高さの最小値
            prev++; // 次の木の高さになる| tree[i]の高さがprev -> tree[i+1]の高さがprev++
        } else {
            // prev+1が下げられる許容の下限値(-Xで下げすぎないようにするため)
            prev = max(prev+1, heights[i] - X);
        }
    }
    return true;
}

int minLevel(vector <int> heights) {
    long long lower = 0;
    long long upper = 1000000000LL;
    
    while(lower < upper) {
        int middle = (lower+upper) / 2;
        if(ok(heights, middle))
            upper = middle;
        else
            lower = middle+1;
    }

    return lower;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {9, 5, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minLevel(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minLevel(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minLevel(Arg0)); }
	void test_case_3() { int Arr0[] = {548, 47, 58, 250, 2012}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 251; verify_case(3, Arg1, minLevel(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    KingdomAndTrees ___test;
    ___test.run_test(-1);
}
// END CUT HERE
