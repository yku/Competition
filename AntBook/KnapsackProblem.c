#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b
#define MAX_N 4
#define MAX_W 5

int dp[MAX_N + 1][MAX_W + 1];

int rec(int w[], int v[], int n, int i, int rest)
{
    int ret;
    
    if(dp[i][rest] >= 0) { return dp[i][rest]; }

    if(i == n) {
        // 品物残っていない（末尾）
        ret = 0;
    }else if(rest < w[i]) {
        // 品物入りきらない
        ret = rec(w, v, n, i+1, rest);
    }else {
        // 品物入れない場合と入れる場合
        ret = max(rec(w, v, n, i+1, rest), rec(w, v, n, i+1, rest - w[i]) + v[i]);
    }
    dp[i][rest] = ret;
    return ret;
}

int solve(int w[], int v[], int n, int W) 
{
    memset(dp, -1, sizeof(dp));
    return rec(w, v, n, 0, W);
}

int solve2(int w[], int v[], int n, int W)
{
    int i, rest;
    for(i = n - 1; i >= 0; i--) {
        for(rest = 0; rest <= W; rest++) {
            if(rest < w[i]) {
                dp[i][rest] = dp[i+1][rest];
            }else {
                dp[i][rest] = max(dp[i+1][rest], dp[i+1][rest - w[i]] + v[i]);
            }
        }
    }
    return dp[0][W];
}

int main()
{
    int w[] = { 2, 1, 3, 2, };
    int v[] = { 3, 2, 4, 2, };
    int n = 4, W = 5;
    int ret; 

    ret = solve(w, v, n, W);
    printf("%d\n", ret);
    ret = solve2(w, v, n, W);
    printf("%d\n", ret);
}
