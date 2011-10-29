#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class DivideAndShift {
vector<int> primes;
public:
int solve(int n, int m, int depth) {
    int ret = min(m, n-m) + depth;
//    cout << "N=" << n << " " << "M=" <<  m << " " << "depth=" <<  depth << " ret=" <<  ret << endl;
    for(int i = 0; i < primes.size(); i++) {
        if(n < primes[i]) break;
        if(n % primes[i] == 0) {
            ret = min(ret, solve(n / primes[i], m % (n / primes[i]), depth+1));
        }
    }
    return ret;
}

int getLeast(int N, int M) {

    primes.push_back(2);
    primes.push_back(3);
    for(int i = 5; i <= N; i += 2) {
        bool is_prime = true;
        for(int j = 0; j < primes.size(); j++) {
            if(i % primes[j] == 0) is_prime = false;
        }
        if(is_prime) primes.push_back(i);
    }

    return solve(N, M - 1, 0);
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 56; int Arg1 = 14; int Arg2 = 3; verify_case(0, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 49; int Arg1 = 5; int Arg2 = 2; verify_case(1, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 256; int Arg1 = 7; int Arg2 = 6; verify_case(2, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 0; verify_case(3, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 77777; int Arg1 = 11111; int Arg2 = 2; verify_case(4, Arg2, getLeast(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    DivideAndShift ___test;
    ___test.run_test(-1);
}
// END CUT HERE
