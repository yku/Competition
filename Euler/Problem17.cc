#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int countLetter(int n)
{
    int ret = 0;
    string n1[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string n2[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string n3[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string h = "hundred";
    
    if(n <= 0 || 1001 <= n) { exit(1); return -1; }
    if(n == 1000) { string t = "onethousand"; return t.length(); }
    if(1 <= n && n <= 9) { return n1[n].length(); }
    if(10 <= n && n <= 19) { return n2[n-10].length(); }
    string t = "";

    int a = n / 100, r = n % 100;
    if(a) {
        t += n1[a] + h;
        if(!r) { return t.length(); }
        else t += "and";
    } 
    
    
    if(1 <= r && r <= 9) { string tt = t + n1[r]; return tt.length(); }
    if(10 <= r && r <= 19) { string tt = t + n2[r-10]; return tt.length(); }
    int b = r / 10, rr = r % 10;
    t += n3[b] + n1[rr];
    return t.length();
}

int main()
{
    int ans = 0;
    for(int i = 1; i <= 1000; i++) 
        ans += countLetter(i);
    cout << ans << endl;
    return 0;
}

