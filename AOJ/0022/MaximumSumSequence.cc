#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int solve(vector<int>& v)
{
    int sum = 0;
    int ret = -100001;
    for(int i = 0; i < v.size(); i++) {
        sum = max(sum+v[i], v[i]);
        ret = max(ret, sum);
    }
    return ret;
}

int main()
{
    int n;
    while(cin >> n, n) {
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

