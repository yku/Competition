#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class TrainingCamp {
public:
vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics) {
    vector<string> ret; 

    for(int i = 0; i < attendance.size(); i++) {
        string student = attendance[i];
        string tmp = "";
        for(int j = 0; j < problemTopics.size(); j++) {
            string problem = problemTopics[j];
            bool flag = true;
            for(int k = 0; k < student.size(); k++) {
                if(problem[k] == 'X' and student[k] != 'X') flag = false;
            }
            if(flag) tmp += 'X';
            else     tmp += '-';
        }
        ret.push_back(tmp);
    }

    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"XXX",
 "XXX",
 "XX-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"---",
 "XXX",
 "-XX",
 "XX-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"XXXX", "XXXX", "X--X" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, determineSolvers(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"-XXXX",
 "----X",
 "XXX--",
 "X-X-X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X---X",
 "-X---",
 "XXX--",
 "--X--"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"-X-X", "----", "-XXX", "X--X" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, determineSolvers(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"-----",
 "XXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"XXXXX",
 "-----",
 "--X-X"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"-X-", "XXX" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, determineSolvers(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"-",
 "X",
 "X",
 "-",
 "X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-",
 "X"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"X-", "XX", "XX", "X-", "XX" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, determineSolvers(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"X----X--X",
 "X--X-X---",
 "--X-X----",
 "XXXX-X-X-",
 "XXXX--XXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X----X-X-",
 "-----X---",
 "-X----X-X",
 "-X-X-X---",
 "-----X---",
 "X-------X"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"-X--XX", "-X--X-", "------", "XX-XX-", "--X--X" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, determineSolvers(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TrainingCamp ___test;
    ___test.run_test(-1);
}
// END CUT HERE
