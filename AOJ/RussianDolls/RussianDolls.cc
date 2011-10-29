#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

/**
 * dp[i] := $B?M7A(Ba[i]$B$,4^$`$3$H$N$G$-$k:GBg$N?M7A$N?t(B
 * 1. dp[i] := 1 if $B$I$N?M7A$b4^$`$3$H$,$G$-$J$$$H$-(B($B<+J,<+?H$N$_!K(B
 * 2. dp[i] := dp[j]+1 if a[i] > a[j].$B$?$@$7!"(Ba$B$O>:=g$K%=!<%H:Q$_(B
 */
int solve(vector<pair<int, int> > &dolls)
{
    int n = dolls.size();
    int dp[n];
    int ret = 0;
    int wrong = 0;

    fill(dp, dp+n, 1);
    for(int i = 0; i < n; i++) {
        int h1 = dolls[i].first;
        int r1 = dolls[i].second;
        
        for(int j = 0; j < n; j++) {
            int h2 = dolls[j].first;
            int r2 = dolls[j].second;

            if(h1 > h2 and r1 > r2) {
                dp[i] = max(dp[i], dp[j] + 1);
                //ret = max(ret, dp[i]); <-$B$3$l$ODL$i$J$+$C$?(B.$B0l$D$b4^$a$k$3$H$,$G$-$J$$>l9g!"(Bret$B$,99?7$5$l$:(B0$B$rJV$9$+$i(B. $B$b$7DL$7$?$$$J$i(Bret=1$B$G=i4|2=$9$l$P(Bok
                //wrong = max(wrong, dp[i]);
            }
        }
        ret = max(ret, dp[i]);
    }
   
    //cout << "[wrong]=" << wrong << " [ret]=" << ret << endl;

    return ret;
}

int main()
{
    while(true) {
        int n, m;
        vector<pair<int, int> > dolls;

        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++) {
            int h, r;
            cin >> h >> r;
            dolls.push_back(pair<int,int>(h, r));
        }
        cin >> m;
        for(int i = 0; i < m; i++) {
            int h, r;
            cin >> h >> r;
            dolls.push_back(pair<int,int>(h, r));
        }
        sort(dolls.begin(), dolls.end(), cmp);
        cout << solve(dolls) << endl;
    }
    return 0;
}
