#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class SentenceCapitalizerInator {
public:
string fixCaps(string paragraph) {
    string ret = "";
    vector<string> s;
    const char delim = ' ';
    string::size_type begin_idx, end_idx;

    begin_idx = paragraph.find_first_not_of(delim);
    while(begin_idx != string::npos) {
        end_idx = paragraph.find_first_of(delim, begin_idx);
        if(end_idx == string::npos) {
            s.push_back(paragraph.substr(begin_idx));
            break;
        }
        s.push_back(paragraph.substr(begin_idx, (end_idx - begin_idx)));
        begin_idx = paragraph.find_first_not_of(delim, end_idx);
    }

    bool upper = true;
    for(int i = 0; i < s.size(); i++) {
        int last = s[i].length() - 1;
        if(upper) {
            s[i][0] = toupper(s[i][0]);
            upper = false;
        }
        if(s[i][last] == '.') upper = true;
        ret += s[i] + " ";
    }
    int l = ret.length() - 1;
    ret.erase(l);

    return ret; 
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "hello programmer. welcome to topcoder."; string Arg1 = "Hello programmer. Welcome to topcoder."; verify_case(0, Arg1, fixCaps(Arg0)); }
	void test_case_1() { string Arg0 = "one."; string Arg1 = "One."; verify_case(1, Arg1, fixCaps(Arg0)); }
	void test_case_2() { string Arg0 = "not really. english. qwertyuio. a. xyz."; string Arg1 = "Not really. English. Qwertyuio. A. Xyz."; verify_case(2, Arg1, fixCaps(Arg0)); }
	void test_case_3() { string Arg0 = "example four. the long fourth example. a. b. c. d."; string Arg1 = "Example four. The long fourth example. A. B. C. D."; verify_case(3, Arg1, fixCaps(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SentenceCapitalizerInator ___test;
    ___test.run_test(-1);
}
// END CUT HERE
