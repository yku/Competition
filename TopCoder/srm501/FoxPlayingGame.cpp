#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/**
 * Reference: http://techtipshoge.blogspot.com/2011/03/srm-brushup-foxplayinggame-501-div2.html
 * 方針: 正負に関わらずscoreAは全部足す
 *       scoreBは4つの選択肢がある
 *        1. 掛けると小さくなる(-1.0 < scoreB < 1.0)の範囲 => 掛けないのがよい
 *        2. 掛ければ掛けるほど大きくなる => 全部掛ける
 *        3. 2.と基本同じだが、符号の関係で掛ける回数を一つ減らす => (全部-1)掛ける
 *        4. 1回だけ掛ける。掛けると絶対値は小さくなるが符号逆転して正になる => 1回だけ掛ける
 */ 
class FoxPlayingGame {
public:
double theMax(int nA, int nB, int paramA, int paramB) {
    double scoreA = paramA / 1000.0;
    double scoreB = paramB / 1000.0;

    if(nA == 0) return 0;
    if(nB == 0) return nA * scoreA;

    double ret = nA * scoreA;
    ret = max(ret, nA * scoreA * pow(scoreB, nB));
    ret = max(ret, nA * scoreA * pow(scoreB, nB-1));
    ret = max(ret, nA * scoreA * scoreB);

    return ret;

}



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
