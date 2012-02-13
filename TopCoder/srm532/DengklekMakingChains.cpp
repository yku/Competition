#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class DengklekMakingChains {
public:
int maxBeauty(vector <string> chains) {
    int ret = 0;
    int middle = 0;
    vector<int> l, r;

    for(int i = 0; i < chains.size(); i++) {
        // ".9." こういった奴用
        for(int j = 0; j < 3; j++) {
            if(chains[i][j] != '.')
                ret = max(ret, chains[i][j] - '0');
        }

        // ".45"
        int sum = 0;
        bool f = true;
        for(int j = 2; j >= 0; j--) {
            if(chains[i][j] == '.'){ f = false;  break; }
            sum += chains[i][j] - '0';
        }

        if(f) {
            middle += sum;
        }else {
            l.push_back(sum);
        }

        // "35."
        sum = 0;
        f = true;
        for(int j = 0; j < 3; j++) {
            if(chains[i][j] == '.') { f = false; break; }
            sum += chains[i][j] - '0';
        }
        if(!f) r.push_back(sum);
    }

    /* for Testcase3
    for(int i = 0; i < l.size(); i++) {
        cout << l[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < r.size(); i++) {
        cout << r[i] << " ";
    }
    cout << endl;
    */
    for(int i = 0; i < l.size(); i++) {
        for(int j = 0; j < r.size(); j++) {
            if(i != j) {
                // "8.9"などがあった場合、左につけるのが正解だが、
                // 右側のチェインにも出現しているため。Case3が該当
                ret = max(ret, l[i] + middle + r[j]); 
            }
        }
    }

    return ret;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".15", "7..", "402", "..3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, maxBeauty(Arg0)); }
	void test_case_1() { string Arr0[] = {"..1", "7..", "567", "24.", "8..", "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(1, Arg1, maxBeauty(Arg0)); }
	void test_case_2() { string Arr0[] = {"...", "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxBeauty(Arg0)); }
	void test_case_3() { string Arr0[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, maxBeauty(Arg0)); }
	void test_case_4() { string Arr0[] = {"..1", "3..", "2..", ".7."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, maxBeauty(Arg0)); }
	void test_case_5() { string Arr0[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(5, Arg1, maxBeauty(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    DengklekMakingChains ___test;
    ___test.run_test(-1);
}
// END CUT HERE
