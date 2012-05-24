#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

const int n = 2000001;
bool primes[n];

void init(void)
{
    fill(primes, primes+n, true);
    primes[0] = primes[1] = false;
    for(int i = 2; i < n; i++)
        if(primes[i]) {
            for(int j = 2; i*j < n; j++)
                primes[i*j] = false;
        }
}

int main()
{
    ll ret = 0;

    init();
    for(int i = 0; i < n-1; i++) {
        if(primes[i]) ret += i;
    }
    cout << ret << endl;
       
    return 0;
}

