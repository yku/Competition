#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/**
 * 切断して余った切れ端をすぐにつぎのステップで埋め込めばOK.
 * ex)desiredLength=5, desiredCount=6, actualLength=6 の場合
 * Step1. 一本目の納品する木 dl < al より alを5と1に切断(cut++)し、1があまる。
 * Step2-0. 二本目の納品する木 まずStep1で余った分を二本目のdlに利用(dl - Step1のあまり 1).=> 二本目のdlはあと4必要
 * Step2-1. al を4と2に切断(cut++) => 余り2 以下同様に三本目以降を適用していく
 */
class BoardSplitting {
public:
int minimumCuts(int desiredLength, int desiredCount, int actualLength) {
    int cut = 0;	
    if(desiredLength >= actualLength and desiredLength % actualLength == 0) return 0;

    int al = actualLength;
    for(int i = 0; i < desiredCount; i++) {
        int dl = desiredLength;
        while(dl) {
            if(dl >= al) { dl -= al; al = actualLength; }
            else {
                al -= dl;
                dl = 0;
                cut++;
            }
        }
    }
    //cout << cut << endl;
    return cut;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();  }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 4; int Arg3 = 3; verify_case(0, Arg3, minimumCuts(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 100; int Arg2 = 3; int Arg3 = 0; verify_case(1, Arg3, minimumCuts(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 500; int Arg1 = 5; int Arg2 = 1000; int Arg3 = 3; verify_case(2, Arg3, minimumCuts(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 314; int Arg1 = 159; int Arg2 = 26; int Arg3 = 147; verify_case(3, Arg3, minimumCuts(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 6; int Arg3 = 5; verify_case(4, Arg3, minimumCuts(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BoardSplitting ___test;
    ___test.run_test(-1);
}
// END CUT HERE
