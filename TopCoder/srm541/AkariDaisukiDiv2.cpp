#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class AkariDaisukiDiv2 {
public:
int countTuples(string S) {
    const int n = S.size();
    int ret = 0;
    for(int i = 1; i < n; i++) { // first X
        for(int j = i+1; j < n; j++) { // Akari
            for(int p = j+1; p < n; p++) { // second X
                for(int q = p+1; q < n; q++) { // Daisuki
                    if(S.substr(i, j-i) == S.substr(p, q-p)) ret++;
                }
            }
        }
    }

    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "topcoderdivtwo"; int Arg1 = 2; verify_case(0, Arg1, countTuples(Arg0)); }
	void test_case_1() { string Arg0 = "foxciel"; int Arg1 = 0; verify_case(1, Arg1, countTuples(Arg0)); }
	void test_case_2() { string Arg0 = "magicalgirl"; int Arg1 = 4; verify_case(2, Arg1, countTuples(Arg0)); }
	void test_case_3() { string Arg0 = "waaiusushioakariusushiodaisuki"; int Arg1 = 75; verify_case(3, Arg1, countTuples(Arg0)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; int Arg1 = 8924; verify_case(4, Arg1, countTuples(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    AkariDaisukiDiv2 ___test;
    ___test.run_test(-1);
}
// END CUT HERE
