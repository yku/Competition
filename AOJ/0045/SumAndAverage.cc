#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

void solve(vector<pair<int, int> > v)
{
    int sum = 0, avg = 0;
    for(int i = 0; i < v.size(); i++) {
        int value = v[i].first, num = v[i].second;
        sum += value * num;
        avg += num;
    }
    avg = ((double)avg / (double)v.size() + 0.5);
    cout << sum << endl << avg << endl;
}

int main()
{
    int v, n;
    char c;
    vector<pair<int, int> > vec;
    while(cin >> v >> c >> n) {
        vec.push_back(pair<int,int>(v, n)); 
    }
    solve(vec);
    return 0;
}

