#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

class ToolsBox {
public:
int countTools(vector <string> need) {
    set<string> tools;

    for(int i = 0; i < need.size(); i++) {
        vector<string> s = split(need[i], " ");        
        for(int j = 0; j < s.size(); j++)
            tools.insert(s[j]);
    }

    return tools.size();
}

vector<string> split( string s, string c )
{
    vector<string> ret;
    for( int i=0, n; i <= s.length(); i=n+1 ){

        n = s.find_first_of( c, i );
        if( n == string::npos ) n = s.length();
        string tmp = s.substr( i, n-i );
        ret.push_back(tmp);
    }
    return ret;
}

// BEGIN CUT HERE
public:
void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
void test_case_0() { string Arr0[] = {"SAW HAMMER SCREWDRIVER","SCREWDRIVER HAMMER KNIFE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, countTools(Arg0)); }
void test_case_1() { string Arr0[] = {"SAW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, countTools(Arg0)); }
void test_case_2() { string Arr0[] = {"SAW","SAW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, countTools(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ToolsBox ___test;
    ___test.run_test(-1);
}
// END CUT HERE
