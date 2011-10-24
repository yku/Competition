#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll solve(ll L, ll t, int N, int C, vector<ll> a)
{
    vector<ll> v;
    ll totalhour = 0;
    
    for(int i = 0; i < N; i++) {
        totalhour += a[i%C] * 2;
        if(totalhour > t) v.push_back(min(a[i%C]*2, totalhour - t));
    }
    sort(v.begin(), v.end(), greater<int>());
    
    /*
     * If L > v.size(), v[i] is out of range v. So, result is incorrect!
     * example) large case 37: L=979006 v.size = 938479
     * for(int i = 0; i < L; i++) {
     *    totalhour -= v[i] / 2;
     * }
     */
    for(int i = 0; i < L && i < v.size(); i++) {
        totalhour -= v[i] / 2;
    }

    return totalhour;
}

int main()
{
    int cases;

    scanf("%d", &cases);

    for(int c = 1; c <= cases; c++) {
        ll L, t;
        int N, C;
        vector<ll> a;
        ll ret;
        scanf("%lld %lld %d %d", &L, &t, &N, &C);
        for(int i = 0; i < C; i++) {
            ll n;
            scanf("%lld", &n);
            a.push_back(n);
        }
        ret = solve(L, t, N, C, a);
        cout << "Case #" << c << ": " << ret << endl;
    }
    return 0;
}
