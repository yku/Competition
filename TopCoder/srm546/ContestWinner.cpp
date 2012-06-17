#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;


class ContestWinner {
public:
int getWinner(vector <int> events) {
    int ret = 0, t = 0; 
    map<int, int> dict;
    
    for(int i = 0; i < events.size(); i++) {
        dict[events[i]]++;
        
        if(t < dict[events[i]]) {
            ret = events[i];
            t = dict[events[i]];
        }
    }
    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4,7,4,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { int Arr0[] = {10,20,30,40,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { int Arr0[] = {123,123,456,456,456,123}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 456; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,2,3,3,3,4,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, getWinner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ContestWinner ___test;
    ___test.run_test(-1);
}
// END CUT HERE
