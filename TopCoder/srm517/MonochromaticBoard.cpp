#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class MonochromaticBoard {
public:
int theMin(vector <string> board) {
    int ret, r, c;
    int rows = board.size();
    int cols = board[0].size();

    r = c = 0;
    for(int i = 0; i < rows; i++) {
        bool isBlack = true;
        for(int j = 0; j < cols; j++) {
            if(board[i][j] == 'W') isBlack = false;
        }
        if(isBlack) r++;
    }

    for(int i = 0; i < cols; i++) {
        bool isBlack = true;
        for(int j = 0; j < rows; j++) {
           if(board[j][i] == 'W') isBlack = false;
        }
        if(isBlack) c++;
    }
    if(c == cols) ret = min(r, c);
    else          ret = r + c;

    return ret; 
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"WBWBW",
 "BBBBB",
 "WBWBW",
 "WBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, theMin(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBBB",
 "BBBB",
 "BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, theMin(Arg0)); }
	void test_case_2() { string Arr0[] = {"BBBBB",
 "BBBBB",
 "BBBBB",
 "BBBBB",
 "BBBBB",
 "BBBBB",
 "BBBBB",
 "BBBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, theMin(Arg0)); }
	void test_case_3() { string Arr0[] = {"WW",
 "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, theMin(Arg0)); }
	void test_case_4() { string Arr0[] = {"BBBBBBBB",
 "BBBBBBBB",
 "BBBBBBBB",
 "WBWBBBWB",
 "BBBBBBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(4, Arg1, theMin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MonochromaticBoard ___test;
    ___test.run_test(-1);
}
// END CUT HERE
