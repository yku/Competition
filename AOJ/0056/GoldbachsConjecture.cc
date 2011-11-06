#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int n = 50000;
static bool primes[n];

void init_primes(void)
{
    fill(primes, primes+n, true);
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
    for(int i = 0; i <= x / 2; i++) {
        if(primes[i] and primes[x-i]) ret++;
    }
    return ret;
}


int main()
{
    int x;

    init_primes();
    while(cin >> x, x) {
        cout << solve(x) << endl;
    }
    return 0;
}
