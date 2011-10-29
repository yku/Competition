#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int solve(vector<int>& v)
{
    const int n = v.size();
    int dp[n];
    int ret = 0;

    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < n; j++) {
            if(i > j and v[i] > v[j]) {
                dp[i] = dp[j]+1;
                ret = max(ret, dp[i]);
            }
        }

    }
/* 
    for(int i = 0; i < n; i++)
        cout << dp[i] << " ";
    cout << endl;
*/
    return ret;

}

int main()
{
    int n;
    
    while(cin >> n) {
        vector<int> v;

        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        cout << solve(v) << endl;
    }
    return 0;
}

