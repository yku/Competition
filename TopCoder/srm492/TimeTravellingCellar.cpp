// SRM 492 div2 250
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class TimeTravellingCellar {
public:
int determineProfit(vector <int> profit, vector <int> decay) {
    int numCellars = profit.size();
    int tmp = 0;

    for(int i = 0; i < numCellars; i++) {
        for(int j = 0; j < numCellars; j++) {
            if (i == j) continue;
            tmp = max(tmp, profit[i] - decay[j]);
        }
    }
    return tmp;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) {
            if ((Case == -1) || (Case == 0)) test_case_0();
            if ((Case == -1) || (Case == 1)) test_case_1();
            if ((Case == -1) || (Case == 2)) test_case_2();
            if ((Case == -1) || (Case == 3)) test_case_3();
        }
        private:
	template <typename T> string print_array(const vector<T> &V) {
            ostringstream os; os << "{ ";
            for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\",";
        os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) {
            cerr << "Test Case #" << Case << "...";
            if (Expected == Received) cerr << "PASSED" << endl;
            else { cerr << "FAILED" << endl;
                   cerr << "\tExpected: \"" << Expected << '\"' << endl;
                   cerr << "\tReceived: \"" << Received << '\"' << endl; } 
            }
	void test_case_0() { 
            int Arr0[] = {1,2,3};
            vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
            int Arr1[] = {3,1,2}; 
            vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
            int Arg2 = 2;
            verify_case(0, Arg2, determineProfit(Arg0, Arg1));
        }
	void test_case_1() { 
            int Arr0[] = {3,2};
            vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
            int Arr1[] = {1,2};
            vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
            int Arg2 = 1;
            verify_case(1, Arg2, determineProfit(Arg0, Arg1));
        }
	void test_case_2() {
            int Arr0[] = {3,3,3};
            vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
            int Arr1[] = {1,1,1};
            vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
            int Arg2 = 2;
            verify_case(2, Arg2, determineProfit(Arg0, Arg1));
        }
	void test_case_3() {
            int Arr0[] = {1000,500,250,125};
            vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
            int Arr1[] = {64,32,16,8};
            vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
            int Arg2 = 992;
            verify_case(3, Arg2, determineProfit(Arg0, Arg1));
        }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TimeTravellingCellar ___test;
    ___test.run_test(-1);
}
// END CUT HERE
