#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <math.h>

using namespace std;


class TheLotteryBothDivs {
public:
bool isProperSuffix(string a, string b) {
    if(b.length() <= a.length()) {
        return false;
    }
    return (b.substr(b.length() - a.length()) == a);
}

double find(vector <string> goodSuffixes) {
    int n = goodSuffixes.size();
    bool remove[n];
    
    fill(remove, remove+n, false);

    for(int i = 0; i < n; i++) {
        // remove duplicate suffix ex) "47", "47"
        for(int j = i+1; j < n; j++) {
            if(goodSuffixes[i] == goodSuffixes[j]) {
                remove[i] = true;
            }
        }
        // remove unnecessary suffix ex) "47" "4747"
        for(int j = 0; j < n; j++) {
            if(isProperSuffix(goodSuffixes[j], goodSuffixes[i])) {
                remove[i] = true;
            }
        }
    }
    double good = 0.0;
    for(int i = 0; i < n; i++) {
        if(!remove[i]) {
            // 当たりくじの本数
            // 例えば,goodSuffixes[i].size()が2だとすると、
            // 000000000-999999999のうち下2桁が固定されるので当たりくじの範囲は
            // 0000000XX-9999999XXとなる。よって当たりくじの本数は
            // 10^(9-2) = 10^7となる。
            good += pow(10, 9.0 - goodSuffixes[i].size());
        }
    }
    double total = 1e9; // =10^9 科学表記
    return good / total;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"4", "7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"47", "47"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.01; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"47", "58", "4747", "502"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.021; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arr0[] = {"8542861", "1954", "6", "523", "000000000", "5426", "8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.201100101; verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TheLotteryBothDivs ___test;
    ___test.run_test(-1);
}
// END CUT HERE
