#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

string solve(string s)
{
    string ret = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '@') {
            int n = s[++i] - '0';
            i++;
            while(n--) ret += s[i];
        }else{
            ret += s[i];
        }
    }

    return ret;
}

int main()
{
    string s;
    while(cin >> s) {
        cout << solve(s) << endl;
    }
    return 0;
}

