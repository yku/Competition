#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class RedAndGreen {
public:
int minPaints(string row) {
    int ret = 1 << 30;
    const int size = row.size();

    for(int i = 0; i < size; i++) { // base
        int t = 0;
        for(int j = 0; j < size; j++) {
            if(i < j && row[j] == 'R') t++;
            if(i > j && row[j] == 'G') t++;
        }
        ret = min(ret, t);
    }  
    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 7)) test_case_7();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGRGR"; int Arg1 = 2; verify_case(0, Arg1, minPaints(Arg0)); }
	void test_case_1() { string Arg0 = "RRRGGGGG"; int Arg1 = 0; verify_case(1, Arg1, minPaints(Arg0)); }
	void test_case_2() { string Arg0 = "GGGGRRR"; int Arg1 = 3; verify_case(2, Arg1, minPaints(Arg0)); }
	void test_case_3() { string Arg0 = "RGRGRGRGRGRGRGRGR"; int Arg1 = 8; verify_case(3, Arg1, minPaints(Arg0)); }
	void test_case_4() { string Arg0 = "RRRGGGRGGGRGGRRRGGRRRGR"; int Arg1 = 9; verify_case(4, Arg1, minPaints(Arg0)); }
	void test_case_5() { string Arg0 = "RRR"; int Arg1 = 0; verify_case(5, Arg1, minPaints(Arg0)); }
	void test_case_6() { string Arg0 = "GGG"; int Arg1 = 0; verify_case(6, Arg1, minPaints(Arg0)); }
	void test_case_7() { string Arg0 = "GGGRRRRGRGRRRGRRRRGRGGGRGRRRRRRGGRGRGRGGRRRRGRGGGR"; int Arg1 = 19; verify_case(7, Arg1, minPaints(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    RedAndGreen ___test;
    ___test.run_test(-1);
}
// END CUT HERE
