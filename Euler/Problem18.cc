#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define W 200
#define H 200

int dp[W][H];

int solve(int h)
{
    for(int i = h-2; i >= 0; i--) {
        for(int j = 0; j < W; j++) {
            if(dp[i][j] == -1) continue;
            dp[i][j] = dp[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    return dp[1][1];
}

int main()
{
    int i = 1;
    string s;
    memset(dp, -1, sizeof(dp));
    while(getline(cin, s)) {
        stringstream ss(s);
        int n;
        int j = 1;
        while(ss >> n) {
            dp[i][j] = n;
            j++;
        }
        i++;
    }
    cout << solve(i) << endl;
    return 0;
}

