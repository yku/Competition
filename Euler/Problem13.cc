#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

string solve(vector<string> v)
{
    vector<char> digit;
    string ret;
    for(int i = 0; i < v.size(); i++) {
        string s = v[i];
        reverse(s.begin(), s.end());
        bool carry = false;
        
        for(int j = 0; j < s.length(); j++) {
            int t = s[j] - '0';
            
            if(digit.size() > j) {
                t += digit[j] - '0';
                t += carry ? 1 : 0;
                carry = false;
                if(t >= 10) carry = true;
                digit[j] = (t%10) + '0';
            }
            else digit.push_back(t+'0');
            
        }
        for(int j = s.length(); carry; j++) {
            int t;
            
            if(carry) {
                if(digit.size() > j) {
                    t = (digit[j]-'0') + 1;
                }else{
                    digit.push_back('0'); // 新しい桁を追加
                    t = 1;
                }
                carry = false;
            }
            if(t >= 10) carry = true;
            digit[j] = (t%10) + '0';
        }
    }
    for(int i = 0; i < digit.size(); i++)
        ret += digit[i];
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    string s;
    vector<string> v;
    while(cin >> s) {
        v.push_back(s); 
    }
    cout <<  solve(v) << endl;
    return 0;
}

