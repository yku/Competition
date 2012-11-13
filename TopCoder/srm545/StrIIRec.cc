#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


class StrIIRec {
public:
/**
 * 先頭から順に一文字ずつ小さいのからくっつけていく
 */
string recovstr(int n, int minInv, string minStr) {
    string ret = "";
    bool used[26];
    
    fill(used, used+sizeof(used), false);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!used[j]) {
                string t = ret;
                t += (char)('a'+j);
                
                // これまでに作った文字列＋付け加える一文字＋残りを降順に並べた物
                for(int k = n-1; k >= 0; k--)
                    if(j != k && !used[k]) t += (char)('a'+k);
                
                //cout << t << " " << minStr << endl;
                if(t < minStr) {
                    continue;
                }
                
                int cnt = 0;
                for(int a = 0; a < n; a++) {
                    for(int b = a+1; b < n; b++) {
                        if(t[a] > t[b]) cnt++;
                    }
                }

                if(cnt >= minInv) {
                    used[j] = true;
                    ret += (char)('a'+j);
                    break;
                }
            }
        }
        //cout << ret.length() << "," << i+1 << endl;
        // i+1の値==発見済みの文字列の長さ => 異なる場合は発見できなかったので中断
        if((int)ret.length() != i+1) break;
    }

    bool check = true;
    check &= (int)ret.length() == n;
    check &= ret >= minStr;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(ret[i] > ret[j]) cnt++;
        }
    }
    check &= cnt >= minInv;
    return check ? ret : "";
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; string Arg2 = "ab"; string Arg3 = "ba"; verify_case(0, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 1; string Arg2 = "efcdgab"; string Arg3 = "efcdgabhi"; verify_case(1, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 11; int Arg1 = 55; string Arg2 = "debgikjfc"; string Arg3 = "kjihgfedcba"; verify_case(2, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 0; string Arg2 = "e"; string Arg3 = "eabcdfghijklmno"; verify_case(3, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 9; int Arg1 = 20; string Arg2 = "fcdebiha"; string Arg3 = "fcdehigba"; verify_case(4, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 16; int Arg1 = 64; string Arg2 = "k"; string Arg3 = "kabcdopnmljihgfe"; verify_case(5, Arg3, recovstr(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    StrIIRec ___test;
    ___test.run_test(-1);
}
// END CUT HERE
