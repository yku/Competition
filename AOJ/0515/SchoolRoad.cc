#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int solve(int a, int b, vector<pair<int, int> >& v)
{
    int dp[b+1][a+1];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
  
    // 通行できないところは-1で表現する
    for(int i = 0; i < v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;
        if((x == 1 and y == 1) or (x == a and y == b)) return 0;
        dp[y][x] = -1;
    }
    
    for(int i = 1; i <= b; i++) {
        for(int j = 1; j <= a; j++) {
            if(dp[i][j] != -1) {
                if(dp[i][j-1] != -1) dp[i][j] += dp[i][j-1];
                if(dp[i-1][j] != -1) dp[i][j] += dp[i-1][j];
            }
        }
    }
    return dp[b][a];
}

int main()
{
    int a, b;
    while(cin >> a >> b) {
        if(a == 0 and b == 0) break;
        int n;
        vector<pair<int, int> > v;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v.push_back(pair<int,int>(x, y));
        }
        cout << solve(a, b, v) << endl;
    }
    return 0;
}
