#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class RainyRoad {
public:

string isReachable(vector <string> road) {
    int col = road[0].length();
    
    for(int i = 0; i < col; i++) {
        if(road[0][i] == 'W' && road[1][i] == 'W') return "NO";
    }
    return "YES";
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".W.."
,"...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isReachable(Arg0)); }
	void test_case_1() { string Arr0[] = {".W.."
,"..W."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, isReachable(Arg0)); }
	void test_case_2() { string Arr0[] = {".W..W.."
,"...WWW."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(2, Arg1, isReachable(Arg0)); }
	void test_case_3() { string Arr0[] = {".."
,"WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(3, Arg1, isReachable(Arg0)); }
	void test_case_4() { string Arr0[] = {".WWWW."
,"WWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, isReachable(Arg0)); }
	void test_case_5() { string Arr0[] = {".W.W.W."
,"W.W.W.W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(5, Arg1, isReachable(Arg0)); }
	void test_case_6() { string Arr0[] = {".............................................W."
,".............................................W."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(6, Arg1, isReachable(Arg0)); }
	void test_case_7() { string Arr0[] = {".W.W.W."
,"W.W.WWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(7, Arg1, isReachable(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    RainyRoad ___test;
    ___test.run_test(-1);
}
// END CUT HERE
