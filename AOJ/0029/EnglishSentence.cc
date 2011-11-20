#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void solve(vector<string>& v)
{
    map<string, int> dict;
    string mode = "", longest = "";
    int mode_count = 0;
    for(int i = 0; i < v.size(); i++) {
        dict[v[i]]++;
    }
    map<string, int>::iterator it = dict.begin();
    while(it != dict.end()) {
        string word = (*it).first;
        int counts = (*it).second;
        if(mode_count < counts) { mode = word; mode_count = counts; }
        if(longest.length() < word.length()) longest = word;
        it++;
    }
    cout << mode << " " << longest << endl;
}

int main()
{
    vector<string> v;
    string s;
    while(cin >> s) {
        v.push_back(s);
    }
    solve(v);
    return 0;
}

