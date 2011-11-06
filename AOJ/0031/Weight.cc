#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

void solve(int w)
{
    vector<int> v;
    for(int i = 9; i >= 0; i--) {
        int a = (1 << i);
        if(w - a >= 0) {
            v.push_back(a);
            w -= a;
        }
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
        if(i != v.size() - 1) cout << " ";
    }
    cout << endl;
}

int main()
{
    int w;
    while(cin >> w) 
        solve(w);
    return 0;
}
