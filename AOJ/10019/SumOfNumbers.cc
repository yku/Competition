#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int solve(string s)
{
    int ret = 0;
    for(int i = 0; i < s.length(); i++) {
        ret += s[i] - '0';
    }
    return ret;
}

int main()
{
    string s;
    while(cin >> s) {
        if(s == "0") break;
        cout << solve(s) << endl;
    }

    return 0;
}

