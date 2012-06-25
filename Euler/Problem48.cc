#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

ll M = 1e10;

int main()
{
    ll ans = 0;
    for(int i = 1; i <= 1000; i++) {
        ll t = i;
        for(int j = 1; j < i; j++) {
            t *= i;
            t %= M;
        }
        ans += t;
        ans %= M;
    }
    cout << ans << endl;

    return 0;
}

