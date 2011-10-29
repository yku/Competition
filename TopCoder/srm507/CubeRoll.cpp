#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define INF 100000
#define VISITED true
#define NON_VISIT !VISITED

class CubeRoll {
public:
int boundedCase(int lefthole, int initPos, int goalPos, int righthole) {
    bool holes[righthole + 1]; // hole range is from 1(min) to 50(max). +1 is hole 0. hole 0 is not used.
    unsigned int turns[righthole + 1];
    queue<int> q;

    fill(holes, holes + righthole + 1, NON_VISIT);     
    fill(turns, turns + righthole + 1, INF);     
    q.push(initPos);
    holes[initPos] = VISITED;
    turns[initPos] = 0;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int y = 1; x + y * y < righthole; y++) {
            int z = x + y * y;
            if(holes[z] == NON_VISIT) {
                q.push(z);
                holes[z] = VISITED;
                turns[z] = turns[x] + 1;
            }
        }

        for(int y = 1; x - y * y > lefthole; y++) {
            int z = x - y * y;
            if(holes[z] == NON_VISIT) {
                q.push(z);
                holes[z] = VISITED;
                turns[z] = turns[x] + 1;
            }
        } 
    }

    return turns[goalPos];
}

int unboundedCase(int distance) {
    
    // distance ... goal - init間の距離
    // distanceが平方数なら一回
    for(int i = 1; i * i <= distance; i++) {
        if( i * i == distance ) return 1;
    }

    // distanceが奇数なら必ず2回で移動可能
    // 平方数の差は奇数になるため。以下で説明する平方の差でk=1のときに相当
    // 例えば、
    // 1, 4, 9, 16, ... , n^2
    // 3, 5, 7, ... , 2n-1( = n^2 - (n - 1)^2)
    // left側に一回、right側に一回移動すれば任意の奇数移動できる
    //  => initとgoalは交換可能なため、left側を無限遠とみなす
    if(distance % 2 == 1) return 2;

    // distanceが平方の和で表せる場合は2
    for(int i = 1; i * i <= distance; i++) {
        for(int j = i; i * i + j * j <= distance; j++) {
            if( i * i + j * j == distance) return 2;
        }
    }

    // distanceが平方の差で表せる場合は2
    // 1^2, 2^2, 3^2, ... , n^2 をひっくりかえすと
    // n^2, (n-1)^2, ..., (n-k)^2, ..., 2^2, 1^2 とみなせ
    // 任意の平方の差は n^2 - (n-k)^2 = 2kn - k^2となる
    // 任意の平方の差でdistanceが表せると仮定すると
    // 2kn - k^2 = distance より n = (distance + k^2) / 2k 
    // ここでnは正の整数なため、右辺が2kで割り切れれば2手で到達可能
    // 1 <= k <= n, n^2 <= distance
    // ここの処理で検出できるのは、偶数かつ平方の差でのみ表現できる場合
    // ex. distance = 12 (= 4^2 - 2^2)
    // テストケースではケース5が該当
    for(int k = 1; k <= sqrt(distance); k++) {
        if((distance + k * k) % 2 * k == 0) return 2;
    }

    // それ以外は3手。平方数の差で任意の奇数(k=1)を移動(ここで2回)したあと、
    // +1移動すればよいから
    //  => 偶数かつ平方の和/差で移動できない距離 ex. 22
    return 1;
}

int getMinimumSteps(int initPos, int goalPos, vector <int> holePos) {
    int lefthole = -INF;
    int righthole = INF;

    if(initPos > goalPos) {
        // init -> goal と goal -> init にかかるコストは同じ
        // goal から init に移動したとみなせば交換可能
        swap(initPos, goalPos);
    }

    for(int i = 0; i < holePos.size(); i++) {
        int x = holePos[i];
        if(x < initPos) {
            lefthole = max(lefthole, x);
        } else if(x > goalPos) {
            righthole = min(righthole, x);
        } else {
            return -1;
        }

    }
    // 片方にしか穴がない状況
    if(lefthole == -INF || righthole == INF) {
        return unboundedCase(goalPos - initPos);
    }else{
        // 初期位置とゴールが穴に挟まれている状況
        return boundedCase(lefthole, initPos, goalPos, righthole);
    }
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(0, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 36; int Arg1 = 72; int Arr2[] = {300, 100, 200, 400}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 21; int Arr2[] = {38,45}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 98765; int Arg1 = 4963; int Arr2[] = {10,20,40,30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 68332; int Arg1 = 825; int Arr2[] = {99726,371,67,89210}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(4, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 99998; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(5, Arg3, getMinimumSteps(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CubeRoll ___test;
    ___test.run_test(-1);
}
// END CUT HERE
