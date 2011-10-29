#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class MultiRead {
public:
int minCycles(string trace, int procs) {
    int clk = 0;
    int reads = 0;

    for(int i = 0; i < trace.size(); i++) {
        if(trace[i] == 'W') {
            clk++;
            if(reads > 0) {
                while(reads > 0){
                    clk++;
                    reads -= procs;
                }
                reads = 0;
            }
        }else {
            reads++;
        }
    }
    while(reads > 0){
        clk++;
        reads -= procs;
    }

    return clk;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RWWRRR"; int Arg1 = 3; int Arg2 = 4; verify_case(0, Arg2, minCycles(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "RWWRRRR"; int Arg1 = 3; int Arg2 = 5; verify_case(1, Arg2, minCycles(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "WWWWW"; int Arg1 = 5; int Arg2 = 5; verify_case(2, Arg2, minCycles(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "RRRRRRRRRR"; int Arg1 = 4; int Arg2 = 3; verify_case(3, Arg2, minCycles(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "RWRRWWRWRWRRRWWRRRRWRRWRRWRRRRRRRRRWRWRWRRRRWRRRRR"; int Arg1 = 4; int Arg2 = 30; verify_case(4, Arg2, minCycles(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MultiRead ___test;
    ___test.run_test(-1);
}
// END CUT HERE
