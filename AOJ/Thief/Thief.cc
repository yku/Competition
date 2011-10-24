#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

// 通らない。なぜ？？
void solve(vector<pair<int, int> >& v, int W)
{
    int dp[v.size()+1][W+1];
    int total, n;

    n = v.size();
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) {
        int val = v[i].first;
        int weight = v[i].second;
        for(int j = 0; j <= W; j++) {
            if(j-weight >= 0) {
                dp[i+1][j] = max(dp[i][j], dp[i][j-weight] + val);
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    for(int j = W; j >= 0; j--) {
        if(dp[n][W] == dp[n][j]) 
            total = j;
    }

    cout << dp[n][W] << endl;
    cout << total << endl;
}

int main()
{
    int W, N, c;

    while(true) {
        cin >> W;
        if(W == 0) break;

        cin >> N;

        vector<pair<int, int> > v;
        for(int i = 0; i < N; i++) {
            int value, weight;

            cin >> value;
            cin.ignore();
            cin >> weight;
            v.push_back(pair<int, int>(value, weight));
        }
        cout << "Case " << ++c << ":" << endl;
        solve(v, W);
    }

    return 0;
}
