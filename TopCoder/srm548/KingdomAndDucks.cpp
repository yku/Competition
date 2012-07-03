#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

class KingdomAndDucks {
public:
int minDucks(vector <int> duckTypes) {
    map<int, int> dict;
    int ret = 0;
    int t = 0;

    for(int i = 0; i < duckTypes.size(); i++)
        dict[duckTypes[i]]++;
    for(int i = 0; i <= 50; i++)
        t = max(t, dict[i]);
    
    map<int, int>::iterator it = dict.begin();
    while(it != dict.end()) {
        if((*it).second >= 1) ret += t;
        it++;
    }

    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minDucks(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 7, 4, 7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, minDucks(Arg0)); }
	void test_case_2() { int Arr0[] = {17, 17, 19, 23, 23, 19, 19, 17, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, minDucks(Arg0)); }
	void test_case_3() { int Arr0[] = {50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, minDucks(Arg0)); }
	void test_case_4() { int Arr0[] = {10, 10, 10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, minDucks(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    KingdomAndDucks ___test;
    ___test.run_test(-1);
}
// END CUT HERE
