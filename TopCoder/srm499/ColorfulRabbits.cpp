#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

class ColorfulRabbits {
public:
int getMinimum(vector <int> replies) {
    int len = replies.size(); 
    set<int> s;
    int ret = 0;

    if(len == 1 && replies[0] == 0) return 1;

    for(int i = 0; i < len; i++) s.insert(replies[i]);

    set<int>::iterator it = s.begin();
    while(it != s.end()){
        int val = *it + 1;
        const int rabbits = static_cast<int>(count(replies.begin(), replies.end(), *it));
        int groups = rabbits / val;
        if(rabbits % val > 0) groups += 1;
        if(val > rabbits) groups = 1;
        ret += val * groups;
        it++;
    }

    return ret; 
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 1, 2, 2 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { int Arr0[] = { 0 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { int Arr0[] = { 2, 2, 44, 2, 2, 2, 444, 2, 2 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 499; verify_case(2, Arg1, getMinimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ColorfulRabbits ___test;
    ___test.run_test(-1);
}
// END CUT HERE
