#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

// 10 = 2 x 5
int solve(int n)
{
    int a, b;
    a = b = 0;
    for(ll i = 1; i <= n; i++) {
        ll x = i;
        while(!(x%2) or !(x%5)) {
            if(!(x%2)) { a++; x /= 2; }
            else { b++; x /= 5; }
        }
    }
    return min(a, b);
}

int main()
{
    int n;
    while(cin >> n, n) {
        cout << solve(n) << endl;
    }
    return 0;
}

