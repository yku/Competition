#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class FoxAndIntegers {
public:
vector <int> get(int AminusB, int BminusC, int AplusB, int BplusC) {
    int A, B, C;
    vector<int> ret;
    A = (AminusB + AplusB);
    B = (BminusC + BplusC);

    if(A & 1 || B & 1) return ret;
    A /= 2;
    B /= 2;
    if(AminusB + B != A) return ret;
    C = (BplusC - B);
    if(BminusC + C != B) return ret;
    ret.push_back(A);
    ret.push_back(B);
    ret.push_back(C);
    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = -2; int Arg2 = 3; int Arg3 = 4; int Arr4[] = {2, 1, 3 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, get(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 5; int Arg3 = 5; int Arr4[] = { }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, get(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = -23; int Arg2 = -10; int Arg3 = 3; int Arr4[] = {0, -10, 13 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, get(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = -27; int Arg1 = 14; int Arg2 = 13; int Arg3 = 22; int Arr4[] = { }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, get(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 30; int Arg1 = 30; int Arg2 = 30; int Arg3 = -30; int Arr4[] = {30, 0, -30 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, get(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FoxAndIntegers ___test;
    ___test.run_test(-1);
}
// END CUT HERE
