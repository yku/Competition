#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class TwoRectangles {
public:
/**
 * X軸とY軸で独立して考える
 *   (x.1) --al----ar---bl---br----> [X axis] 
 *   (x.2) --bl----br---al---ar----> [X axis] 
 *   (y.1) --ab----at---bb---bt----> [Y axis]
 *   (y.2) --bb----bt---ab---at----> [Y axis]
 */
int intersect(int a1, int a2, int b1, int b2)
{
    // 交差しない
    if(a2 < b1 || b2 < a1) return 0; 
    // 交点
    if(a2 == b1 || b2 == a1) return 1;
    // 交差
    return 2; 
}

string describeIntersection(vector <int> A, vector <int> B) {
    int al = A[0], ab = A[1], ar = A[2], at = A[3];
    int bl = B[0], bb = B[1], br = B[2], bt = B[3];

    int x = intersect(al, ar, bl, br);
    int y = intersect(ab, at, bb, bt);
    
    if(x == 2 && y == 2) return "rectangle";
    // 片方が交点で片方が交差するとき接する
    if((x == 2 && y == 1) || (x == 1 && y == 2)) return "segment";
    if(x == 1 && y == 1) return "point";
    return "none";
}

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,5,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "rectangle"; verify_case(0, Arg2, describeIntersection(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,5,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "rectangle"; verify_case(1, Arg2, describeIntersection(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,6,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,5,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "segment"; verify_case(2, Arg2, describeIntersection(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,0,5,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "segment"; verify_case(3, Arg2, describeIntersection(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,5,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "point"; verify_case(4, Arg2, describeIntersection(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,1,4,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "none"; verify_case(5, Arg2, describeIntersection(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TwoRectangles ___test;
    ___test.run_test(-1);
}
// END CUT HERE
