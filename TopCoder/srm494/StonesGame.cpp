#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class StonesGame {
public:
bool can(int M1, int M2, int N, int K)
{
    int distance = abs(M1 - M2);
    
    // M1とM2が両方ともKの範囲に収まらなければ勝てない
    if(distance > K) return false;

    // M1とM2で対称性を持てないなら勝てない
    // ex) K=3 X X [M1 X M2] X X => Kが奇数ならOK。偶数ならNG
    if((K+1)%2 != distance%2) return false;

    /* Kの開始インデックスと終了インデックスを求める */

    // distance+1はM1-M2間に含まれている石の個数。+1は真ん中の石に相当
    // min(M1, M2)は左側の石のインデックスを求める
    // K - (distance+1) はKの中に存在する石の中でM1-M2間に含まれない石の個数に相当
    // それを2で割ることで片方（この場合は左側)の石の個数をもとめている
    int start_idx = min(M1, M2) - (K - (distance+1)) / 2;
    if(start_idx < 1) return false;

    // 同様に右側も
    int end_index = max(M1, M2) + (K - (distance+1)) / 2;
    if(end_index > N) return false;

    return true;
}

string winner(int N, int M, int K, int L) {
    bool flag = true;
    // 最初の一手で勝てる場合はRomeo
    if(can(M, L, N, K)) return "Romeo";
    // 引き分けになる条件は、Strangeletの一手目で必ず勝てない場合
    // Strangeletが必ず勝てる=Romeoのどんな手に対しても解をもつ
    // 裏返せばRomeoの手に対して一つでも一回で勝てない手があれば引き分けとなる
    for(int pos = 1; pos <= N; pos++) {
        // 可能なRomeoの手M->posへ移動
        if(can(M, pos, N, K)) {
            // Romeoのある手に対してStrangletが一手で勝てないとき
            // pos->Lへ一回で移動できない
            if(!can(pos, L, N, K)) {
                return "Draw";
            }
        }
    }
    // Romeoが勝たず、引き分けでもない=Strangeletの勝利
    return "Strangelet";
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; string Arg4 = "Draw"; verify_case(0, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; string Arg4 = "Romeo"; verify_case(1, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2; int Arg3 = 3; string Arg4 = "Strangelet"; verify_case(2, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2; int Arg3 = 2; string Arg4 = "Draw"; verify_case(3, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 804588; int Arg2 = 705444; int Arg3 = 292263; string Arg4 = "Romeo"; verify_case(4, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1000000; int Arg1 = 100000; int Arg2 = 500000; int Arg3 = 600000; string Arg4 = "Strangelet"; verify_case(5, Arg4, winner(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    StonesGame ___test;
    ___test.run_test(-1);
}
// END CUT HERE
