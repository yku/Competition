#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

void solve(int h, int m, int s)
{
    int rest_sec = 120*60 - (h*60*60+m*60+s);
    int rest_sec2 = rest_sec * 3;

    int hour = rest_sec / 3600;
    rest_sec %= 3600;
    int minutes = rest_sec / 60;
    rest_sec %= 60;
    int second = rest_sec;
    printf("%02d:%02d:%02d\n", hour, minutes, second);
    
    hour = rest_sec2 / 3600;
    rest_sec2 %= 3600;
    minutes = rest_sec2 / 60;
    rest_sec2 %= 60;
    second = rest_sec2;
    printf("%02d:%02d:%02d\n", hour, minutes, second);
}

int main()
{
    int h, m, s;
    while(cin >> h >> m >> s) {
        if(h == -1 and m == -1 and s == -1) break;
        solve(h, m, s);
    }
    return 0;
}

