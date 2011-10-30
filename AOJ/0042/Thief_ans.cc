#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int W;

    for(int t=1 ; scanf("%d", &W) , W ; t++ ){
        int n, v[1001]={0}, w[1001]={0};
        int dp[1001][1001] = {0};

        scanf("%d", &n);
        for(int i=0 ; i < n ; i++ ){
            scanf("%d,%d", &v[i] , &w[i] );
        }
        for(int i=0 ; i < n ; i++ ){
            for(int j=0 ; j <= W ; j++ ){
                if( j < w[i] ){
                    dp[i+1][j] = dp[i][j];
                }else{
                    dp[i+1][j] = max( dp[i][j] , dp[i][j-w[i]] + v[i] );
                }
            }
        }
        int total;
        for(int j=W ; j >= 0 ; j-- ){
            if( dp[n][W] == dp[n][j] ){
                total = j; 
            }
        }
        printf("Case %d:\n%d\n%d\n", t , dp[n][W] , total );
    }
}
