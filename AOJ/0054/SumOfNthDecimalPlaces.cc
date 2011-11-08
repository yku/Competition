#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// http://d.hatena.ne.jp/ty70/20110425/1303753958
// 割り算の筆算を利用
int solve(int a, int b, int n)
{
    int S = 0;

    a *= 10;
    for(int i = 0; i < n; i++) {
        S += (a / b) % 10;
        a %= b;
        a *= 10;
    }

    return S;
}

int main()
{
    int a, b, n;
    while(cin >> a >> b >> n) {
        cout << solve(a, b, n) << endl;
    }
    return 0;
}
