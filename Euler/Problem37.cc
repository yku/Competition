#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int memo[1000001];

bool isPrime(int n)
{
    if(memo[n] == -1) return false;
    if(memo[n] == 1) return true;

    for(int i = 3; i*i <= n; i++) 
        if(n % i == 0) { memo[n] = -1; return false; }
    
    memo[n] = 1;
    return true;
}

bool solve(int n)
{
    int digits = 0;
    int t = n;
    while(t) {
        t /= 10;
        digits++;
    }
    if(digits <= 1 || !isPrime(n)) return false;
    for(int i = 1, base = 10; i < digits; i++, base *= 10) 
        if(!isPrime(n % base) || !isPrime(n / base)) return false;

    return true;
}

int main()
{
    int ans = 0;
    memset(memo, 0, sizeof(memo));
    memo[0] = memo[1] = -1;
    memo[2] = 1;
    for(int i = 4; i <= 1000001; i += 2)
        memo[i] = -1;

    for(int i = 0, cnt = 0; i <= 1000001 && cnt < 11; i++) {
        if(solve(i)) { ans += i; cnt++; }
    }
    cout << ans << endl;

    return 0;
}
