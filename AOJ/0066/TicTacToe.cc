#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

char solve(string s)
{

    for(int i = 0; i < 3; i++) {
        // 縦
        if((s[i] == s[i+3] && s[i+3] == s[i+6]) && s[i] != 's') return s[i];
        // 横 
        if((s[i*3] == s[i*3+1] && s[i*3+1] == s[i*3+2]) && s[i*3] != 's') return s[i*3];
    }
    if(((s[0] == s[4] && s[4] == s[8]) || (s[2] == s[4] && s[4] == s[6])) && s[4] != 's') return s[4];
    
    return 'd';
}

int main()
{
    string s;

    while(getline(cin, s)) {
        cout << solve(s) << endl;
    }
    return 0;
}

