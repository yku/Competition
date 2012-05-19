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
 * 3点 A, B, C をそれぞれX,Yが同じにならないように置く
 * 移動距離は3点をおいたときに生成される四角形の横をw, 縦をhとしたとき
 * 2*(w+h)で表される(行きと帰りで*2)。これがtになる。
 *
 * 四角形をおける位置の総数は (X-w)*(Y-h)
 * 
 * 四角形内部の3点の置き方は
 * 1.四角形の左上端と右下端をA、Bと固定する。Cは四角形内部の任意の位置におけるので
 * Cの置き方は(w-1)*(h-1)
 * 2.A,B,Cを並べ替えると3!=6通り
 * 1,2より四角形内部の点の置き方は6*(w-1)*(h-1)
 */
class PatrolRoute {
public:
int countRoutes(int X, int Y, int minT, int maxT) {
    ll ret = 0;	
    for(int h = 2; h < Y; h++) {
        for(int w = 2; w < X; w++) {
            int d = 2*(w+h);
            if(minT <= d && d <= maxT) {
                ll a = (X - w) * (Y - h); // 四角形をおける位置の総数
                ll b = 6 * (w - 1) * (h - 1); // 四角形内部の3点の置き方の総数
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
