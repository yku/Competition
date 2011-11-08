#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    vector<int> v, ans;
    int n, size = 0;
    while(cin >> n) {
        if(size < n) {
            size = n;
            v.resize(n+1);
        }
        v[n]++;
    }

    int max_val = v[0];
    for(int i = 0; i <= size; i++) 
        max_val = max(max_val, v[i]);
    
    for(int i = 0; i <= size; i++) 
        if(max_val == v[i]) ans.push_back(i);
    
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
