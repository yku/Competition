#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class MultiNumber {
public:
string check(int number) {
    if(number/10 == 0) return "NO";
    vector<int> v;

    while(number) {
        v.push_back(number%10);
        number /= 10;
    }

    for(int i = 0; i < v.size(); i++) {
        int sa = 1, sb = 1;
        for(int j = 0; j <= i; j++) sa *= v[j];
        for(int k = i+1; k < v.size(); k++) sb *= v[k];
        if(sa == sb) return "YES";
    }
    return "NO";
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "NO"; verify_case(0, Arg1, check(Arg0)); }
	void test_case_1() { int Arg0 = 1221; string Arg1 = "YES"; verify_case(1, Arg1, check(Arg0)); }
	void test_case_2() { int Arg0 = 1236; string Arg1 = "YES"; verify_case(2, Arg1, check(Arg0)); }
	void test_case_3() { int Arg0 = 4729382; string Arg1 = "NO"; verify_case(3, Arg1, check(Arg0)); }
	void test_case_4() { int Arg0 = 42393338; string Arg1 = "YES"; verify_case(4, Arg1, check(Arg0)); }
	void test_case_5() { int Arg0 = 808; string Arg1 = "NO"; verify_case(5, Arg1, check(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MultiNumber ___test;
    ___test.run_test(-1);
}
// END CUT HERE
