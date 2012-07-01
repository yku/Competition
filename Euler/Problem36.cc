#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;
typedef long long ll;
bool isPalindrome(string s)
{
    for(int i = 0, j = s.length() - 1; i < s.length(); i++) {
        if(s[i] != s[j-i]) return false;
    }
    return true;
}

string binary(int n)
{
    string ret = "";
    while(n) {
        ret += (n % 2) - '0';
        n /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    ll ans = 0;
    for(int i = 1; i <= 1e6; i++) {
        stringstream ss;
        ss << i;
        if(isPalindrome(ss.str()) && isPalindrome(binary(i))) ans += i;
    }
    cout << ans << endl;
    return 0;
}
