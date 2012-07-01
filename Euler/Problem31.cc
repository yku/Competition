#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int pence[] = {200, 100, 50, 20, 10, 5, 2, 1};
const int pence2[] = {1, 2, 5, 10, 20, 50, 100, 200};
/**
 * recursive
 */
int solve(int n, int rest)
{
    if(rest == 0) return 1;
    if(rest < 0 || n == 8) return 0;
    int ret = 0;
    int c = rest / pence[n];
    for(int i = 0; i <= c; i++) {
        ret += solve(n+1, rest - i * pence[n]);
    }
    return ret;
}

/**
 * dynamic programming
 */
int dp[201]; // dp[i] = 金額iの支払い方の総和
int solve2(void)
{
    memset(dp, 0, sizeof(dp)); 
    dp[0] = 1; // コイン一枚で支払う回数に相当

    for(int i = 0; i < 8; i++) 
        for(int j = pence2[i]; j <= 200; j++) 
            dp[j] += dp[j-pence2[i]];
    
    return dp[200];
}

/**
 * dp[i][j] = i番目までのコインをつかって金額jを支払う組み合わせの総数
 * solve3()を簡略化したのがsolve2()
 */
int solve3(void)
{
    int dp2[8][201];
    memset(dp2, 0, sizeof(dp2));
    // 計算の都合上,コインiをつかって金額0を支払う組み合わせは1とする
    for(int i = 0; i <= 200; i++) dp2[0][i] = 1;
    
    for(int i = 1; i < 8; i++) {
        for(int j = 0; j <= 200; j++) {
            if(j - pence2[i] >= 0)
                dp2[i][j] = dp2[i-1][j] + dp2[i][j-pence2[i]];
            else
                dp2[i][j] = dp2[i-1][j];
        }
    }
    return dp2[7][200];
}

int main()
{
    cout << solve(0, 200) << endl;
    cout << solve2() << endl;
    cout << solve3() << endl;
    return 0;
}
