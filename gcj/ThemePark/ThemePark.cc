#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
typedef long long ll;

/*
 * memo[i]...グループiを先頭グループとしたときの詰め込める人数
 * next[i]...グループiを先頭グループとし、最大まで詰め込んだグループの次に詰め込むグループを表す
 */
void makeMemo(vector<ll>& memo, vector<ll>& next, ll k, vector<ll>& g)
{
    ll n = g.size();
    memo.resize(n);
    next.resize(n);
    
    for(int i = 0; i < n; i++) {
        int j;
        memo[i] = 0;
        for(j = 0; j < n; j++) {
            if(memo[i] + g[(i+j)%n] > k) break;
            memo[i] += g[(i+j)%n];
        }
        next[i] = (i+j) % n;
    }
}

ll solve(const ll R, const ll k, vector<ll> g)
{
    vector<ll> memo, next;
    ll ret = 0;
    
    makeMemo(memo, next, k, g);
    
    ll idx = 0;
    for(ll i = 0; i < R; i++) {
        ret += memo[idx];
        idx = next[idx];
    }

    return ret;
}

int main()
{
    int T;

    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        ll R, k, N;
        vector<ll> g; 

        scanf("%lld %lld %lld", &R, &k, &N);
        for(int j = 0; j < N; j++) {
            int t;
            scanf("%d", &t);
            g.push_back(t);
        }
        cout << "Case #" << i << ": " << solve(R, k, g) << endl;
    }
    return 0;

}
