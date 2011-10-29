#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool move[3] = { false, false, false };
class ThreeTeleports {
public:
int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
    return (int)solve(xMe, yMe, xHome, yHome, teleports); 
}

int getMD(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

long solve(int x, int y, int xHome, int yHome, vector <string> teleports)
{
    long ret = getMD(x, y, xHome, yHome);

    for(int i = 0; i < teleports.size(); i++) {
        int x1, x2, y1, y2;
        if(move[i]) continue;
        
        move[i] = true;
        sscanf(teleports[i].c_str(), "%d %d %d %d", &x1, &y1, &x2, &y2);
        ret = min(ret, getMD(x, y, x1, y1) + solve(x2, y2, xHome, yHome, teleports) + 10);
        ret = min(ret, getMD(x, y, x2, y2) + solve(x1, y1, xHome, yHome, teleports) + 10); 
        move[i] = false;
    }
    return ret;    
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 4; int Arg3 = 5; string Arr4[] = {"1000 1001 1000 1002", "1000 1003 1000 1004", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 3; verify_case(0, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 20; int Arg3 = 20; string Arr4[] = {"1 1 18 20", "1000 1003 1000 1004", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 14; verify_case(1, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 20; int Arg3 = 20; string Arr4[] = {"1000 1003 1000 1004", "18 20 1 1", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 14; verify_case(2, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 10000; int Arg3 = 20000; string Arr4[] = {"1000 1003 1000 1004", "3 3 10004 20002", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 30; verify_case(3, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 10000; int Arg3 = 30000; string Arr4[] = {"3 10 5200 4900", "12212 8699 9999 30011", "12200 8701 5203 4845"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 117; verify_case(4, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1000000000; int Arg3 = 1000000000; string Arr4[] = {"0 1 0 999999999", "1 1000000000 999999999 0", "1000000000 1 1000000000 999999999"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 36; verify_case(5, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ThreeTeleports ___test;
    ___test.run_test(-1);
}
// END CUT HERE
