#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int ret = 0;
    string s;
    while(getline(cin, s)) {
        bool f = true;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != s[s.length()-1-i]) { f = false; break; }
        }
        if(f) ret++; 
    }
    cout << ret << endl;
    return 0;
}

