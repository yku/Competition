#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

class WhichDay {
public:
string getDay(vector <string> notOnThisDay) {
    string days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    string ret;
    set<string> s;

    for(int i = 0; i < notOnThisDay.size(); i++) {
        s.insert(notOnThisDay[i]);
    }
    
    for(int i = 0; i < 7; i++) {
        if(s.count(days[i]) == 0) return days[i];
    }
    return "";
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Saturday"; verify_case(0, Arg1, getDay(Arg0)); }
	void test_case_1() { string Arr0[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Friday", "Thursday"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Saturday"; verify_case(1, Arg1, getDay(Arg0)); }
	void test_case_2() { string Arr0[] = {"Sunday", "Monday", "Tuesday", "Thursday", "Friday", "Saturday"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Wednesday"; verify_case(2, Arg1, getDay(Arg0)); }
	void test_case_3() { string Arr0[] = {"Sunday", "Friday", "Tuesday", "Wednesday", "Monday", "Saturday"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Thursday"; verify_case(3, Arg1, getDay(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    WhichDay ___test;
    ___test.run_test(-1);
}
// END CUT HERE
