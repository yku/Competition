#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;
typedef long long ll;

bool isTriangle(string s)
{
    int t = 0;
    for(int i = 0; i < s.length(); i++) {
        t += s[i] - 'A' + 1;
    }
    for(int i = 1; ; i++) {
        int tn = i * (i+1) / 2;
        if(tn == t) return true;
        if(tn > t) break;
    }

    return false;
}

int solve(vector<string>& v)
{
    int ret = 0;
    for(int i = 0; i < v.size(); i++)
        if(isTriangle(v[i])) ret++;
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

