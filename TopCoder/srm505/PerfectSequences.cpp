#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class PerfectSequences {
public:
string fixIt(vector <int> seq) {
    unsigned int sum, product;

    sum = 0;
    product = 1;
    if(seq.size() == 1) return "Yes";
    for(int i = 0; i < seq.size(); i++) {
        if(seq[i] < 0) return "No";
        sum += seq[i];
        product *= seq[i]; 
    }
    if(sum == product) return "No"; 

    for(int i = 0; i < seq.size(); i++) {
        double a, b, mod;
        int ret;
        a = sum - seq[i];
        b = product / seq[i];
        if(a < 0 or (b-1) <= 0) return "No";
        ret = static_cast<int>(a / (b - 1.0));
        mod = a - static_cast<double>(ret * (b - 1.0));
        if(mod == 0) return "Yes"; 
    }
    return "No";
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(0, Arg1, fixIt(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(1, Arg1, fixIt(Arg0)); }
	void test_case_2() { int Arr0[] = {1,4,2,4,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(2, Arg1, fixIt(Arg0)); }
	void test_case_3() { int Arr0[] = {1000000,1,1,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(3, Arg1, fixIt(Arg0)); }
	void test_case_4() { int Arr0[] = {8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(4, Arg1, fixIt(Arg0)); }
	void test_case_5() { int Arr0[] = {2,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(5, Arg1, fixIt(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PerfectSequences ___test;
    ___test.run_test(-1);
}
// END CUT HERE
