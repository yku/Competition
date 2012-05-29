#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/**
 * 値X %は四捨五入できられているのでとりうる範囲は
 * X-0.5 <= X < X+0.5
 *
 * 下限値の％の合計人数と上限値の合計人数の間に10000がふくまれていれば正しい。
 * そうでないなら不正あり。ただし負数にならないことに注意（これが抜けてSystemFail） 
 * ex) X=12なら
 * 11.5 <= X < 12.5
 *
 */
class ElectionFraudDiv2 {
public:
string IsFraudulent(vector <int> percentages) {
    const int voters = 10000;
    const int n = percentages.size();
    int lower = 0, upper = 0; 
    for(int i = 0; i < n; i++) {
        lower += max(0, percentages[i]*100 - (int)(0.5*100)); // minusになることはない
        upper += percentages[i]*100 + (int)(0.5*100);
    }

    //cout << lower << "," << upper << endl;
    if(lower <= voters and voters < upper) return "NO";
    return "YES";
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5();  if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7();  }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(0, Arg1, IsFraudulent(Arg0)); }
	void test_case_1() { int Arr0[] = {34, 34, 34}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, IsFraudulent(Arg0)); }
	void test_case_2() { int Arr0[] = {12, 12, 12, 12, 12, 12, 12, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, IsFraudulent(Arg0)); }
	void test_case_3() { int Arr0[] = {13, 13, 13, 13, 13, 13, 13, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, IsFraudulent(Arg0)); }
	void test_case_4() { int Arr0[] = {0, 1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, IsFraudulent(Arg0)); }
	void test_case_5() { int Arr0[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(5, Arg1, IsFraudulent(Arg0)); }
	void test_case_6() { int Arr0[] = {0, 0, 0, 0, 0, 0, 0, 34, 34, 34}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(6, Arg1, IsFraudulent(Arg0)); }
	void test_case_7() { int Arr0[] = {22, 20, 0, 0, 14, 20, 21, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(7, Arg1, IsFraudulent(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ElectionFraudDiv2 ___test;
    ___test.run_test(-1);
}
// END CUT HERE
