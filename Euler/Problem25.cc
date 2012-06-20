#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;
map<int, string>dict;

string add(string a, string b)
{
    int ret = 0;
    int carry = 0;

    if(a.length() < b.length()) a.swap(b);
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a.length() != b.length()) {
        for(int i = 0; i < a.length() - b.length(); i++)
            b += "0";
    }
    for(int j = 0; j < a.length(); j++) {
        ll t = (a[j] - '0') + (b[j] - '0');
        if(carry) t += carry; 
        a[j] = t % 10 + '0';
        carry = t / 10;
    }
    while(carry) {
         a += (carry%10)+'0';
         carry /= 10;
    }
    reverse(a.begin(), a.end());
    return a;
}

string fib(int n)
{
    if(n == 0) return "0";
    if(n == 1) return "1";
    if(dict[n] != "") return dict[n];
    dict[n] = add(fib(n-1), fib(n-2));
    return dict[n];
}

/*
int fib(int n)
{
    int a, b, c;
    a = 0, b = 1;
    for(int i = 0; i < n; i++) {
        c = a+b;
        b = a;
        a = c; 
    }
    return c;
}*/

int main()
{
    int i = 0;
    while(true) {
        string s = fib(i);
        if(s.length() >= 1000) { cout << i << endl; break; }
        i++;
    }
    return 0;
}

