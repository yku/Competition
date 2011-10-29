#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class MysteriousRestaurant {
public:
int convertdoller(char c) {
    if(c >= '0' && c <= '9') return c - '0';
    if(c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if(c >= 'a' && c <= 'z') return c - 'a' + 36;
}

int maxDays(vector <string> prices, int budget) {
    int N = prices.size();
    int M = prices[0].size();
    int ret = 0;

    for(int i = 0; i < N && i < 7; i++) {
        string p = prices[i];
        int minval = 1 << 30;
        for(int j = 0; j < M; j++) {
            minval = min(minval, convertdoller(p[j]));
        }
        if(budget >= minval) {
            budget -= minval;
            ret++;
        }else{
            return ret:
        }
    }
    for(int i = 7; i < N; i++) {
        prices[i][j] + prices[i-7][j] ;
        prices[i][j+1] + prices[i-7][j+1] ;
    }
    
    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"26", "14", "72", "39", "32", "85", "06"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 5; verify_case(0, Arg2, maxDays(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"26", "14", "72", "39", "32", "85", "06", "91"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 8; verify_case(1, Arg2, maxDays(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"SRM", "512"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(2, Arg2, maxDays(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 256; int Arg2 = 10; verify_case(3, Arg2, maxDays(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MysteriousRestaurant ___test;
    ___test.run_test(-1);
}
// END CUT HERE
