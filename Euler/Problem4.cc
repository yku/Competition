#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

/**
 * 3桁の掛け算でつくれる最大の回文となる数字を求めよ
 * 
 * ex) 2桁の場合は91x99=9009
 *
 * ans) 913x993 = 906609
 *
 * 100-999の掛け算の範囲は10000-998001となる。
 * 回文にするためには、偶数桁必要なので今回は6桁の数字のみ解候補となる
 * 回文は abccba となる値なので数字で表記すると
 *   100000a + 10000b + 1000c + 100c + 10b + a 
 * = 100001a + 10010b + 1100c
 * = 11 * (9091a + 910b + 100c) 
 * となり、6桁の回文は素数である11の倍数となる。
 * jに11の倍数となる数字を当てはめれば計算量を削減できる
 * i * j = i * (11 * x) = 11 * (i*x)
 */
int solve(int n)
{
    stringstream ss;
    string s;
    int len;
    ss << n;
    s = ss.str();
    len = s.length();
    if(len % 2) return 0; // 回文なので桁数が偶数でないなら駄目
    for(int i = 0; i < len; i++) {
        if(s[i] != s[len-1-i]) return 0;
    }
    return n;
}

int main()
{
    int ans = 0;
    for(int i = 100; i < 1000; i++) {
        for(int j = 110; j < 1000; j += 11) { // 指定された回文は素数11の倍数.11x10 , 11x11, 11x12...
            ans = max(solve(i*j), ans);
        }
    }
    cout << ans << endl;
    
    return 0;
}

