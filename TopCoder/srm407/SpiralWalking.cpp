#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class SpiralWalking {
public:
   
int totalPoints(vector <string> levelMap) {
    int rows = levelMap.size();
    int cols = levelMap[0].size();
    bool visit[rows+2][cols+2];
    int ret = 0;
    int x, y, dx, dy;
    bool turned = false;

    x = 1; y = 1;
    dx = 1; dy = 0;

    for(int y = 0; y < rows+2; y++)
        for(int x = 0; x < cols+2; x++)
            visit[y][x] = false;

    for(int x = 0; x < cols+2; x++) {
        visit[0][x] = true;
        visit[rows+1][x] = true;
    }
    for(int y = 0; y < rows+2; y++){
        visit[y][0] = true;
        visit[y][cols+1] = true;
    }
   while(true) {
        // dump
        /* 
        for(int i = 0; i < rows+2; i++) {
        for(int j = 0; j < cols+2; j++) {
            if(visit[j][i]) cout << "#";
            else            cout << " ";
        }
        cout << endl;
        }
        cout << "ret=" << ret << endl;
        cout << endl;
        */
        turned = false;
        int i = 0;
        for( ; i < 4; i++) { // 4 is number of direction. (N, E, W, S)
            if(not visit[y+dy][x+dx]) break;
            if(dx == 1) {
                dx = 0; dy = 1;
            }else if(dy == 1) {
                dx = -1; dy = 0;
            }else if(dx == -1) {
                dx = 0; dy = -1;
            }else if(dy == -1) {
                dx = 1; dy = 0; 
            }
            turned = true;
        }
        if(i == 4) break;
        if(not turned) ret += levelMap[y-1][x-1] - '0';
        visit[y][x] = true;
        x += dx;
        y += dy;
    }
    ret += levelMap[y-1][x-1] - '0';
    
    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"111",
 "111",
 "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, totalPoints(Arg0)); }
	void test_case_1() { string Arr0[] = {"101",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, totalPoints(Arg0)); }
	void test_case_2() { string Arr0[] = {"00",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, totalPoints(Arg0)); }
	void test_case_3() { string Arr0[] = {"86850",
 "76439",
 "15863",
 "24568",
 "45679",
 "71452",
 "05483"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 142; verify_case(3, Arg1, totalPoints(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SpiralWalking ___test;
    ___test.run_test(3);
}
// END CUT HERE
