#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll pow(ll x, ll n) 
{
    if(n == 0) return 1;
    else return x * pow(x, n - 1);
}

string solve(int N, int K) 
{
    ll p = pow(2, N);
    if(K % p == (p - 1)) return "ON";
    else                 return "OFF";
}

int main()
{
    int T;

    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        int N, K;

        scanf("%d %d", &N, &K);
        cout << "Case #" << i << ": " << solve(N, K) << endl;
    }
    return 0;
}
