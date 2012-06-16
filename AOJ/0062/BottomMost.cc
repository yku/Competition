#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int solve(vector<int>& v)
{
    if(v.size() == 1) return v[0];
    vector<int> vv;
    
    for(int i = 0; i < v.size()-1; i++) 
        vv.push_back((v[i]+v[i+1])%10);

    return solve(vv);
}

int main()
{
    string s;
    
    while(getline(cin, s)) {
        vector<int> v;
        for(int i = 0; i < s.length(); i++) 
            v.push_back(s[i]-'0');
        cout << solve(v) << endl;
    }

    return 0;
}

