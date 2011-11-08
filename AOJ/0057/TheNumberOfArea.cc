#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

/**
 * n := 分割する直線の数
 *
 * A_0 = 1
 * A_n = A_(n-1) + n (n >= 1)
 */
int solve(int n)
{
    int ret = 1;

    for(int i = 1; i <= n; i++) 
        ret = ret + i;
    return ret;
}

int main()
{
    int d;
    while(cin >> d)
        cout << solve(d) << endl;
}
