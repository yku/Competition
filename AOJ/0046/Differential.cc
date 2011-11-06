#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

double solve(vector<double>& v)
{
    sort(v.begin(), v.end());
    return (v[v.size()-1] - v[0]);
}

int main()
{
    vector<double> v;
    double h;
    while(cin >> h) {
        v.push_back(h);
    }
    cout << solve(v) << endl;
    return 0;
}
