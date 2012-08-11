#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream> 
#include <map> 
using namespace std;

bool isPandigital(long long n)
{
    map<int, int> dict;
    while(n) {
        if(n % 10) dict[n%10]++;
        n /= 10;
    }
    if(dict.size() == 9) return true;
    return false;
}

int main()
{
    long long ans = 0;
    for(int x = 1; x <= 9999; x++) {
        long long t;
        string s = "";
        for(int n = 1; n <= 9; n++) {
            stringstream ss;
            ss << (x*n);
            s += ss.str();
            if(s.length() > 9) break;
            ss.clear();
            ss.str("");
            ss << s;
            ss >> t;
            //cout << t << endl;
            if(isPandigital(t))
                ans = max(ans, t);
        }
    }
    cout << ans << endl;
}

