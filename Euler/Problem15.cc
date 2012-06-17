#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
// 点の数はグリッド数+1
#define W 20+1
#define H 20+1
ll dp[H][W];

int main()
{
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < W; i++) dp[0][i] = 1;
    for(int i = 0; i < H; i++) dp[i][0] = 1;

    for(int i = 0; i < H-1; i++) 
        for(int j = 0; j < W-1; j++) 
            dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1];
    cout << dp[H-1][W-1] << endl;
    return 0;
}

