#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, s;

int dfs(int n, int i, int sum)
{
    int ret = 0;
    if(n == 0 and sum == s) return 1;
    if(i == 10 or n == 0) return 0;
    ret += dfs(n, i+1, sum);
    ret += dfs(n-1, i+1, sum+i);
    return ret;
}


int solve(int n, int s)
{
    return dfs(n, 0, 0);
}

int main()
{
    while(cin >> n >> s) {
        if(n == 0 and s == 0) break;
        cout << solve(n, s) << endl;
    }
    return 0;
}
