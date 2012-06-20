#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

int memo[10];

int factorial(int n)
{
    if(memo[n]) return memo[n];
    if(n==0 || n==1) return 1;
    memo[n] = n * factorial(n-1);
    return memo[n];
}
/**
 *  9999999 = 9!*7 = 2540160
 * 99999999 = 9!*8 = 2903040
 * 8桁以上は元の数の増加分に階乗の和が追いつかない
 * => 7桁目が上限値
 */
bool isCurious(ll n)
{
    ll t(n);
    ll tt = 0;
    while(t) {
        tt += factorial(t%10);
        t /= 10;
    }
    if(tt == n) return true;
    return false;
}
int main()
{
    int ret = 0;
    memset(memo, 0, sizeof(memo)); 
    for(int i = 3; i < 10000000; i++) {
        if(isCurious(i)) { ret += i; }
    }
    cout << ret << endl;
    return 0;
}
