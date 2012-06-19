#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
ll solve(vector<string>& v)
{
    int ret = 0;
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        string s = v[i];
        int t = 0;
        for(int j = 0; j < s.length(); j++) {
            t += s[j] - 'A'+1; 
        }
        t = t * (i+1);
        ret += t;
    }
    return ret;
}

int main()
{
    vector<string> v;
    string s;
    while(cin >> s) {
        replace(s.begin(), s.end(), ',', ' ');
        replace(s.begin(), s.end(), '"', ' ');
        stringstream ss(s);
        string buf;
        while(ss >> buf) 
            v.push_back(buf);
    }
    cout << solve(v) << endl;
    return 0;
}

