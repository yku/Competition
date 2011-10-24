#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

typedef long long ll;
using namespace std;

ll solve(ll M, int C, ll W, vector<pair<ll, ll> >& cuts)
{
    reverse(cuts.begin(), cuts.end());
    for(int i = 0; i < C; i++) {
        ll A = cuts[i].first;
        ll B = cuts[i].second;
        
        if(1 <= W && W <= B) {
            W = W + A - 1;
        }else if(B+1 <= W && W <= A+B-1) {
            W = W - B;
        }
    }

    return W;
}

int main()
{
    int T;

    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        int C;
        ll M, W;
        vector<pair<ll, ll> > cuts;
        scanf("%lld %d %lld", &M, &C, &W);
        for(int c = 0; c < C; c++) {
            ll A, B;
            scanf("%lld %lld", &A, &B);
            cuts.push_back(pair<ll, ll>(A, B));
        }
        cout << "Case #" << i << ": " << solve(M, C, W, cuts) << endl;
    }
}
