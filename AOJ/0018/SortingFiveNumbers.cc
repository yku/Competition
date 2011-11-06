#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve(vector<int>& v)
{
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << " ";
    }
    cout << v[v.size()-1] << endl;
}

int main()
{
    int n;
    vector<int> v;
    for(int i = 0; i < 5; i++) {
        cin >> n;
        v.push_back(n);
    }
    solve(v);
}
