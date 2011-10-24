#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(int n, vector<pair<int, int> >& v)
{
    int ret;
    int x = 0;

    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        int p = v[i].first;
        int c = v[i].second;
        if(0 <= x && x <= c-1) {
            x = x + p - 1;
        }else if(c <= x && x <= p+c-2) {
            x = x - c;
        }
    }
    ret = n - x;
    return ret;
}


int main()
{
    while(true) {
        int n, r;
        vector<pair<int, int> > cuts;
        cin >> n >> r;
        if(n == 0 && r == 0) break;
        for(int i = 0; i < r; i++) {
            int p, c;
            cin >> p >> c;
            cuts.push_back(pair<int, int>(p, c));
        }
        cout << solve(n, cuts) << endl;
    }
}
