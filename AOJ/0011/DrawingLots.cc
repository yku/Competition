#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

void solve(int w, int n, vector<pair<int, int> >& v)
{
    int lots[w+1];

    for(int i = 0; i <= w; i++) lots[i] = i;
    for(int i = 0; i < n; i++) {
        int a = v[i].first;
        int b = v[i].second;
        int t;
        t = lots[a]; 
        lots[a] = lots[b];
        lots[b] = t;
    }
    for(int i = 1; i <= w; i++) cout << lots[i] << endl;
}

int main()
{
    int w, n;
    while(cin >> w >> n) {
        vector<pair<int, int> > v;
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a;
            cin.ignore();
            cin >> b;
            v.push_back(pair<int, int>(a, b));
        }
        solve(w, n, v);
    }
    return 0;
}
