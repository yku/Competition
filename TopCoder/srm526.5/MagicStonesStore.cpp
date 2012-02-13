#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool isPrime(int n){
    int i;
    if(n < 2)
        return 0;
    else if(n == 2)
        return 1;
    if(n % 2 == 0)
        return 0;

    for(i = 3; i * i <= n; i += 2)
        if(n % i == 0)
              return false;
    return true;
}

class MagicStonesStore {
public:
string ableToDivide(int n) {
    for(int i=2; i <= 2*n; i++) {
        if(isPrime(i) && isPrime(2*n-i)) return "YES";
    }
    return "NO";
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "NO"; verify_case(0, Arg1, ableToDivide(Arg0)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "YES"; verify_case(1, Arg1, ableToDivide(Arg0)); }
	void test_case_2() { int Arg0 = 3; string Arg1 = "YES"; verify_case(2, Arg1, ableToDivide(Arg0)); }
	void test_case_3() { int Arg0 = 5; string Arg1 = "YES"; verify_case(3, Arg1, ableToDivide(Arg0)); }
	void test_case_4() { int Arg0 = 1000; string Arg1 = "YES"; verify_case(4, Arg1, ableToDivide(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MagicStonesStore ___test;
    ___test.run_test(-1);
}
// END CUT HERE
