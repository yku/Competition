#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;

ll gcd(ll m, ll n)
{
    if(n > m) swap(m, n);
    if(n == 0) return m;
    else return gcd(n, m%n);
}
/**
 * m/n && gcd(10, n) == 1のとき純循環小数。
 * 循環小数の循環節の長さをeとすると
 * 10^e ≡1 (mod n) となる.
 *
 * [循環節の長さ]
 * m/nを循環小数とし、循環節の長さをeとする。m, nは互いに素。
 * 10^e*(m/n) - m/n = (10^e-1)*(m/n)は小数部が打ち消しあい整数となる。
 * m,nは互いに素なため、整数となるには10^e - 1がnで割り切れなければならない。
 * よって10^e - 1 ≡0 (mod n). 移行して10^e ≡1 (mod n)
 *
 * [純循環小数の条件]
 * 既約分数m/nを小数で表すと純循環小数になるとしたとき、
 * 10^e ≡1 (mod n) が成り立つ。
 * すなわち10^e = 1 + a*n を満たす整数aが存在する。
 * 10^e - a*n = 1より差分が1なので(10^e, a*n).
 * 10^e = 2^e*5^e
 * an => 2と5を素因数に含まない
 * よって(10, a) は互いに素でありまた(10, n)も互いに素。
 * gcd(10, n) == 1のとき純循環小数.
 *
 * [混循環小数の条件]
 * (10, n)が互いに素でないとき.このときnは2,5の倍数を少なくとも一つはふくむ.n = 2^r*5^s (r >= 1 or s >= 1).
 * よって混循環小数はa/n => a / (2^r*5^s*n') の既約分数であらわされる.
 * 補題1より a/(2^r*5^s*n') = b'/(2^r*5^s) + c'/n'
 * ... => 混循環小数は純循環小数と有限小数の和で表現されるので純循環小数を求めればよい
 * via. http://www2r.biglobe.ne.jp/kosanhp/math/junkan.pdf
 */
int solve(int d)
{
    if(gcd(10, d) != 1) return 0;
    ll t = 1;
    for(int i = 1; i < 1000; i++) {
        t *= 10;
        t %= d;
        if(t == 1) return i;
    }
    return -1;
}

int main()
{
    int ans;
    int t = 0;
   
    for(int i = 3; i <= 1000; i += 2) {
        if(t < solve(i)) { ans = i; t = solve(i); }
    }
    cout << ans << endl;

    return 0;
}

