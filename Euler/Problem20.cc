#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
ll solve(void)
{
    ll ret = 0;
    string digit = "1";
    for(int i = 1; i < 100; i++) {
        int carry = 0;
        for(int j = 0; j < digit.length(); j++) {
            int t = (digit[j] - '0') * i;
            if(carry) t += carry; 
            digit[j] = t % 10 + '0';
            carry = t / 10; 
        }
        while(carry) {
            digit += (carry%10)+'0';
            carry /= 10;
        }
    }
    //reverse(digit.begin(), digit.end());
    //cout << digit << endl;
    for(int i = 0; i < digit.length(); i++)
        ret += digit[i] - '0';
    return ret;
}

int main()
{
    cout << solve() << endl;    
    return 0;
}

