#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class WorkingRabbits {
public:
double getEfficiency(vector <string> profit) {
    double P = 0.0;
    double Q = profit.size() * (profit.size() - 1) / 2.0; 
    
    for(int i = 0; i < profit.size(); i++) 
        for(int j = i; j < profit[0].size(); j++) 
            P  += profit[i][j] - '0';
    
    return (double)(P / Q); 
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "071", 
  "702", 
  "120" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.3333333333333335; verify_case(0, Arg1, getEfficiency(Arg0)); }
	void test_case_1() { string Arr0[] = { "00", 
  "00" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(1, Arg1, getEfficiency(Arg0)); }
	void test_case_2() { string Arr0[] = { "0999", 
  "9099", 
  "9909", 
  "9990" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 9.0; verify_case(2, Arg1, getEfficiency(Arg0)); }
	void test_case_3() { string Arr0[] = { "013040", 
  "100010", 
  "300060", 
  "000008", 
  "416000", 
  "000800" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.5333333333333334; verify_case(3, Arg1, getEfficiency(Arg0)); }
	void test_case_4() { string Arr0[] = { "06390061", 
  "60960062", 
  "39090270", 
  "96900262", 
  "00000212", 
  "00222026", 
  "66761201", 
  "12022610" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.2142857142857144; verify_case(4, Arg1, getEfficiency(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    WorkingRabbits ___test;
    ___test.run_test(-1);
}
// END CUT HERE
