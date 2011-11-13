#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


char maze[51][51];
int row;
int col;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
 

class AlphabetPath {
public:
   
void dfs(int x, int y)
{
    char c = maze[y][x];
    maze[y][x] = '.';

    for(int i = 0; i < 4; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if(0 <= nx && nx < col && 0 <= ny && ny < row && maze[ny][nx] == (c+1)) dfs(nx, ny);
    }
}

string doesItExist(vector <string> letterMaze) {
    row = letterMaze.size();
    col = letterMaze[0].length();
    int sx = 0, sy = 0; 
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            maze[i][j] = letterMaze[i][j];
            if(maze[i][j] == 'A') { sx = j; sy = i; }
        }
    }
    
    dfs(sx, sy);

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(maze[i][j] != '.') return "NO"; 
        }
    }

    return "YES";
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, doesItExist(Arg0)); }
	void test_case_1() { string Arr0[] = {"ADEHI..Z",
 "BCFGJK.Y",
 ".PONML.X",
 ".QRSTUVW"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, doesItExist(Arg0)); }
	void test_case_2() { string Arr0[] = {"ACBDEFGHIJKLMNOPQRSTUVWXYZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(2, Arg1, doesItExist(Arg0)); }
	void test_case_3() { string Arr0[] = {"ABC.......",
 "...DEFGHIJ",
 "TSRQPONMLK",
 "UVWXYZ...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, doesItExist(Arg0)); }
	void test_case_4() { string Arr0[] = {"..............",
 "..............",
 "..............",
 "...DEFGHIJK...",
 "...C......L...",
 "...B......M...",
 "...A......N...",
 "..........O...",
 "..ZY..TSRQP...",
 "...XWVU.......",
 ".............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(4, Arg1, doesItExist(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    AlphabetPath ___test;
    ___test.run_test(-1);
}
// END CUT HERE
