#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int n = 1000000;
static bool primes[n];

void init_primes(void)
{
    primes[0] = primes[1] = false;
    for(int i = 2; i < n; i++) {
        if(primes[i]) {
            for(int j = 2; i*j < n; j++) 
                primes[i*j] = false;
        }
    }
}

int solve(int x)
{
    int ret = 0;
    for(int i = 0; i <= x; i++)
        if(primes[i]) ret++;
    return ret;
}

int main()
{
    int x;
    fill(primes, primes+n, true);
    init_primes();
    while(cin >> x) {
        cout << solve(x) << endl;
    }
    return 0;
}

