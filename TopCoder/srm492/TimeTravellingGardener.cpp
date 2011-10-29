#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * $B@Z$i$J$$LZ$N8D?t$r:G>.2=$9$k(B
 */
class TimeTravellingGardener {
public:
int determineUsage(vector <int> distance, vector <int> height) {
    int dx, dy, ret;
    int x[60], y[60];

    ret = height.size() - 1; // $B:G0-$N>l9g!#0lHV>.$5$$LZ$K9g$o$;$k(B

    x[0] = 0;
    for(int i = 1; i < height.size(); i++) 
        x[i] = x[i-1] + distance[i-1]; 
    for(int i = 0; i < height.size(); i++) 
        y[i] = height[i];

    for(int i = 0; i < height.size(); i++) {
        for(int j = i + 1; j < height.size(); j++) {
            dx = x[j] - x[i];
            dy = y[j] - y[i];
            /* int a = dy / dx;*/ // $BG$0U$N(B2$BK\$NLZ$r$`$9$s$@$H$-$N79$-(B
            int tmp = 0;
            // $B@Z$i$J$$8D?t$,(B2$B8D0J>e$N$b$N$r$5$,$9(B
            for(int k = 0; k < height.size(); k++) {
                /*
                 * $B8m:9KI;_$N$?$a<0JQ7A$r$*$3$J$C$F$$$k(B
                 * $BG$0U$NE@(B(x1,y1), (x2,y2)$B$N(B2$BE@$rDL$kD>@~$O(B
                 * dx = x2 - x1, dy = y2 - y1$B$H$9$k$H(B
                 * y = dy / dx * (x - x1) + y1 $B$GI=$;$k(B
                 * $B3d$j;;$O$$$C$F$$$k$H8m:9$,H/@8$9$k$N$GN>JU$K(Bdx$B$r$+$1$F(B
                 * y * dx = dy * (x - x1) + y1 * dx
                 * $B$G7W;;!&H=Dj$7$F$d$k(B
                 */
                int h  = (x[k] - x[i]) * dy  + y[i] * dx;
                if(h < 0) { tmp += height.size(); break; }       // $BLZ$r%^%$%J%9$^$G@Z$i$J$$$H$$$1$J$$$H$-$OA*$s$@FsE@$O4V0c$$(B
                if(h > y[k]*dx) { tmp += height.size(); break; } // $BCmL\$7$F$$$kLZ$,Dc$/$F$I$&$7$h$&$b$J$$$H$-(B=>$BA*$s$@FsE@$G$OEz$(=P$;$J$$$H$-(B
                if(h < y[k]*dx) tmp++;                           // $BCmL\$7$F$$$kLZ$,9b$/$F@Z$kI,MW$,$"$k(B
            }
            ret = min(ret, tmp);
        }
    }
    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,8,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(3, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {476,465,260,484}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {39,13,8,72,80}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {173,36,668,79,26,544}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {488,743,203,446,444,91,453}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(5, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {2,4,2,2,4,2,4,2,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,10,10,10,16,16,22,22,28,28}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(6, Arg2, determineUsage(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TimeTravellingGardener ___test;
    ___test.run_test(-1);
}
// END CUT HERE
