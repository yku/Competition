#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

// ヨセフスの問題
// http://ja.wikipedia.org/wiki/%E3%83%A8%E3%82%BB%E3%83%95%E3%82%B9%E3%81%AE%E5%95%8F%E9%A1%8C
// TODO: 理解しきれていないので復習要
int f(int n, int m)
{
    if(n == 1) return 0;
    else return ((f(n-1, m) + m) % n);
}

int solve(int n, int m)
{
    return f(n, m) + 1;
}

int main()
{
    int n, m;
    while(cin >> n >> m, n || m) {
        cout << solve(n, m) << endl;
    }

    return 0;
}
