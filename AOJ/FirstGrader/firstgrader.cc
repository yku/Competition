#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

/*
 * dp[i][n] := i番目の要素で値nを作れる組み合わせの総和と定義
 */
ll solve(vector<int>& v)
{
    int n = v.size() - 1;
    ll dp[n+1][21];

    memset(dp, 0, sizeof(dp));


    dp[0][v[0]] = 1;
    
    /*
     * iが0始まりだと間違い
     * +v[0]はない。
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= 20; j++) {
            if(j+v[i] <= 20) 
                dp[i+1][j+v[i]] += dp[i][j];
            if(j-v[i] >= 0)
                dp[i+1][j-v[i]] += dp[i][j];
        }
    }*/

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= 20; j++) {
            if(j+v[i] <= 20) 
                dp[i][j+v[i]] += dp[i-1][j];
            if(j-v[i] >= 0)
                dp[i][j-v[i]] += dp[i-1][j];
        }
    }

    return dp[n-1][v[n]];
}

int main()
{
    int N, t;
    vector<int> v;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> t;
        v.push_back(t);
    }
    cout << solve(v) << endl;
    return 0;
}
