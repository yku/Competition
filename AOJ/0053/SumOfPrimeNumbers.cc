#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int n = 1300000;
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

int solve(int x)
{
    int ret = 0;
    for(int i = 2; x; i++) {
        if(primes[i]) {
            ret += i;
            x--;
        }
    }
    return ret;    
}

int main()
{
    int x;
    init_primes();
    while(cin >> x, x) 
        cout << solve(x) << endl;
    return 0;
}
