#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*
 * 方針: signature + 1個分答えの数字がある。
 * 1. signatureに関わらずIIII...IIIとみなし初期値として1を基点に単調増加
 * 2. signatureがDなら隣り合う数字をスワップ。Dが連続するなら末尾まで->バブルソート
 */
class PermutationSignature {
public:
vector <int> reconstruct(string signature) {
    vector<int> ret;

    for(int i = 0; i < signature.size() + 1; i++) 
        ret.push_back(i+1);

    for(int i = 0; i < signature.size(); i++) {
        for(int j = 0; j < signature.size(); j++) {
            if(signature[j] == 'D' && ret[j] < ret[j+1]) {
                int tmp = ret[j];
                ret[j] = ret[j+1];
                ret[j+1] = tmp;
            }
        }
    }

    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "IIIII"; int Arr1[] = {1, 2, 3, 4, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, reconstruct(Arg0)); }
	void test_case_1() { string Arg0 = "DI"; int Arr1[] = {2, 1, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, reconstruct(Arg0)); }
	void test_case_2() { string Arg0 = "IIIID"; int Arr1[] = {1, 2, 3, 4, 6, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, reconstruct(Arg0)); }
	void test_case_3() { string Arg0 = "DIIDID"; int Arr1[] = {2, 1, 3, 5, 4, 7, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, reconstruct(Arg0)); }
	void test_case_4() { string Arg0 = "DDD"; int Arr1[] = {4, 3, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, reconstruct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PermutationSignature ___test;
    ___test.run_test(-1);
}
// END CUT HERE
