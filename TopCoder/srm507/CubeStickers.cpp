#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

class CubeStickers {
public:
string isPossible(vector <string> sticker) {
    map<string, int> m;

    for(int i = 0; i < sticker.size(); i++) {
        if(m.count(sticker[i]) == 0)
            m.insert(pair<string, int>(sticker[i], 0));
        else
            m[sticker[i]]++;
    }
    
    map<string, int>::iterator it = m.begin();
    int two = 0;
    while(it != m.end()){
        if((*it).second >= 2) two++; 
        it++;
    }
    
    if(m.size() >= 5)                  return "YES";
    else if(m.size() == 4 && two >= 2) return "YES"; // 2, 2, 1, 1 -> sum = 6
    else if(m.size() == 3 && two == 3) return "YES"; // 2, 2, 2    -> sum = 6
    else                               return "NO";
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"cyan","magenta","yellow","purple","black","white","purple"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isPossible(Arg0)); }
	void test_case_1() { string Arr0[] = {"blue","blue","blue","blue","blue","blue","blue","blue","blue","blue"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(1, Arg1, isPossible(Arg0)); }
	void test_case_2() { string Arr0[] = {"red","yellow","blue","red","yellow","blue","red","yellow","blue"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isPossible(Arg0)); }
	void test_case_3() { string Arr0[] = {"purple","orange","orange","purple","black","orange","purple"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, isPossible(Arg0)); }
	void test_case_4() { string Arr0[] = {"white","gray","green","blue","yellow","red","target","admin"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(4, Arg1, isPossible(Arg0)); }
	void test_case_5() { string Arr0[] = {"white","gray","green","blue","gray","gray","gray","gray"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(5, Arg1, isPossible(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CubeStickers ___test;
    ___test.run_test(-1);
}
// END CUT HERE
