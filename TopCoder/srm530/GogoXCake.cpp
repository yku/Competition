#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void dump(vector<string> c)
{
    for(int y = 0; y < c.size(); y++) {
        for(int x = 0; x < c[0].size(); x++) {
            cout << c[y][x];
        }
        cout << endl;
    }

    cout << endl;
}

class GogoXCake {
public:
string solve(vector <string> cake, vector <string> cutter) {
    int cx = cutter[0].size(), cy = cutter.size();
    for(int yy = 0; yy + cy <= cake.size(); yy++) {
        for(int xx = 0; xx + cx <= cake[0].size(); xx++) {
            bool f = true;
            for(int y = 0; y < cy; y++) {
                for(int x = 0; x < cx; x++) {
                    if(cutter[y][x] == '.' and cake[y+yy][x+xx] == 'X') {
                        f = false;
                    }
                }
            }
            if(f) {
                for(int y = 0; y < cy; y++)
                    for(int x = 0; x < cx; x++)
                        if(cutter[y][x] == '.')
                            cake[y+yy][x+xx] = 'X';
            }
        }
    }

    for(int y = 0; y < cake.size(); y++)
        for(int x = 0; x < cake[0].size(); x++)
            if(cake[y][x] == '.')
                return "NO";
    return "YES";
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X.X"
,"..."
,"..."
,"X.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".X"
,".."
,"X."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"..XX"
,"...X"
,"X..."
,"XX.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".."
,".."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".X."
,"X.X"
,".X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YES"; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"XXXXXXX"
,"X.....X"
,"X.....X"
,"X.....X"
,"XXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".X."
,"XXX"
,".X."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(4, Arg2, solve(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {".."
,"X."
,".X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".."
,".X"
,"X."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(5, Arg2, solve(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"X.."
,".XX"
,".XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".XX"
,".XX"
,"X.."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(6, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    GogoXCake ___test;
    ___test.run_test(-1);
}
// END CUT HERE
