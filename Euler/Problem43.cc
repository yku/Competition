#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;
typedef long long ll;

int d[] = {2, 3, 5, 7, 11, 13, 17};

bool isValid(string s)
{
    if(s[0] == '0') return false;
    for(int i = 1; i <= 7; i++) {
        stringstream ss;
        int x;
        ss << s.substr(i, 3);
        ss >> x;
        if(x % d[i-1]) return false;
    }
    
    return true;
}

int main()
{
    //string s = "1406357289";
    ll ans = 0;
    string s = "0123456789";
    do {
        if(isValid(s)) {
            stringstream ss(s);
            ll t;
            ss >> t;
            ans += t;
        }
    } while(next_permutation(s.begin(), s.end()));
    cout << ans << endl;
    return 0;
}

