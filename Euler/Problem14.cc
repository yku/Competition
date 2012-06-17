#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;

map<ll, int> memo;

int solve(ll n)
{
    if(n == 1) return 1;
    if(memo[n]) return memo[n];

    int ret = 0;
    if(n&1) ret = solve(3*n+1) + 1;
    else ret = solve(n/2) + 1;

    memo[n] = ret;
    return memo[n];
}

int main()
{
    int ret;
    int t = 0;
    
    for(int i = 1; i <= 1000000; i++) {
        if(t < solve(i)) {
            t = solve(i);
            ret = i;
        }
    }
    cout << ret << endl;
    return 0;
}

