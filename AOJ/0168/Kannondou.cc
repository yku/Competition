#include <iostream>
#include <cstring>

using namespace std;

// dp[n] := n段目まで登ったときの組み合わせ数
// dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
int solve(int n)
{
    int dp[n+1];

    memset(dp, 0, sizeof(dp));
    
    dp[1] = 1; 
    dp[2] = 2; 
    dp[3] = dp[2] + dp[1] + 1;
    for(int i = 4; i <= n; i++) 
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

    int days = dp[n]/10;
    if(dp[n]%10) days++;
    int years = days / 365;
    if(days%365) years++;

    return years;
}


int main()
{
    int n;

    while(cin >> n) {
        if(n == 0) break;
        cout << solve(n) << endl;
    }

    return 0;
}
