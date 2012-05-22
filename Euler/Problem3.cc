#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

/**
 * 1. 小さい数字から順に割り切れるまで割っていき、最後に割り切れた値を返せばOK
 *
 * ex) 10 = 2x2x5
 */

int solve(ll n)
{
    vector<int> v;

    while(n%2 == 0) {
        v.push_back(2);
        n /= 2;
    }
    for(ll i = 3; i <= n; i += 2) {
        while(n%i == 0) {
            v.push_back(i);
            n /= i;
        }
        if(!n) break;
    }
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    reverse(v.begin(), v.end());
    return v[0];
}

int main()
{
    ll n;

    cin >> n;
    cout << solve(n) << endl;

    return 0;
}

