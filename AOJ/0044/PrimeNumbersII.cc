#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int n = 50021;
static bool primes[n+1];

void init_primes(void)
{
    fill(primes, primes+(n+1), true);
    primes[0] = primes[1] = false;
    for(int i = 2; i <= n; i++) {
        if(primes[i]) {
            for(int j = 2; i*j <= n; j++) 
                primes[i*j] = false;
        }
    }
}

void solve(int x)
{
    for(int i = x-1; i >= 2; i--) {
        if(primes[i]) { cout << i; break; }
    }
    cout << " ";
    for(int i = x+1; i <= n; i++) {
        if(primes[i]) { cout << i; break; }
    }
    cout << endl;
}

int main()
{
    int x;
    init_primes();
    while(cin >> x) {
        solve(x);
    }
    return 0;
}

