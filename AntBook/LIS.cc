// Longest Increasing Subsequence
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n = 5;
int a[] = { 4, 2, 3, 1, 5 };
int dp[5];

int solve(void)
{
    int ret = 0;
    memset(dp, 0, sizeof(dp));    
   
     /* 
     * dp[i] := 最後がa[i]番目の要素であるような最長の部分列の長さ
     * (1). a[i]からのみなるとき 1
     * (2). j < i かつ a[j] < a[i] のとき dp[i] := dp[j]+1
     * 
     * よって dp[i] := max{1, dp[j]+1 | j < i and a[j] < a[i]}
     */
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < n; j++) {
            if(i > j && a[i] > a[j]) { 
                dp[i] = dp[j]+1;
                ret = max(ret, dp[i]);
                // まとめてもOK.（もちろんこの場合は、dpの中身は書き換わり
                // maxの値がdpの最後の要素に格納される.dpの中身の意味はかわるのに注意)
                // dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    //return dp[n-1];
    return ret;
}

int main()
{
    cout << solve() << endl;
    return 0;
}


