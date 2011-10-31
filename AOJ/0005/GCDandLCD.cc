#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

ll gcd(ll m, ll n)
{
    if(n == 0) return m;
    else       return gcd(n, m%n);
}

/**
 * lcd = (m*n) / gcd
 *
 * ex) m = a*b, n = b*c
 * gcd = b
 * lcd = a*b*b*c/gcd = a*b*c
 */
int main()
{
    ll m, n;

    while(cin >> m >> n) {
        ll g, l;
        if(m > n) g = gcd(m, n);
        else      g = gcd(n, m);
        l = (m * n) / g;
        cout << g << " " << l << endl;
    }
    return 0;
}

