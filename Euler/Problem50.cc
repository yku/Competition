#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;
typedef long long ll;

#define MAX_N 1000001
bool primes[MAX_N];

void init(void)
{
    fill(primes, primes+sizeof(primes), true);
    primes[0] = primes[1] = false;
    for(int i = 2; i*i < MAX_N; i++) {
        if(primes[i]) {
            for(int j = 2; i*j < MAX_N; j++) 
                primes[i*j] = false;
        }
    }
}

int solve(int n)
{
    int t = 0;
    int c = 0;
    int b = 2;
    for(int i = 2; i <= n; i++) {
        if(primes[i]) {
            t += i;
            c++;
        }
        
        while(n < t) {
            if(primes[b]) {
                t -= b;
                c--;
            }
            b++;
        }
        if(t == n) return c;
    }
    return 0;
}

int main()
{
    init();
    
    int ans = 0;
    int max_t = 0;
    for(int i = 3; i < MAX_N; i += 2) {
        if(!primes[i]) continue;
        int t = solve(i);
        if(max_t < t) {
            max_t = t;
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}
