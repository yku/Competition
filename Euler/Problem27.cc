#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
bool isPrime(int n)
{
    n = abs(n);
    if(n <= 1 || n % 2 == 0) return false;
    if(n == 2) return true;
    for(int i = 3; i*i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

int main()
{
    int primes = 0;
    ll ans;
    for(int a = -999; a <= 999; a++) {
        for(int b = -999; b <= 999; b++) {
            int t = 0;
            for(int i = 0; ; i++) {
                int p = i*i + a*i + b;
                if(isPrime(p)) t++;
                else break;
            }
            if(primes < t) {
                primes = t;
                ans = a * b;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

