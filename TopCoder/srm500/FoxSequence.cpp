#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

class FoxSequence {
public:
string isValid(vector <int> seq) {
    int a, b, c, d;

    // between 0 and a
    for(int i = 0; i < seq.size(); i++) {
        if(seq[i] >= seq[i+1]) { a = i; break; }
    }
    // between a and b
    for(int i = a; i < seq.size(); i++) {
        if(seq[i] <= seq[i+1]) { b = i; break; }
    }
    // between b and c
    for(int i = b; i < seq.size(); i++) {
        if(seq[i] != seq[i+1]) { c = i; break; }
    }
    // between c and d
    for(int i = c; i < seq.size(); i++) {
        if(seq[i] >= seq[i+1]) { d = i; break; }
    }

    if(a <= 0) return "NO";
    int diff = (seq[a] - seq[0]) / a;
    for(int i = 0; i < a - 1; i++) {
       if(seq[i+1] - seq[i] != diff) {
           return "NO";
        }
    }
   
    diff = (seq[b] - seq[a]) / (b - a);
    for(int i = a; i < b - 1; i++) {
       if(seq[i+1] - seq[i] != diff) {
           return "NO";
        }
    }
    
    diff = 0;
    for(int i = b; i < c - 1; i++) {
       if(seq[i+1] - seq[i] != diff) {
           return "NO";
        }
    }
  
    diff = (seq[d] - seq[c]) / (d - c);
    for(int i = c; i < d - 1; i++) {
       if(seq[i+1] - seq[i] != diff) {
           return "NO";
        }
    }
    int N = seq.size(); 
    diff = (seq[N - 1] - seq[d]) / ((N - 1) - d);
    for(int i = d; i < (N - 1) - 1; i++) {
       if(seq[i+1] - seq[i] != diff) {
           return "NO";
        }
    }
    
    return "YES";
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isValid(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, isValid(Arg0)); }
	void test_case_2() { int Arr0[] = {3,6,9,1,9,5,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isValid(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,3,2,1,2,3,2,1,2,3,2,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, isValid(Arg0)); }
	void test_case_4() { int Arr0[] = {1,3,4,3,1,1,1,1,3,4,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, isValid(Arg0)); }
	void test_case_5() { int Arr0[] = {6,1,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(5, Arg1, isValid(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FoxSequence ___test;
    ___test.run_test(-1);
}
// END CUT HERE
