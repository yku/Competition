#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class SquareOfDigits {
public:
int getMax(vector <string> data) {
    int a, b, c, d;
    int ret = 1;
    for(int y = 0; y < data.size(); y++) {
        for(int x = 0; x < data[0].length(); x++) {
            a = data[y][x];
            for(int diff = 1; diff+x < data[0].length() && diff+y < data.size(); diff++) {
                b = data[y+diff][x];
                c = data[y][x+diff];
                d = data[y+diff][x+diff];
                if(a == b && b == c && c == d) ret = max(ret, (diff+1)*(diff+1));
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
	void test_case_0() { string Arr0[] = {"12",
 "34"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getMax(Arg0)); }
	void test_case_1() { string Arr0[] = {"1255",
 "3455"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, getMax(Arg0)); }
	void test_case_2() { string Arr0[] = {"42101",
 "22100",
 "22101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, getMax(Arg0)); }
	void test_case_3() { string Arr0[] = {"1234567890"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, getMax(Arg0)); }
	void test_case_4() { string Arr0[] = {"9785409507",
 "2055103694",
 "0861396761",
 "3073207669",
 "1233049493",
 "2300248968",
 "9769239548",
 "7984130001",
 "1670020095",
 "8894239889",
 "4053971072"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; verify_case(4, Arg1, getMax(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SquareOfDigits ___test;
    ___test.run_test(-1);
}
// END CUT HERE
