#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long memo[50] = {0};

class CorporationSalary {
public:
long long totalSalary(vector <string> relations) {
    long long ret = 0;

    // 初期化しないと一つ前のケースの値が残っている
    memset(memo, 0, sizeof(memo));
    for(int i = 0; i < relations.size(); i++) {
        ret += getSalary(i, relations);
    }

    return ret;
}

// n番目の従業員のサラリーを取得する
long long getSalary(int n, vector<string>& relations) {
    long long ret = 0;
    string relation = relations[n];
    bool f = false;
   
    if(memo[n]) 
        return memo[n];

    for(int i = 0; i < relation.length(); i++) {
        if(relation[i] == 'Y') {
            ret += getSalary(i, relations);
            f = true;
        }
    }
    // 部下が一人もいないとき
    if(!f)
        ret = 1;
    memo[n] = ret;
    return memo[n];
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, totalSalary(Arg0)); }
	void test_case_1() { string Arr0[] = {"NNYN",
 "NNYN",
 "NNNN",
 "NYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(1, Arg1, totalSalary(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNNNNN",
 "YNYNNY",
 "YNNNNY",
 "NNNNNN",
 "YNYNNN",
 "YNNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 17LL; verify_case(2, Arg1, totalSalary(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNNYN",
 "NNNNNN",
 "NNNNNN",
 "NNYNNN",
 "NNNNNN",
 "NNNYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(3, Arg1, totalSalary(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(4, Arg1, totalSalary(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CorporationSalary ___test;
    ___test.run_test(-1);
}
// END CUT HERE
