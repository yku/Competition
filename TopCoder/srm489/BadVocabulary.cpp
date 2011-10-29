#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class BadVocabulary {
public:
int count(string badPrefix, string badSuffix, string badSubstring, vector <string> vocabulary) {
    int ret = 0;
    string s;

    for(int i = 0; i < vocabulary.size(); i++) {
        bool f = false;
        s = vocabulary[i];
        if(s.size() >= badPrefix.size() && s.substr(0, badPrefix.size()) == badPrefix)
            f = true;
        if(s.size() >= badSuffix.size() && s.substr(s.size() - badSuffix.size()) == badSuffix)
            f = true;
        for(int j = 1; j + badSubstring.size() < s.size(); j++) 
            if(s.substr(j, badSubstring.size()) == badSubstring)
                f = true;
        if(f) ret++;
    }

    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "bug"; string Arg1 = "bug"; string Arg2 = "bug"; string Arr3[] = {"buggy", "debugger", "debug"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "b"; string Arg2 = "c"; string Arr3[] = {"a", "b", "tco"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arg0 = "cut"; string Arg1 = "sore"; string Arg2 = "scar"; string Arr3[] = {"scary", "oscar"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arg0 = "bar"; string Arg1 = "else"; string Arg2 = "foo"; string Arr3[] = {"foofoofoo", "foobar", "elsewhere"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arg0 = "pre"; string Arg1 = "s"; string Arg2 = "all"; string Arr3[] = {"all", "coders", "be", "prepared", "for", "the", "challenge", "phase"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BadVocabulary ___test;
    ___test.run_test(-1);
}
// END CUT HERE
