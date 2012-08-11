#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;
typedef long long ll;

#define MAX_N 1000001
vector<int> primes;

void init(void)
{
    bool d[MAX_N];
    fill(d, d+sizeof(d), true);
    d[0] = d[1] = false;
    for(int i = 2; i*i < MAX_N; i++) {
        if(d[i]) {
            for(int j = 2; i*j < MAX_N; j++) 
                d[i*j] = false;
        }
    }
    for(int i = 0; i < MAX_N; i++)
        if(d[i]) primes.push_back(i);

}

int solve(int n)
{
    int t = 0, c = 0, b = 0;
    for(int i = 0; i < primes.size() and primes[i] <= n; i++) {
        t += primes[i];
        c++;
        while(n < t) {
            t -= primes[b++];
            c--;
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
    
    for(int i = 0; i < primes.size(); i++) {
        int t = solve(primes[i]);
        if(max_t < t) {
            max_t = t;
            ans = primes[i];
        }
    }
    cout << ans << endl;

    return 0;
}
