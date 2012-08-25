#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class FoxAndFlowerShopDivTwo {
public:
int theMaxFlowers(vector <string> flowers, int r, int c) {
    int max_r = flowers.size(), max_c = flowers[0].size();
    int ret = 0, num_flowers = 0; 
    
    for(int y = 0; y < r; y++) 
        for(int x = 0; x < max_c; x++) 
            if(flowers[y][x] == 'F') num_flowers++;
    ret = max(ret, num_flowers); 
    num_flowers = 0;
 
    for(int y = max_r - 1; y > r; y--) 
        for(int x = 0; x < max_c; x++) 
            if(flowers[y][x] == 'F') num_flowers++;
    ret = max(ret, num_flowers); 
    num_flowers = 0;
 
    for(int y = 0; y < max_r; y++) 
        for(int x = 0; x < c; x++) 
            if(flowers[y][x] == 'F') num_flowers++;
    ret = max(ret, num_flowers); 
    num_flowers = 0;
  
    for(int y = 0; y < max_r; y++) 
        for(int x = max_c - 1; x > c; x--) 
            if(flowers[y][x] == 'F') num_flowers++;
    ret = max(ret, num_flowers); 

    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"F.F",
 ".F.",
 ".F."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; verify_case(0, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"F..",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; verify_case(1, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {".FF.F.F",
 "FF...F.",
 "..FF.FF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 6; verify_case(2, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"F",
 ".",
 "F",
 "F",
 "F",
 ".",
 "F",
 "F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; int Arg3 = 3; verify_case(3, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {".FFF..F...",
 "FFF...FF.F",
 "..F.F.F.FF",
 "FF..F.FFF.",
 "..FFFFF...",
 "F....FF...",
 ".FF.FF..FF",
 "..F.F.FFF.",
 ".FF..F.F.F",
 "F.FFF.FF.F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; int Arg3 = 32; verify_case(4, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FoxAndFlowerShopDivTwo ___test;
    ___test.run_test(-1);
}
// END CUT HERE
