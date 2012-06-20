#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int memo[10];

bool solve(int n)
{
    int t(n);
    int a = 0;
    while(t) {
       a += memo[t % 10];
       t /= 10;
    }
    if(a == n) return true;
    return false;
}

int main()
{
    int ans = 0;
    fill(memo, memo+10, 1);
    memo[0] = 0;
    for(int i = 1; i < 10; i++) 
        for(int j = 0; j < 5; j++) 
            memo[i] *= i;
    for(int i = 2; i < 1000000; i++)
        if(solve(i)) ans += i;
    cout << ans << endl;
    return 0;
}

