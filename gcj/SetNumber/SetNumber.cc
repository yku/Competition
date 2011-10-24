#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

bool isPrime(ll n)
{
    ll i;

    if(n < 2)
        return false;
    else if(n == 2)
        return true;

    if(n % 2 == 0)
        return false;

    for(i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;
    return true;
}

ll solve(const ll A, const ll B, const ll P, vector<ll>& primes)
{
    ll ret = B - A + 1;
    cout << "HELLO" << endl;
    bool groups[B-A+1];
    for(ll i = 0; i < B-A+1; i++)
        groups[i] = false;

    for(ll i = 0; i < primes.size(); i++) {
        if(primes[i] >= P and primes[i] <= B) {
            ll diff = 0;
            bool groupexist = false;
            for(ll j = A; j <= B; j++) {
                if(j % primes[i] == 0) {
                    if(groups[j-A] == false) {
                        diff++;
                        groups[j-A] = true;
                    }else{
                        groupexist = true;
                    }
                }
            }
            ret = ret - diff;
            // 新しいグループが増えるとき+1
            // 既存のグループに組み込まれるときは+0
            if(!groupexist and diff != 0){ ret += 1; }
        }
    }

    return ret;
}

int main()
{
    int C;
    vector<ll> primes;

    scanf("%d", &C);

    for(ll i = 0; i < 10e+6; i++)
        if(isPrime(i)) primes.push_back(i);

    for(int i = 1; i <= C; i++) {
        ll A, B, P;
        scanf("%lld %lld %lld", &A, &B, &P);
        cout << "Case #" << i << ": " << solve(A, B, P, primes) << endl;
    }

    return 0;
}
