#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

class NetworkXOneTimePad {
public:
string exclusive(string s1, string s2)
{
    string ret = "";
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] == s2[i]) ret += "0";
        else               ret += "1";
    }
    return ret;
}

int crack(vector <string> plaintexts, vector <string> ciphertexts) {
    set<string> ret;
    for(int i = 0; i < plaintexts.size(); i++) {
        string key = exclusive(plaintexts[i], ciphertexts[0]);
        bool f = true;
        for(int j = 0; j < ciphertexts.size(); j++) {
            if(find(plaintexts.begin(), plaintexts.end(), exclusive(ciphertexts[j], key)) == plaintexts.end())
                f = false;
        }
        if(f)
            ret.insert(key);
    }

    return ret.size();
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"110", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"101", "010"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, crack(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"00", "01", "10", "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00", "01", "10", "11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, crack(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"01", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, crack(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"000", "111", "010", "101", "110", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"011", "100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, crack(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    NetworkXOneTimePad ___test;
    ___test.run_test(-1);
}
// END CUT HERE


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
